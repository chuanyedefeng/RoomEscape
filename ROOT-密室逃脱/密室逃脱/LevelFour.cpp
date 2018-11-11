#include "LevelFour.h"


CLevelFour::CLevelFour(void)
{
	m_Flag = 4;             // 每一关的标志     m_flag = -m_flag  通过当前关      m_flag = n  进入第n关
	m_bmpBack = NULL;		   // 哪一关的背景图
	m_pClue = new CLevel4_Clue;
	m_ptip->m_tipflag = 4;
}


CLevelFour::~CLevelFour(void)
{
	DeleteObject(m_bmpBack);
	m_bmpBack = NULL;

	delete m_pClue;
	m_pClue = NULL;
}

void CLevelFour::LevelBackInit(HINSTANCE hIns)
{
	m_ptip->TipInit(hIns);
	m_bmpBack = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level4_BACK));
}
void CLevelFour::LevelBackShow(HDC hMemDC) 
{
	HDC hTempDC = CreateCompatibleDC(hMemDC);
	if(m_pClue->m_flag == 0)
		SelectObject(hTempDC,m_bmpBack);
		BitBlt(hMemDC,0,0,1000,562,hTempDC,0,0,SRCCOPY);
	DeleteDC(hTempDC);
}

void CLevelFour::LevelClueInit(HINSTANCE hIns)
{
	m_pClue->ClueInit(hIns);
}
void CLevelFour::LevelClueShow(HDC hMemDC)
{
	m_pClue->ClueShow(hMemDC);
}
void CLevelFour::LevelLButtonUp(POINT point)
{
	if(m_pClue-> m_flag == 1 && point.x >= 437 && point.x <= 477 && point.y > 297 && point.y < 326)
	{
		m_pClue-> m_flag = 2;
	}
	if(m_pClue-> m_flag == 3 && point.x >= 97&& point.x <= 183 && point.y > 323 && point.y < 334)
	{
		m_pClue-> m_flag = 4;
	}
}
void CLevelFour::LevelRun(POINT point)     //每关开始运行
{
	for(int i = 0;i < 8;i++)
	{
		if(m_pClue-> m_flag == 2 && point.x >= 252 + i*68 
			&& point.x <= 252 + (1+i)*68 && point.y > 250 && point.y < 315)
		{
			m_pClue->arrBrightDark[i]=-m_pClue->arrBrightDark[i];
			if(IsOK()== true )
			{
				m_Flag = -m_Flag;
				m_pClue-> m_flag = 5;
			}
		}
	}
	if(m_pClue-> m_flag == 0 && point.x >= 904&& point.x <= 960 && point.y > 17 && point.y < 90)
	{
		if(m_tipflag || m_ptip->TipState())
		{
			m_pClue-> m_flag = LEVEL_TIP;
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
	if(m_pClue-> m_flag == LEVEL_TIP && point.x >= 904&& point.x <= 960 && point.y > 17 && point.y < 90)
	{
		m_pClue-> m_flag = 0;
		return ;
	}
	if(m_pClue-> m_flag == 0 && point.x >= 97&& point.x <= 183 && point.y > 323 && point.y < 334)
		m_pClue-> m_flag = 3;// 4 进入墙上的线索图

	if(m_pClue-> m_flag == 4 && point.x >= 879 && point.x <= 924 && point.y > 434 && point.y < 495)
		m_pClue-> m_flag = 0; //退出墙上的线索图

	if( m_pClue->m_flag == 0 && point.x >= 437 && point.x <= 477 && point.y > 297 && point.y < 326 )
		m_pClue->m_flag = 1;

	if(m_pClue-> m_flag == 2 && point.x >= 903&& point.x <= 944 && point.y > 257 && point.y < 316)
		m_pClue-> m_flag = 0;


}
bool CLevelFour::IsOK()
{
	int num=0;
	if(m_pClue->arrBrightDark[0]==-1)
		num++;
	if(m_pClue->arrBrightDark[1]==-1)
		num++;
	if(m_pClue->arrBrightDark[2]==-1)
		num++;
	if(m_pClue->arrBrightDark[3]==1)
		num++;
	if(m_pClue->arrBrightDark[4]==1)
		num++;
	if(m_pClue->arrBrightDark[5]==1)
		num++;
	if(m_pClue->arrBrightDark[6]==-1)
		num++;
	if(m_pClue->arrBrightDark[7]==-1)
		num++;
	if(num==8)
		return true;
	else
		return false;
}
void CLevelFour::LevelDraw(HDC hMemDC)   //每关的重绘
{
	if(m_pClue-> m_flag == LEVEL_TIP)
	{
		m_ptip->TipShow(hMemDC);
	}
	else
	{
		this->LevelBackShow(hMemDC);
		this->LevelClueShow(hMemDC);
	}
}

void CLevelFour::LevelReset()
{
	m_tipflag = false;
	m_Flag = 4;
	for(int i = 0;i < 8;i++)
	{
		m_pClue->arrBrightDark[i] = 1;
	}
	m_pClue->m_flag = 0;
}
