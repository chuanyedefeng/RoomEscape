#include "LevelSecond.h"


CLevelSecond::CLevelSecond(void)
{

	m_Flag = 2;
	m_secondflag = 0;    // 0 进入第二关,  1 点击到门上线索，2//线索就绪 3//线索解决  4//Clue图退出，过关
	m_clueflag = 0;
	
	m_Clue_B = NULL;
	m_Clue_W = NULL;

	m_cluepoint.x = 200;
	m_cluepoint.y = 562;

	int arrTemp[][5] = {{8,9,7,2,1},{5,10,6,3,4},{13,15,17,16,14},{12,11,18,20,19}};
	for(int i = 0;i < 4;i++)
	{
		for(int j = 0;j < 5;j++)
		{
			m_arrClue[i][j] = arrTemp[i][j];
		}
	}

	//------------初始化位图句柄------------------------------------------------------------
	for(int i = 0 ;i < 4;i++)
	{
		for(int j = 0;j < 5;j++)
		{
			 m_hLight[i][j] = NULL;
		}
	}
	m_bmpBack = NULL;
	//------------初始化位图句柄------------------------------------------------------------

	m_ptip->m_tipflag = 2;		
}


CLevelSecond::~CLevelSecond(void)
{
	//--------------删除位图------------------------------------------------------
	for(int i = 0 ;i < 4;i++)
	{
		for(int j = 0;j < 5;j++)
		{

			if(m_hLight[i][j] != NULL)
			{
				DeleteObject(m_hLight[i][j]);
				m_hLight[i][j] = NULL;
			}
		}
	}
	DeleteObject(m_bmpBack);
	m_bmpBack = NULL;
	
	DeleteObject(m_Clue_B);
	m_Clue_B = NULL;

	DeleteObject(m_Clue_W);
	m_Clue_W = NULL;
	//------------------------删除位图-------------------------------------------------
	
}

void CLevelSecond::LevelBackInit(HINSTANCE hIns) 
{
	m_bmpBack = ::LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level2_Back));
	m_ptip->TipInit(hIns);
}
void CLevelSecond::LevelBackShow(HDC hMemDC)
{
	HDC hTempDC = CreateCompatibleDC(hMemDC);
	
	//----------------贴背景---------------------------------------------------------
	SelectObject(hTempDC,m_bmpBack);
	BitBlt(hMemDC,0,0,1000,562,hTempDC,0,0,SRCCOPY);
	//----------------贴背景----------------------------------------------------------

	DeleteDC(hTempDC);
}

void CLevelSecond::LevelClueInit(HINSTANCE hIns)
{
	//-----------------------------加载  线索  位图*----------------------------------------
	for(int i = 0 ;i < 4;i++)
	{
		for(int j = 0;j < 5;j++)
		{
			 m_hLight[i][j] = ::LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level2_0_0 +5* i + j));
		}
	}

	m_Clue_B = ::LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level2_Clue_B));
	m_Clue_W = ::LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level2_Clue_W));
	//-----------------------------加载   线索   位图*----------------------------------------
}
void CLevelSecond::LevelClueShow(HDC hMemDC)
{
	if(m_secondflag != 0)
	{
		HDC hTempDC = CreateCompatibleDC(hMemDC);
		SelectObject(hTempDC,m_Clue_W);
		BitBlt(hMemDC,m_cluepoint.x,m_cluepoint.y,585,500,hTempDC,0,0,SRCAND);
		SelectObject(hTempDC,m_Clue_B);
		BitBlt(hMemDC,m_cluepoint.x,m_cluepoint.y,585,500,hTempDC,0,0,SRCPAINT);
	

		for(int i = 0;i < 4;i++)
		{
			for(int j = 0;j < 5;j++)
			{
				if(m_clueflag == 20)
				{
					SelectObject(hTempDC,m_Clue_W);
					BitBlt(hMemDC,m_cluepoint.x,m_cluepoint.y,585,500,hTempDC,0,0,SRCAND);
					SelectObject(hTempDC,m_Clue_B);
					BitBlt(hMemDC,m_cluepoint.x,m_cluepoint.y,585,500,hTempDC,0,0,SRCPAINT);
				}
				
				else 
				{
					for(int tempflag = 1;tempflag <= m_clueflag;tempflag ++)
					{
						if(tempflag == m_arrClue[i][j] )
						{
							SelectObject(hTempDC,m_hLight[i][j]);
							BitBlt(hMemDC,220 + 108 * j, 60 + 110 * i,108,110,hTempDC,0,0,SRCCOPY );
						}
					}
				}
			}
		}
		DeleteDC(hTempDC);
	}
}

void CLevelSecond::LevelRun(POINT point)    //每关开始运行
{
	bool EnterFlag = false;
	if(m_secondflag == 0 && point.x >= 440 && point.x <= 480 &&point.y >= 289 && point.y <= 332 )
	{
		m_secondflag = 1; 
	}
	if(m_secondflag <= 2 && point.x >= 896 && point.x <= 961 &&point.y >= 8 && point.y <= 86)
	{
		m_levelTemp = m_secondflag;
		if(m_tipflag || m_ptip->TipState())
		{
			m_secondflag = LEVEL_TIP;
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
	if(m_secondflag == LEVEL_TIP && point.x >= 888 && point.x <= 987 &&point.y >= 2 && point.y <= 72)
	{
		m_secondflag = m_levelTemp;
		return ;
	}
	if(m_secondflag == 2)
	{
		//开始解线索
		for(int i = 0;i < 4;i++)
		{
			for(int j = 0;j < 5;j++)
			{
				if(point.x >= 220 + 108 * j && point.x <= 220 + 108*(j+1) &&
					point.y >= 61 + 110 * i && point.y <= 61 + 110*(i+1) )
				{


					if(m_clueflag +1 == m_arrClue[i][j])
					{

						m_clueflag++;
						EnterFlag = true;
						if(m_clueflag == 20)
						{
							m_secondflag = 3;  //此时解决线索
						}
						break;
					}
					else
					{
						EnterFlag = true;
						m_clueflag = 0;
						break;
					}
				}
			}
			////没有连续点击  或   解决线索
			if(EnterFlag == true/* && m_clueflag == 0 || m_clueflag == 20*/)	
			{
				EnterFlag = false;
				break;
			}
		}
		
	}
	
}
void CLevelSecond::LevelDraw(HDC hMemDC)   //每关的重绘
{
	

	if(m_secondflag == LEVEL_TIP)
	{
		m_ptip->TipShow(hMemDC);
	}
	else
	{
		LevelBackShow(hMemDC);
		LevelClueShow(hMemDC);
	}
	
}

void CLevelSecond:: LevelClueMove()
{
	if(m_secondflag == 1) //点击门上线索
	{
		m_cluepoint.y -= 9;

		if(m_cluepoint.y == 31)
			m_secondflag = 2;	//线索就绪
	}
	if(m_secondflag == 3)  //线索解决
	{
		m_cluepoint.y += 9;
		if(m_cluepoint.y == 562)
		{
			m_Flag = -m_Flag;	//Clue图退出，过关
		}
	}
}

void CLevelSecond::LevelReset()
{
	m_tipflag = false;
	m_Flag = 2;
	m_secondflag = 0;    // 0 进入第二关,  1 点击到门上线索，2//线索就绪 3//线索解决  4//Clue图退出，过关
	m_clueflag = 0;
	m_cluepoint.x = 200;
	m_cluepoint.y = 562;
}

