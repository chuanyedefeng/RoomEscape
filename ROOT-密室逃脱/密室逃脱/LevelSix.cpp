#include "LevelSix.h"


CLevelSix::CLevelSix(void)
{
	m_Flag = 6;             // 每一关的标志     m_flag = -m_flag  通过当前关      m_flag = n  进入第n关
	m_bmpBack = NULL ;     // 哪一关的背景图
	m_cluepuzzle = new CClue_Puzzle;

	
	m_hBack1 = 0;
	m_hBack2 = 0;
	m_hBack3 = 0;
	m_TempFlag = false;
	
	m_ptip->m_tipflag = 6;
}


CLevelSix::~CLevelSix(void)
{
	if(m_bmpBack)
	{
		DeleteObject(m_bmpBack);
		m_bmpBack = NULL ;
	}
	if(m_cluepuzzle)
	{
		delete m_cluepuzzle;
		m_cluepuzzle = nullptr;
	}
	if(m_hBack3)
	{
		DeleteObject(m_hBack3);
		m_hBack3 = NULL ;
	}
	if(m_hBack2)
	{
		DeleteObject(m_hBack2);
		m_hBack2 = NULL ;
	}
	if(m_hBack1)
	{
		DeleteObject(m_hBack1);
		m_hBack1 = NULL ;
	}
	
}

void CLevelSix::LevelBackInit(HINSTANCE hIns)
{
	m_hBack1 = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level6_Back1));
	m_hBack2 = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level6_Back2));
	m_hBack3 = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level6_back3));
}
void CLevelSix::LevelBackShow(HDC hMemDC)
{
	HDC hTempDC = CreateCompatibleDC(hMemDC);
	if(m_cluepuzzle->m_flag == 0 && m_TempFlag == false  )//m_flag = 0初始状态，1 钥匙取下，2 钥匙到工具箱，3 进入线索
	{
		SelectObject(hTempDC,m_hBack1);
		BitBlt(hMemDC,0,0,1000,562,hTempDC,0,0,SRCCOPY);
	}
	else if( m_cluepuzzle->m_flag != 7 )
	{
		SelectObject(hTempDC,m_hBack2);
		BitBlt(hMemDC,0,0,1000,562,hTempDC,0,0,SRCCOPY);
	}
	if(m_cluepuzzle->m_flag == 7 )	//通关
	{
		SelectObject(hTempDC,m_hBack3);
		BitBlt(hMemDC,0,0,1000,562,hTempDC,0,0,SRCCOPY);
	}

	DeleteDC(hTempDC);
}
void CLevelSix::LevelClueInit(HINSTANCE hIns)
{
	m_cluepuzzle->ClueInit(hIns);
}
void CLevelSix::LevelClueShow(HDC hMemDC)
{
	m_cluepuzzle->ClueShow(hMemDC);
}
void CLevelSix::LevelRun(POINT point)     //每关开始运行
{
	if(m_cluepuzzle->m_flag == 3 && point.x>262 && point.x<262+155 && point.y>76 && point.y<76+155)
	{
		if(m_cluepuzzle->ArrNum[0][1] ==5 )
		{
			m_cluepuzzle->ArrNum[0][1] = m_cluepuzzle->ArrNum[0][0];
			m_cluepuzzle->ArrNum[0][0] = 5;
			//return;
		}
		else if(m_cluepuzzle->ArrNum[1][0] ==5 )
		{
			m_cluepuzzle->ArrNum[1][0] =m_cluepuzzle-> ArrNum[0][0];
			m_cluepuzzle->ArrNum[0][0] = 5;
			//return;
		}
	}
	if(m_cluepuzzle->m_flag == 3 && point.x>262+155 && point.x<262+2*155 && point.y>76 && point.y<76+155)
	{
		if(m_cluepuzzle->ArrNum[0][0] == 5 )
		{
			m_cluepuzzle->ArrNum[0][0] = m_cluepuzzle->ArrNum[0][1];
			m_cluepuzzle->ArrNum[0][1] = 5;
			//return;
		}
		else if(m_cluepuzzle->ArrNum[0][2] == 5 )
		{
			m_cluepuzzle->ArrNum[0][2] = m_cluepuzzle->ArrNum[0][1];
			m_cluepuzzle->ArrNum[0][1] = 5;
			//return;
		}
		else if(m_cluepuzzle->ArrNum[1][1] == 5 )
		{
			m_cluepuzzle->ArrNum[1][1] = m_cluepuzzle->ArrNum[0][1];
			m_cluepuzzle->ArrNum[0][1] = 5;
			//return;
		}
	}
	if(m_cluepuzzle->m_flag == 3 && point.x>262+155*2 && point.x<262+3*155 && point.y>76 && point.y<76+155)
	{
		if(m_cluepuzzle->ArrNum[0][1] == 5 )
		{
			m_cluepuzzle->ArrNum[0][1] = m_cluepuzzle->ArrNum[0][2];
			m_cluepuzzle->ArrNum[0][2] = 5;
			//return;
		}
		else if(m_cluepuzzle->ArrNum[1][2] == 5 )
		{
			m_cluepuzzle->ArrNum[1][2] =m_cluepuzzle-> ArrNum[0][2];
			m_cluepuzzle->ArrNum[0][2] = 5;
			//return;
		}
	}

	if(m_cluepuzzle->m_flag == 3 && point.x>262 && point.x<262+155 && point.y>76+155 && point.y<76+2*155)
	{
		
		if(m_cluepuzzle-> ArrNum[0][0] == 5 )
		{
			m_cluepuzzle->ArrNum[0][0] =m_cluepuzzle-> ArrNum[1][0];
			m_cluepuzzle->ArrNum[1][0] = 5;
			//return;
		}
		else if(m_cluepuzzle->ArrNum[1][1] == 5 )
		{
			m_cluepuzzle->ArrNum[1][1] = m_cluepuzzle->ArrNum[1][0];
			m_cluepuzzle->ArrNum[1][0] = 5;
			//return;
		}
		else if(m_cluepuzzle->ArrNum[2][0] == 5 )
		{
			m_cluepuzzle->ArrNum[2][0] = m_cluepuzzle->ArrNum[1][0];
			m_cluepuzzle->ArrNum[1][0] = 5;
			//return;
		}
	}
	if(m_cluepuzzle->m_flag == 3 && point.x>262+155 && point.x<262+2*155 && point.y>76+155 && point.y<76+2*155)
	{
		if(m_cluepuzzle->ArrNum[0][1] == 5 )
		{
			m_cluepuzzle->ArrNum[0][1] = m_cluepuzzle->ArrNum[1][1];
			m_cluepuzzle->ArrNum[1][1] = 5;
			//return;
		}
		else if(m_cluepuzzle->ArrNum[1][0] == 5 )
		{
			m_cluepuzzle->ArrNum[1][0] = m_cluepuzzle->ArrNum[1][1];
			m_cluepuzzle->ArrNum[1][1] = 5;
			//return;
		}
		else if(m_cluepuzzle->ArrNum[1][2] == 5 )
		{
			m_cluepuzzle->ArrNum[1][2] = m_cluepuzzle->ArrNum[1][1];
			m_cluepuzzle->ArrNum[1][1] = 5;
			//return;
		}
		else if(m_cluepuzzle->ArrNum[2][1] == 5 )
		{
			m_cluepuzzle->ArrNum[2][1] = m_cluepuzzle->ArrNum[1][1];
			m_cluepuzzle->ArrNum[1][1] = 5;
			//return;
		}
	}
	if(m_cluepuzzle->m_flag == 3 && point.x>262+2*155 && point.x<262+3*155 && point.y>76+155 && point.y<76+2*155)
	{
		if(m_cluepuzzle->ArrNum[0][2] == 5 )
		{
			m_cluepuzzle->ArrNum[0][2] =m_cluepuzzle-> ArrNum[1][2];
			m_cluepuzzle->ArrNum[1][2] = 5;
			//return;
		}
		else if(m_cluepuzzle->ArrNum[1][1] == 5 )
		{
			m_cluepuzzle->ArrNum[1][1] = m_cluepuzzle->ArrNum[1][2];
			m_cluepuzzle->ArrNum[1][2] = 5;
			//return;
		}
		else if(m_cluepuzzle->ArrNum[2][2] == 5 )
		{
			m_cluepuzzle->ArrNum[2][2] = m_cluepuzzle->ArrNum[1][2];
			m_cluepuzzle->ArrNum[1][2] = 5;
			//return;
		}
	}

	if(m_cluepuzzle->m_flag == 3 && point.x>262 && point.x<262+155 && point.y>76+2*155 && point.y<76+3*155)
	{
		if(m_cluepuzzle->ArrNum[1][0] == 5 )
		{
			m_cluepuzzle->ArrNum[1][0] = m_cluepuzzle->ArrNum[2][0];
			m_cluepuzzle->ArrNum[2][0] = 5;
			//return;
		}
		else if(m_cluepuzzle->ArrNum[2][1] == 5 )
		{
			m_cluepuzzle->ArrNum[2][1] = m_cluepuzzle->ArrNum[2][0];
			m_cluepuzzle->ArrNum[2][0] = 5;
			//return;
		}
	}
	if(m_cluepuzzle->m_flag == 3 && point.x>262+155 && point.x<262+2*155 && point.y>76+2*155 && point.y<76+3*155)
	{
		
		if(m_cluepuzzle->ArrNum[1][1] == 5 )
		{
			m_cluepuzzle->ArrNum[1][1] = m_cluepuzzle->ArrNum[2][1];
			m_cluepuzzle->ArrNum[2][1] = 5;
			//return;
		}
		else if(m_cluepuzzle->ArrNum[2][0] == 5 )
		{
			m_cluepuzzle->ArrNum[2][0] = m_cluepuzzle->ArrNum[2][1];
			m_cluepuzzle->ArrNum[2][1] = 5;
			//return;
		}
		else if(m_cluepuzzle->ArrNum[2][2] == 5 )
		{
			m_cluepuzzle->ArrNum[2][2] = m_cluepuzzle->ArrNum[2][1];
			m_cluepuzzle->ArrNum[2][1] = 5;
			//return;
		}
	}
	if(m_cluepuzzle->m_flag == 3 && point.x>262+2*155 && point.x<262+3*155 && point.y>76+2*155 && point.y<76+3*155)
	{
		if(m_cluepuzzle->ArrNum[1][2] == 5 )
		{
			m_cluepuzzle->ArrNum[1][2] = m_cluepuzzle->ArrNum[2][2];
			m_cluepuzzle->ArrNum[2][2] = 5;
			//return;
		}
		else if(m_cluepuzzle->ArrNum[2][1] == 5 )
		{
			m_cluepuzzle->ArrNum[2][1] = m_cluepuzzle->ArrNum[2][2];
			m_cluepuzzle->ArrNum[2][2] = 5;
			//return;
		}
	}
	if(m_cluepuzzle->m_flag == 7 && point.x>424 && point.x<601 && point.y>121 && point.y<487)
	{
		m_Flag = - m_Flag;
	}
	if(m_cluepuzzle->m_flag ==6 &&point.x>262+155 && point.x<262+2*155  && point.y>76+155 && point.y<76+2*155)
	{
		m_cluepuzzle->m_flag =7;  //解决此关，显示亮门
	}
	if(m_cluepuzzle->m_flag ==5 && point.x>262+155 && point.x<262+2*155  && point.y>76+155 && point.y<76+2*155)
	{
		m_cluepuzzle->m_flag =6;  //钥匙旋转
	}
	if(m_cluepuzzle->m_flag == 4 && m_cluepuzzle->m_clueflag == true 
		&& point.x>262+155 && point.x<262+2*155 && point.y>76+155 && point.y<76+2*155)
	{
		m_cluepuzzle->m_flag = 5;  //将钥匙插进钥匙孔，前提是拿到钥匙
	}
	if(IsOK()== true && m_cluepuzzle->m_flag  == 3)
		m_cluepuzzle->m_flag = 4;		//全对，出现钥匙孔
	/*if(m_cluepuzzle->m_flag == 3 && point.x > 868 && point.x<918 && point.y>254 && point.y<323)
	{
		m_cluepuzzle->m_flag = ;
	}*/
	if(m_cluepuzzle->m_flag <= 2 && point.x>433 && point.x<493 && point.y>277 && point.y<334)
	{
		m_cluepuzzle->m_flag = 3;
	}
	if(m_TempFlag == false && m_cluepuzzle->m_flag == 0
		&& point.x>731 && point.x<763 && point.y>169 && point.y<215)
	{
		m_cluepuzzle->m_flag = 1;
		m_TempFlag = true;
	}
	if(m_cluepuzzle->m_flag >0 &&m_cluepuzzle->m_flag < 7
		&& point.x>877 && point.x<912 && point.y>261 && point.y<317 )
	{
		m_cluepuzzle->m_flag = 0;
	}
	if(m_cluepuzzle->m_flag == 0 &&  point.x>904 && point.x<961 && point.y>18 && point.y<79)
	{
		MessageBox(NULL,"	The Last Level,\nYou cannot use tip","waring",MB_OK);
	}
}
void CLevelSix::LevelDraw(HDC hMemDC)  //每关的重绘
{
	this->LevelBackShow(hMemDC);
	this->LevelClueShow(hMemDC);
}

bool CLevelSix::IsOK()  //密码全对
{
	int num=0;
	if(m_cluepuzzle->ArrNum[0][0]== 1)
		num++;
	if(m_cluepuzzle->ArrNum[0][1]== 2)
		num++;
	if(m_cluepuzzle->ArrNum[0][2]== 3)
		num++;
	if(m_cluepuzzle->ArrNum[1][0]== 4)
		num++;
	if(m_cluepuzzle->ArrNum[1][1]== 5)
		num++;
	if(m_cluepuzzle->ArrNum[1][2]== 6)
		num++;
	if(m_cluepuzzle->ArrNum[2][0]== 7)
		num++;
	if(m_cluepuzzle->ArrNum[2][1]== 8)
		num++;
	if(m_cluepuzzle->ArrNum[2][2]== 9)
		num++;
	if(num==9)
		return true;
	else
		return false;
}
void CLevelSix::LevelReset()
{
	m_tipflag = false;
	m_Flag = 6;
	m_cluepuzzle->ClueReset();
	m_TempFlag = false;
}
void CLevelSix::Return()
{
	
}
void CLevelSix::LevelClueMove()
{
	m_cluepuzzle->ClueMove();
}