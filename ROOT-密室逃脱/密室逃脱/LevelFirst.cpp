#include "LevelFirst.h"


CLevelFirst::CLevelFirst(void)
{
	m_Flag = 1;             // ��һ�صı�־
	m_bmpBack = 0 ;     // ��һ�صı���ͼ
	first_flag =  0;			//��һ�������ı�־
	for(size_t i = 0;i<5;i++)
	{
		first_code[i] = 0;
	}
	m_ptip->m_tipflag = 1;
}


CLevelFirst::~CLevelFirst(void)
{
}

void CLevelFirst::LevelBackInit(HINSTANCE hIns)       //��һ�ر�����ʼ��
{
	m_bmpBack = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_LEVEL1_BACK));
	m_ptip->TipInit(hIns);		//ֻ����һ��
}


void CLevelFirst::LevelBackShow(HDC hMemDC)        //��һ�ر�����ʾ
{
	HDC hTempDC = CreateCompatibleDC(hMemDC);
	SelectObject(hTempDC,m_bmpBack);
	BitBlt(hMemDC,0,0,1000,563,hTempDC,0,0,SRCCOPY);
	DeleteDC(hTempDC);
}


void CLevelFirst::LevelClueInit(HINSTANCE hIns)         //��һ�صĳ�ʼ��
{
	                  
	//������������è�������Ķ���
	CClue* cateye = new CCatEye;
	CClue* codeslock= new CCodesLock;		 // m_clue��һ��װ����   ������
	
	//������è��װ������������
	m_clue.push_back(cateye);       
	m_clue.push_back(codeslock);         

	//������ʼ��
	list<CClue*>::iterator ite = m_clue.begin();
	while(ite != m_clue.end())
	{
		(*ite)->ClueInit(hIns);    
		ite++;
	}
}
void CLevelFirst::LevelClueShow(HDC hMemDC)         //��һ�ص�������ʾ
{
	HDC hTempDC = CreateCompatibleDC(hMemDC);
	list<CClue*>::iterator ite = m_clue.begin();      // ����������
	while(ite != m_clue.end())
	{
		(*ite)->ClueShow(hTempDC);
		BitBlt(hMemDC,0,0,1000,563,hTempDC,0,0,SRCCOPY);
		ite++;
	}
	DeleteDC(hTempDC);
}

void CLevelFirst::LevelRun(POINT point) 
{

	if(first_flag == 2)		//��ʾ������
	{
		if(point.x >= 219 && point.x <= 219 + 99 
			&& point.y >= 224 && point.y<= 224 + 126 )
			{
				first_code[0]++;               //�㵽��1������

				if(first_code[0] > 9)        
					first_code[0] = 0;
				              
			}            

		if( point.x >= 219 + 128  && point.x <= 219 + 99  +128
			&& point.y >= 224 && point.y<= 224 + 126 )

			{
				first_code[1]++;                     //�㵽��2������

				if(first_code[1] > 9)
					first_code[1] = 0;
				
			}            

		if( point.x >= 219 + 2*128 && point.x <= 219 + 99  + 2*128
			&& point.y >= 224 && point.y<= 224 + 126 )

			{
				first_code[2]++;                     //�㵽��3������

				if(first_code[2] > 9)
					first_code[2] = 0;
				
			}            

		if( point.x >= 219 + 3*128  && point.x <= 219 + 99  + 3*128 
			&& point.y >= 224 && point.y<= 224 + 126 )
			{
				first_code[3]++;                     //�㵽��4������

				if(first_code[3] > 9)
					first_code[3] = 0;
			}            


		if( point.x >= 219 + 4*128 && point.x <= 219 + 99 + 4*128
			&& point.y >= 224 && point.y<= 224 + 126 )
		{
			first_code[4]++;                  //�㵽��5������
			
			if(first_code[4] > 9)
				first_code[4] = 0;
		}

	    if(first_code[0] == 7 && first_code[1] == 9
			 &&first_code[2] == 3 && first_code[3] == 5  && first_code[4] == 1)
		{
		    m_Flag = -m_Flag;                    //ͨ������
			first_flag = 3;
			return;
		}

		 	//�ж��Ƿ�ص�������
		if(point.x >= 895 && point.x <= 929 
			&&point.y >= 447 && point.y <= 498)
		{
			this->Return();               //�ص�������
		}
	}

	if(first_flag == 0 && point.x >= 439 && point.x <= 488 
		&& point.y >= 328 && point.y <= 350)
	{
		first_flag = 2;     //��ʱ�����������      
	}

	if( first_flag  == 1 &&point.x >= 881 && point.x <= 917 
		&& point.y>= 236 && point.y <= 288 )
	{
	    this->Return();          
	}

	if(first_flag == LEVEL_TIP && point.x >= 888 && point.x <= 987 
		&& point.y >= 2 && point.y <= 72)
	{
		first_flag = 0;
		return ;
	}

	if(first_flag == 0 && point.x >= 901 && point.x <= 967 
		&& point.y >= 8 && point.y <= 84)
	{
		if(m_tipflag || m_ptip->TipState())
		{
			first_flag = LEVEL_TIP;
			m_tipflag = true;
		}
		else
		{
			char str[100] = {0};
			sprintf(str,"����ʣ��%d�Ŷ������ܿ�����ʾ~",m_ptip->GetTipcount());
			MessageBox(NULL,str,"��ܰ��ʾ",MB_OK);
		}
		return ;
	}

	if(first_flag == 0 && point.x >= 513 && point.x <= 527 && point.y>= 182 && point.y <= 196)
	{
        first_flag  = 1;                     //�ж��Ƿ�㵽��è��
	}

}

void CLevelFirst::LevelDraw(HDC hMemDC)
{
	
	this->LevelBackShow(hMemDC);
	list<CClue*>::iterator ite = m_clue.begin();
	if(first_flag == 1)                   //��ʾè��
	{
		(*ite)->ClueShow (hMemDC);
	}
	++ite;
	if(first_flag == 2 )    //��ʱ�����������Ľ�������
	{
		((CCodesLock*)(*ite))->ClueShow(hMemDC,first_code);           //��ʾ����������
	}
	if(first_flag == LEVEL_TIP)
	{
		m_ptip->TipShow(hMemDC);
	}
}

void CLevelFirst::Return()
{
	first_flag = 0;                               //����������
}

 void CLevelFirst::LevelReset()
 {
	m_tipflag = false;
	m_Flag = 1;
	for(size_t i = 0;i<5;i++)
	{
		first_code[i] = 0;	//����������Ϊ0
	}
	first_flag =  0;
 }