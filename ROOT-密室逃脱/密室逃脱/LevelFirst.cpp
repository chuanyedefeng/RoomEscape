#include "LevelFirst.h"


CLevelFirst::CLevelFirst(void)
{
	m_Flag = 1;             // 那一关的标志
	m_bmpBack = 0 ;     // 哪一关的背景图
	first_flag =  0;			//哪一个线索的标志
	for(size_t i = 0;i<5;i++)
	{
		first_code[i] = 0;
	}
	m_ptip->m_tipflag = 1;
}


CLevelFirst::~CLevelFirst(void)
{
}

void CLevelFirst::LevelBackInit(HINSTANCE hIns)       //第一关背景初始化
{
	m_bmpBack = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_LEVEL1_BACK));
	m_ptip->TipInit(hIns);		//只加载一次
}


void CLevelFirst::LevelBackShow(HDC hMemDC)        //第一关背景显示
{
	HDC hTempDC = CreateCompatibleDC(hMemDC);
	SelectObject(hTempDC,m_bmpBack);
	BitBlt(hMemDC,0,0,1000,563,hTempDC,0,0,SRCCOPY);
	DeleteDC(hTempDC);
}


void CLevelFirst::LevelClueInit(HINSTANCE hIns)         //第一关的初始化
{
	                  
	//创建密码锁和猫眼线索的对象
	CClue* cateye = new CCatEye;
	CClue* codeslock= new CCodesLock;		 // m_clue第一个装的是   密码锁
	
	//将锁，猫眼装进线索链表中
	m_clue.push_back(cateye);       
	m_clue.push_back(codeslock);         

	//线索初始化
	list<CClue*>::iterator ite = m_clue.begin();
	while(ite != m_clue.end())
	{
		(*ite)->ClueInit(hIns);    
		ite++;
	}
}
void CLevelFirst::LevelClueShow(HDC hMemDC)         //第一关的线索显示
{
	HDC hTempDC = CreateCompatibleDC(hMemDC);
	list<CClue*>::iterator ite = m_clue.begin();      // 线索迭代器
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

	if(first_flag == 2)		//显示密码锁
	{
		if(point.x >= 219 && point.x <= 219 + 99 
			&& point.y >= 224 && point.y<= 224 + 126 )
			{
				first_code[0]++;               //点到第1个密码

				if(first_code[0] > 9)        
					first_code[0] = 0;
				              
			}            

		if( point.x >= 219 + 128  && point.x <= 219 + 99  +128
			&& point.y >= 224 && point.y<= 224 + 126 )

			{
				first_code[1]++;                     //点到第2个密码

				if(first_code[1] > 9)
					first_code[1] = 0;
				
			}            

		if( point.x >= 219 + 2*128 && point.x <= 219 + 99  + 2*128
			&& point.y >= 224 && point.y<= 224 + 126 )

			{
				first_code[2]++;                     //点到第3个密码

				if(first_code[2] > 9)
					first_code[2] = 0;
				
			}            

		if( point.x >= 219 + 3*128  && point.x <= 219 + 99  + 3*128 
			&& point.y >= 224 && point.y<= 224 + 126 )
			{
				first_code[3]++;                     //点到第4个密码

				if(first_code[3] > 9)
					first_code[3] = 0;
			}            


		if( point.x >= 219 + 4*128 && point.x <= 219 + 99 + 4*128
			&& point.y >= 224 && point.y<= 224 + 126 )
		{
			first_code[4]++;                  //点到第5个密码
			
			if(first_code[4] > 9)
				first_code[4] = 0;
		}

	    if(first_code[0] == 7 && first_code[1] == 9
			 &&first_code[2] == 3 && first_code[3] == 5  && first_code[4] == 1)
		{
		    m_Flag = -m_Flag;                    //通过本关
			first_flag = 3;
			return;
		}

		 	//判断是否回到主界面
		if(point.x >= 895 && point.x <= 929 
			&&point.y >= 447 && point.y <= 498)
		{
			this->Return();               //回到主界面
		}
	}

	if(first_flag == 0 && point.x >= 439 && point.x <= 488 
		&& point.y >= 328 && point.y <= 350)
	{
		first_flag = 2;     //此时点击到密码锁      
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
			sprintf(str,"您还剩余%d颗豆，不能开启提示~",m_ptip->GetTipcount());
			MessageBox(NULL,str,"温馨提示",MB_OK);
		}
		return ;
	}

	if(first_flag == 0 && point.x >= 513 && point.x <= 527 && point.y>= 182 && point.y <= 196)
	{
        first_flag  = 1;                     //判断是否点到了猫眼
	}

}

void CLevelFirst::LevelDraw(HDC hMemDC)
{
	
	this->LevelBackShow(hMemDC);
	list<CClue*>::iterator ite = m_clue.begin();
	if(first_flag == 1)                   //显示猫眼
	{
		(*ite)->ClueShow (hMemDC);
	}
	++ite;
	if(first_flag == 2 )    //此时进入密码锁的解锁界面
	{
		((CCodesLock*)(*ite))->ClueShow(hMemDC,first_code);           //显示密码锁背景
	}
	if(first_flag == LEVEL_TIP)
	{
		m_ptip->TipShow(hMemDC);
	}
}

void CLevelFirst::Return()
{
	first_flag = 0;                               //返回主界面
}

 void CLevelFirst::LevelReset()
 {
	m_tipflag = false;
	m_Flag = 1;
	for(size_t i = 0;i<5;i++)
	{
		first_code[i] = 0;	//将密码重置为0
	}
	first_flag =  0;
 }