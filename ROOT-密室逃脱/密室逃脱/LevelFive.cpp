#include "LevelFive.h"


CLevelFive::CLevelFive(void)
{
	m_Flag = 5;             // ÿһ�صı�־     m_flag = -m_flag  ͨ����ǰ��      m_flag = n  �����n��
	m_bmpBack = NULL;     // ��һ�صı���ͼ
	m_clueScreen = new CClue_Screen;
	m_ptip->m_tipflag = 5;
}


CLevelFive::~CLevelFive(void)
{
}

void CLevelFive::LevelBackInit(HINSTANCE hIns)
{
	m_bmpBack =  LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level5_Back));
	m_ptip->TipInit(hIns);
}
void CLevelFive::LevelBackShow(HDC hMemDC) 
{
	HDC hTempDC = CreateCompatibleDC(hMemDC);
	if(m_clueScreen->m_flag == 0)
	{
		SelectObject(hTempDC,m_bmpBack);
		BitBlt(hMemDC,0,0,1000,562,hTempDC,0,0,SRCCOPY);
	}
	if(m_clueScreen->m_flag == 1)
	{
		SelectObject(hTempDC,m_clueScreen->m_hBack1);
		BitBlt(hMemDC,0,0,1000,562,hTempDC,0,0,SRCCOPY);
	}
	if(m_clueScreen->m_flag >= 2)
	{
		SelectObject(hTempDC,m_clueScreen->m_hBack2);
		BitBlt(hMemDC,0,0,1000,562,hTempDC,0,0,SRCCOPY);
	}
	DeleteDC(hTempDC);
}
	
void CLevelFive::LevelClueInit(HINSTANCE hIns)
{
	m_clueScreen->ClueInit(hIns);
}
void CLevelFive::LevelClueShow(HDC hMemDC)
{
	m_clueScreen->ClueShow(hMemDC);
}
	
void CLevelFive::LevelRun(POINT point)    //ÿ�ؿ�ʼ����
{
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		{
			if(m_clueScreen->m_flag == 0 && point.x>644+j*114 && point.x<740+j*114 && point.y>148+i*107 && point.y<244+i*107)
			{
				m_clueScreen->arrIsScreen[i][j]=- m_clueScreen->arrIsScreen[i][j];
			}
		}
	}

	if(m_clueScreen->m_flag == Level5_GET_KEY && point.x>432 && point.x<607 && point.y>124 && point.y<485)
	{
		m_Flag = -m_Flag;  //����
		m_clueScreen->m_flag = 4;
	}

	if(m_clueScreen->m_flag == 1 && point.x>286 && point.x<363 && point.y>189 && point.y<288)
		m_clueScreen->m_flag = 2;	//Կ�׳������ɵ���������

	if(IsOK()==true && m_clueScreen->m_flag  == 0)
		m_clueScreen->m_flag = 1;   //Կ������
	

	if((m_clueScreen->m_flag <= 4|| m_clueScreen->m_flag == Level5_GET_KEY)
		&&  point.x>904 && point.x<960 && point.y>17 && point.y<90)
	{
		m_levelTemp	= m_clueScreen->m_flag ;

		if(m_tipflag || m_ptip->TipState())
		{
			m_clueScreen->m_flag = LEVEL_TIP;
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
	if(m_clueScreen->m_flag == LEVEL_TIP &&  point.x>896 && point.x<961 && point.y>8 && point.y<86)
	{
		m_clueScreen->m_flag = m_levelTemp;
		return;
	}

}

bool CLevelFive::IsOK()   //��Ļȫ��
{
	int num=0;
	if(m_clueScreen->arrIsScreen[0][0]==1)
		num++;
	if(m_clueScreen->arrIsScreen[0][1]==-1)
		num++;
	if(m_clueScreen->arrIsScreen[0][2]==1)
		num++;
	if(m_clueScreen->arrIsScreen[1][0]==-1)
		num++;
	if(m_clueScreen->arrIsScreen[1][1]==-1)
		num++;
	if(m_clueScreen->arrIsScreen[1][2]==1)
		num++;
	if(m_clueScreen->arrIsScreen[2][0]==-1)
		num++;
	if(m_clueScreen->arrIsScreen[2][1]==1)
		num++;
	if(m_clueScreen->arrIsScreen[2][2]==-1)
		num++;
	if(num==9)
		return true;
	return false;
}
void CLevelFive::LevelDraw(HDC hMemDC)   //ÿ�ص��ػ�
{
	if(m_clueScreen->m_flag == LEVEL_TIP)
	{
		m_ptip->TipShow(hMemDC);
	}
	else
	{
		this->LevelBackShow(hMemDC);
		this->LevelClueShow(hMemDC);
	}
}	
void CLevelFive::LevelLButtonUp(POINT point)
{
	
}
void CLevelFive::LevelReset()
{
	m_tipflag = false;
	m_Flag = 5;  
	m_clueScreen->ClueReset();
}
void CLevelFive::LevelClueMove()
{
	m_clueScreen->ClueMove();
}