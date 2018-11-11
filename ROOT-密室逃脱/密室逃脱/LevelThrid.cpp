#include "LevelThrid.h"


CLevelThrid::CLevelThrid(void)
{
	m_bmpBack = 0;
	m_Flag = 3;
	m_ClueBack = 0;
	m_clueFlag = 0;		//标记钩子是否使用
	m_returnflag = false;
	m_ThirdFlag = 0;   //m_ThirdFlag = 3拿起钩子  并且   点击钥匙 孔   ,2 拿到钥匙和钩子，   4进入锁中，
	m_KeyFlag = 0;
	m_HookFlag = 0;
	m_pClue_Hook = new CLevel3_Hook;
	m_pClue_Key = new CLevel3_Key;

	for(int i = 0; i < 3;i++)
	{
		m_hGun[i] = 0;
	}

	for(int i =0;i < 5;i++)
	{
		m_keyarr[i] = 0;
	}
	m_ptip->m_tipflag = 3;
}


CLevelThrid::~CLevelThrid(void)
{
	DeleteObject(m_bmpBack);
	m_bmpBack =	NULL;
	DeleteObject(m_ClueBack);
	m_ClueBack =	NULL;

	delete m_pClue_Hook;
	m_pClue_Hook = nullptr;
	delete m_pClue_Key;
	m_pClue_Key = nullptr;
	
	for(int i = 0; i < 3;i++)
	{
		DeleteObject(m_hGun[i]);
		m_hGun[i] = NULL;
	}
}

void CLevelThrid::LevelBackInit(HINSTANCE hIns)
{
	m_bmpBack = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level3_Back));
	m_ptip->TipInit(hIns);
}
void CLevelThrid::LevelBackShow(HDC hMemDC)
{
	
	if(m_ThirdFlag == LEVEL_TIP)
	{
		m_ptip->TipShow(hMemDC);
	}
	else
	{
		HDC hTempDC = CreateCompatibleDC(hMemDC);
		SelectObject(hTempDC,m_bmpBack);
		BitBlt(hMemDC,0,0,1000,562,hTempDC,0,0,SRCCOPY);
		DeleteDC(hTempDC);
	}
}
void CLevelThrid::LevelClueInit(HINSTANCE hIns)
{
	m_pClue_Key->ClueInit(hIns);
	m_pClue_Hook->ClueInit(hIns);
	
	for(int i = 0; i < 3;i++)
	{
		m_hGun[i] = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level3_GunBig + i));
	}
	m_ClueBack = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level3_Clue));

}
void CLevelThrid::LevelClueShow(HDC hMemDC) 
{
	HDC hTempDC = CreateCompatibleDC(hMemDC);
	if(m_ThirdFlag != LEVEL_TIP)
	{
		if(m_HookFlag != 2 && m_HookFlag != 3  )  //显示钥匙和钩子
			m_pClue_Hook->ClueShow(hMemDC);
		if(m_KeyFlag != 2 && m_KeyFlag != 3  )  //显示钥匙和钩子
			m_pClue_Key->ClueShow(hMemDC);
	}
	if((m_clueFlag == 3 || m_ThirdFlag == 3) && (m_returnflag == true))
	{
		SelectObject(hTempDC,m_ClueBack);
		BitBlt(hMemDC,0,0,1000,562,hTempDC,0,0,SRCCOPY);
		for(int i = 0;i < 5;i++)
		{
			switch (m_keyarr[i])
			{
			case 0:
				{
					SelectObject(hTempDC,m_hGun[0]);
					BitBlt(hMemDC,220+123*i,193,60,289,hTempDC,0,0,SRCCOPY);
				}
				break;
			case 1:
				{
					SelectObject(hTempDC,m_hGun[1]);
					BitBlt(hMemDC,220+123*i,250,60,232,hTempDC,0,0,SRCCOPY);
				}
				break;
			case 2:
				{
					SelectObject(hTempDC,m_hGun[2]);
					BitBlt(hMemDC,220+123*i,324,60,158,hTempDC,0,0,SRCCOPY);
				}
				break;
			}
		}
	}
	
	DeleteDC(hTempDC);
}

//m_KeyFlag = 0 初始化，1 获得钥匙  2 钥匙移动到工具箱
//m_ThirdFlag =  0 初始画， LEVEL_TIP 点击提示 ，3在工具箱中拿起钩子   拿起钩子或钥匙就++   1,2
//m_clueFlag = 0初始化，1 在工具箱中拿起钩子，2用掉钩子，3 是2 的末态

void CLevelThrid::LevelRun(POINT point)    //每关开始运行
{
	if(m_KeyFlag == 0)
	{
		if(true == m_pClue_Key->IsGetClue(point.x,point.y))
			m_KeyFlag = 1;		//获得钥匙
	}
	if(m_HookFlag == 0)
	{
		if(true == m_pClue_Hook->IsGetClue(point.x,point.y))
			m_HookFlag = 1;        //获得钩子
	}

	if( m_clueFlag == 3 || m_ThirdFlag == 3)     //透钥匙
	{
		for(int i = 0;i <5;i++)
		{
		
			switch (m_keyarr[i])     //点击钥匙孔必须在其范围内
			{
			case 0:  //长
				{
					if(point.x >= 220 + 123*i && point.x <= 220 + 123*i + 60
					&&point.y >= 193 && point.y <= 482)
					{
						m_keyarr[i] ++ ;
						if(m_keyarr[i] > 2)
							m_keyarr[i] = 0;
					}
				}
				break;
			case 1:		//中
				{
					if(point.x >= 220 + 123*i && point.x <= 220 + 123*i + 60
					&&point.y >= 250 && point.y <= 482)
					{
						m_keyarr[i] ++;
						if(m_keyarr[i] > 2)
							m_keyarr[i] = 0;
					}
				}
				break;
			case 2:		//短
				{
					if(point.x >= 220 + 123*i && point.x <= 220 + 123*i + 60
					&&point.y >= 324 && point.y <= 482)
					{
						m_keyarr[i] ++ ;
						if(m_keyarr[i] > 2)
							m_keyarr[i] = 0;
					}
				}
				break;
			}
		}


		//校验是否钥匙孔对
		int bFlag = 0;
		int Tempkeyarr[5] = {2,1,0,1,0};
		for(int i = 0;i < 5;i++)
		{
			if(Tempkeyarr[i] == m_keyarr[i])
				bFlag ++;
			if(bFlag == 5)
			{
				m_Flag = -m_Flag;
				m_ThirdFlag = 4;
				m_clueFlag = 4;
				return ;
			}
		}
		bFlag = 0;
		//校验是否钥匙孔对
	}

	if( m_ThirdFlag == 3 && point.x >= 440 && point.x <= 467&& point.y >= 294 && point.y <= 321)
	{
		if(m_clueFlag == 1)
			m_clueFlag = 2; //将钩子用出
	}
	
	if( ((m_ThirdFlag <= 4 )|| (m_ThirdFlag == LEVEL3_GET_KEY ) )
		&& point.x >= 904 && point.x <= 960 && point.y >= 17 && point.y <= 90)
	{						 
		m_levelTemp = m_ThirdFlag;
		if(m_tipflag || m_ptip->TipState())
		{
			m_ThirdFlag = LEVEL_TIP;
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

	if( m_ThirdFlag == LEVEL_TIP && point.x >= 888 && point.x <= 987 && point.y >= 2 && point.y <= 72)
	{
		m_ThirdFlag = m_levelTemp;
		return ;
	}

	if((m_clueFlag == 3 || m_ThirdFlag == 3) && m_returnflag == true)
	{
		if(point.x >= 897 && point.x <= 943 && point.y >= 265 && point.y <= 329)
		{
			m_returnflag = false;
		}
	}
	
	if(	(m_clueFlag == 3 || m_ThirdFlag == 3)  && point.x >= 440
		&& point.x <= 467&& point.y >= 294 && point.y <= 321)		//点击门上的钥匙孔
	{
		m_returnflag = true;
		return ;
	}
}

void CLevelThrid::LevelDraw(HDC hMemDC)   //每关的重绘
{
	this->LevelBackShow(hMemDC);
	this->LevelClueShow(hMemDC);
}

void CLevelThrid::LevelReset()
{
	m_tipflag = false;
	m_Flag = 3;
	m_pClue_Hook->ClueReset();
	m_pClue_Key->ClueReset();

	m_ThirdFlag = 0;  //m_ThirdFlag = 3点击拿起钩子按钮，2 点击钥匙，1 点击钩子，4进入锁中，
	m_KeyFlag = 0;
	m_HookFlag = 0;
	m_clueFlag = 0;
	for(int i =0;i < 5;i++)
	{
		m_keyarr[i] = 0;
	}
}

void CLevelThrid::LevelClueMove()
{
	if(m_KeyFlag == 1)
	{
		m_pClue_Key->ClueMove();
		if(m_pClue_Key->clue_point.x == 30)
		{
			m_ThirdFlag ++;
			m_KeyFlag = 2;
		}
	}

	if(m_HookFlag == 1)
	{
		m_pClue_Hook->ClueMove();
		if(m_pClue_Hook->clue_point.x == 30)
		{
			m_ThirdFlag ++;
			m_HookFlag = 2;
		}
	}
}

