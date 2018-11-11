#include "EscapeRoom.h"
_IMPLEMENT_(CEscapeRoom)   
 

CEscapeRoom::CEscapeRoom(void)
{
	
	m_isvertory = 0;		//0未通关，1通关，2点击end图片
	m_bflagMenutoLevel = true;
	dc = 0;
	hMemDC = 0;
	hBitmap = 0;
	m_hmpend = 0;
	m_level = nullptr;
	CLevel* plevel = new CLevelFirst; 
	m_level = plevel;
	m_lstlevel.push_back(plevel);				//关入队
	plevel = new CLevelSecond;
	m_lstlevel.push_back(plevel);
	plevel = new CLevelThrid;
	m_lstlevel.push_back(plevel);
	plevel = new CLevelFour;
	m_lstlevel.push_back(plevel);
	plevel = new CLevelFive;
	m_lstlevel.push_back(plevel);
	plevel = new CLevelSix;
	m_lstlevel.push_back(plevel);
	
	//读存档
	FILE *pfile;
	struct Save_Game save;
	pfile = fopen("./test.in","rb");
	if(pfile == NULL)
		m_wlevel = 1;                    //初始化是第一关
	else
	{
		fread(&save,sizeof(save),1,pfile);
		m_wlevel = save.m_wlevel;
	}
	if(pfile)
	fclose(pfile);
}


CEscapeRoom::~CEscapeRoom(void)
{
	ReleaseDC(hWnd_Main,dc);
	DeleteDC(hMemDC);
	DeleteObject(hBitmap);
	hBitmap = 0;
	DeleteObject(m_hmpend);
	m_hmpend = 0;

	list<CLevel*>::iterator ite = m_lstlevel.begin();

	while(ite != m_lstlevel.end())
	{
		delete *ite;
		ite = m_lstlevel.erase(ite);
	}

	KillTimer(hWnd_Main,ARROWMOVE);
	KillTimer(hWnd_Main,LEVEL2_CLUE_MOVE);
	KillTimer(hWnd_Main,LEVEL3_KEY_MOVE);
	KillTimer(hWnd_Main,LEVEL3_HOOK_MOVE);
	KillTimer(hWnd_Main,LEVEL6_KEY_MOVE);
	KillTimer(hWnd_Main,LEVEL5_KEY_MOVE);
	KillTimer(hWnd_Main,TOOLBOX_RUN);
}								
										 
void CEscapeRoom::OnCreatGame()			 
{				
	dc = GetDC(hWnd_Main);				 
	hMemDC = CreateCompatibleDC(dc);	 
	hBitmap = CreateCompatibleBitmap(dc,1000,563);
	SelectObject(hMemDC,hBitmap);
	m_hmpend = LoadBitmap(m_hIn,MAKEINTRESOURCE(IDB_END));

	PlaySound("Music.wav",NULL,SND_LOOP|SND_ASYNC);
	list<CLevel*>::iterator ite = m_lstlevel.begin();
	while(ite != m_lstlevel.end())
	{
		(*ite)->LevelBackInit(m_hIn);
		(*ite)->LevelClueInit(m_hIn);
		if((*ite)->m_Flag == m_wlevel)
		{
			m_level = (*ite);
			m_level->m_ptip->SetTipCount(m_menu.m_TipCount);
			m_tool.ChangeLevel(m_level);
		}
		ite++;
	}
	

	m_tool.ToolBoxInit(m_hIn);
	back.BackInit(m_hIn);                //背景初始化
	back.arrow.ArrowInit (m_hIn);    //箭头初始化
	m_menu.MenuInit(m_hIn);
	
	//开定时器
	SetTimer(hWnd_Main,ARROWMOVE,10,NULL);
	SetTimer(hWnd_Main,LEVEL2_CLUE_MOVE,10,NULL);
	SetTimer(hWnd_Main,LEVEL3_KEY_MOVE,100,NULL);
	SetTimer(hWnd_Main,LEVEL3_HOOK_MOVE,100,NULL);
	SetTimer(hWnd_Main,TOOLBOX_RUN,1,NULL);
	SetTimer(hWnd_Main,LEVEL5_KEY_MOVE,100,NULL);
	SetTimer(hWnd_Main,LEVEL6_KEY_MOVE,100,NULL);
	SetTimer(hWnd_Main,MENU_STATE,1,NULL);
	SetTimer(hWnd_Main,MENU_SOUND,111,NULL);
}

void CEscapeRoom::OnGameRun(WPARAM n_TimerID)
{
	//播放音乐
	if(n_TimerID == MENU_SOUND)
	{
		if(m_menu.Getsoundflag() == true)
			PlaySound(m_menu.GetSoundWav(),NULL,SND_LOOP|SND_ASYNC);
		else
			PlaySound(m_menu.GetSoundWav(),NULL,SND_LOOP|SND_ASYNC);
	}
	//-------------关卡变化
	list<CLevel*>::iterator ite = m_lstlevel.begin();
	while(ite != m_lstlevel.end())
	{
		if((*ite)->m_Flag == m_menu.GetLevel())
		{
			m_level = (*ite);
			m_level->m_ptip->SetTipCount(m_menu.m_TipCount);
			m_tool.ChangeLevel(m_level);
		}
		ite++;
	}
	
	if(n_TimerID == MENU_STATE)
	{
		if(m_menu.GetLevel() == m_level->m_Flag&& m_menu.GetLevelState()[m_level->m_Flag-1])
		{
			m_bflagMenutoLevel = false;
		}
	}

	//-------------关卡变化

	if(m_level->m_Flag == 3)
	{
		if(n_TimerID == LEVEL3_KEY_MOVE)
		{
			m_level->LevelClueMove();
			this->OnGameDraw();
		}

		if(n_TimerID == LEVEL3_HOOK_MOVE)
		{
			back.arrow.ArrowMove();
			this->OnGameDraw();
		}
	}
	if(m_level->m_Flag == 5)
	{
		if(n_TimerID == LEVEL5_KEY_MOVE)
			m_level->LevelClueMove();
	}
	if(m_level->m_Flag == 6)
	{
		if(n_TimerID == LEVEL6_KEY_MOVE)
		{
			m_level->LevelClueMove();
		}
	}
	
	if(n_TimerID == TOOLBOX_RUN)
	{
		m_tool.ChangeLevel(m_level);
		m_tool.ToolRun();
	}
	if(n_TimerID == ARROWMOVE)
	{
		back.arrow.ArrowMove();
		this->OnGameDraw();
	}

	if(n_TimerID == LEVEL2_CLUE_MOVE)
		m_level->LevelClueMove();	
}
void CEscapeRoom::OnGameDraw()
{
	HDC TempDC = CreateCompatibleDC(hMemDC);
	HBITMAP hbitmap = CreateCompatibleBitmap(hMemDC,1000,562);
	SelectObject(TempDC,hbitmap);
	if(m_isvertory == 1 || m_isvertory == 2)
	{
		SelectObject(TempDC,m_hmpend);
		BitBlt(hMemDC,0,0,1000,562,TempDC,0,0,SRCCOPY);
	}
	else
	{
		if(m_bflagMenutoLevel == true)
			m_menu.MenuShow(TempDC);
		else if((m_menu.GetLevel() == m_level->m_Flag ||m_menu.GetLevel() == - m_level->m_Flag)
			&&  m_menu.GetLevelState()[m_level->m_Flag -1 ])
		{
			if(m_level->IsPassLevel() == true  )			//通过某一关
			{
				back.LightDoorShow(TempDC,-m_level->m_Flag);
				if(back.doorflag == 1)
				{
					back.OpenDoorShow (TempDC,-m_level->m_Flag);
					back.arrow .ArrowShow (TempDC );
				}
			}
			else
			m_level->LevelDraw(TempDC);
		}

	}
	if(m_bflagMenutoLevel == false && (m_tool.m_ToolEnterFlag == true || false == m_tool.m_ToolQuitFlag))
		m_tool.ToolBoxShow(TempDC);

	BitBlt(hMemDC,0,0,1000,562,TempDC,0,0,SRCCOPY);


	BitBlt(dc,0,0,1000,563,hMemDC,0,0,SRCCOPY);
	DeleteObject(TempDC);
	DeleteObject(hbitmap);
}
void CEscapeRoom::OnLButtonDown(POINT point)
{
	if(m_bflagMenutoLevel == true)
	{
		m_tool.ResetToolBox();			//重置工具箱
		m_menu.PlayGame(point);
		m_wlevel = m_menu.GetLevel();    //获得关卡
		
		m_menu.ReturnMenu(point);
		m_menu.ChangeSound(point);

		
	}
	if(m_bflagMenutoLevel == false && m_menu.GetLevel() == m_level->m_Flag && m_menu.GetLevelState()[m_level->m_Flag-1])
		m_level->LevelRun(point);

	if(m_tool.m_ToolEnterFlag == true || false == m_tool.m_ToolQuitFlag)//如果进入工具箱
	{
		if(m_tool.ReturnMenu(point) == true)
		{
			m_bflagMenutoLevel = true;
			m_menu.SetLevel(0);
			m_menu.SetMenuFlag(0);
			m_level->LevelReset();
			m_tool. m_ToolEnterFlag = false;
			m_tool. m_ToolQuitFlag = true;
		}
		m_tool.IsCarryClue(point);
	}
	if(m_level != nullptr && m_level->IsPassLevel() == true)               //如果通关         
	{
		this->OnGameDraw();
		
		back.ChangeDoorFlag (point);  //点击门之后灯变亮
		
		if(back.doorflag == 2)
		{
			m_level->LevelReset();  //重置关卡
			m_tool.ResetToolBox();			//重置工具箱
			if(m_wlevel < 6)		//到最后一关
				m_wlevel = m_level->m_Flag + 1;
			
			//置位通关标志
			if(!m_menu.GetLevelState()[m_wlevel-1])
				m_menu.SetLevelState(m_wlevel);

			m_menu.SetLevel(m_wlevel);
			back.ResetDoorFlag();	
			if(m_level->m_Flag == 6)
			{
				m_isvertory = 1;	//通过第六关，即为通关
				return;
			}
		}
	}

	if(m_isvertory == 1 && point.x >=0 && point.x <= 1000 && point.y >= 0 && point.y <= 601)
	{
		m_isvertory = 2;	//弹出对话框，胜利
		MessageBox(hWnd_Main,"恭喜你通关啦O(∩_∩)O~","Congratulations",MB_OK);
		//回到主菜单----------
		m_menu.SetLevel(0);
		m_menu.SetMenuFlag(0);
		m_isvertory = 0;
		m_bflagMenutoLevel = true;
		//----------回到主菜单
	}

	if(m_bflagMenutoLevel == false)
	/***************************进入或退出工具箱*********************************************/
	m_tool.InOrOutDown(point);
	/***************************************************************************************/
}
void CEscapeRoom::OnLbuttonUp(POINT point)
{
	if(m_bflagMenutoLevel == false)
	{
		/*************************进入或退出工具箱***********************************************/
		m_tool.InOrOutUp(point);
		/***************************************************************************************/
		m_level->LevelLButtonUp(point);
	}
}
//程序退出，存档
void CEscapeRoom::OnGameQuit()
{
	struct Save_Game save;
	memcpy(save.m_bLevelFlag,m_menu.GetLevelState(),sizeof(bool)*6); //过了几关
	save.m_Level = m_menu.GetLevel();
	save.m_wlevel = this->m_wlevel;                    //标志   哪一关	
	FILE *pfile;
	pfile = fopen("./test.in","wb");
	fwrite(&save,sizeof(save),1,pfile);
	fclose(pfile);
}
