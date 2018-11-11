#include "GameMenu.h"


CGameMenu::CGameMenu(void)
{
	m_TipCount = new int(15);  //每关提示需要10个豆，过一关可以获得5个豆，初始化为15个
	m_soundflag = true;
	
	FILE *pfile;
	struct Save_Game save;
	
	for(int i = 0;i <6;i++)
	{
		m_bLevelFlag[i] = false;
	}
	m_bLevelFlag[0] = true;
	m_Level = 0;
	//读存档
	pfile = fopen("./test.in","rb");
	if(pfile != NULL)
	{
		fread(&save,sizeof(save),1,pfile);
		memcpy(m_bLevelFlag,save.m_bLevelFlag,sizeof(bool)*6);
		m_Level = save.m_Level;
	}
	if(pfile)
	fclose(pfile);

	m_Menuflag = 0;
	

	m_hLevelAll   = 0;
	m_hLevel2_Val = 0;
	m_hLevel3_Val = 0;
	m_hLevel4_Val = 0;
	m_hLevel5_Val = 0;
	m_hLevel6_Val = 0;
	m_hMain_Menu = 0 ;
	m_hMain_SdMenu = 0;
	m_sound = "Music.wav";
}


CGameMenu::~CGameMenu(void)
{
	if(m_hLevelAll)
	{
		DeleteObject(m_hLevelAll);
		m_hLevelAll = NULL;
	}
	if(m_hLevel2_Val)
	{
		DeleteObject(m_hLevel2_Val);
		m_hLevel2_Val = NULL;
	}
	if(m_hLevel3_Val)
	{
		DeleteObject(m_hLevel3_Val);
		m_hLevel3_Val = NULL;
	}
	if(m_hLevel4_Val)
	{
		DeleteObject(m_hLevel4_Val);
		m_hLevel4_Val = NULL;
	}
	if(m_hLevel5_Val)
	{
		DeleteObject(m_hLevel5_Val);
		m_hLevel5_Val = NULL;
	}
	if(m_hLevel6_Val)
	{
		DeleteObject(m_hLevel6_Val);
		m_hLevel6_Val = NULL;
	}
	if(m_hMain_SdMenu)
	{
		DeleteObject(m_hMain_SdMenu);
		m_hMain_SdMenu = NULL;
	}
	if(m_hMain_Menu)
	{
		DeleteObject(m_hMain_Menu);
		m_hMain_Menu = NULL;
	}
}


void CGameMenu::ChangeSound(POINT point)
{
	if(m_Menuflag == 0 && point.x >= 107 && point.x <= 188 && point.y>= 61 && point.y <= 148 )
	{
		m_soundflag = !m_soundflag;
		if(m_soundflag == true)
			m_sound = "Music.wav";
		else
			m_sound = "";
	}
}

void CGameMenu::PlayGame(POINT point)		//进入游戏
{
	if(m_Menuflag == 0 && point.x >= 910 &&  point.x <= 986
		&& point.y>= 64 && point.y <= 142)
	{
		char str[100] = {0};
		sprintf(str,"  您现在共有%d颗豆，每关的提示将消耗\n10颗豆，过一关可获得5颗豆，加油喔~",*m_TipCount);
		MessageBox(NULL,str,"温馨提示",MB_OK);
		return;
	}
	if(m_Menuflag == 1 && point.x >= 185 &&  point.x <= 318
		&& point.y>= 42 && point.y <= 259)
	{
		m_Level = 1;
		return;
	}

	if(m_Menuflag == 1 && point.x >= 442 &&  point.x <= 442 + 147
		&& point.y>= 72 && point.y <= 72 + 244)
	{
		m_Level = 2;
		return;
	}
	if(m_Menuflag == 1 && point.x >= 676 &&  point.x <= 676 + 160
		&& point.y>= 33 && point.y <= 33 + 241)
	{
		m_Level = 3;
		return;
	}
	if(m_Menuflag == 1 && point.x >= 313 &&  point.x <= 313 + 146
		&& point.y>= 288 && point.y <= 288+ 233)
	{
		m_Level = 4;
		return;
	}
	if(m_Menuflag == 1 && point.x >= 577 &&  point.x <= 577 + 140
		&& point.y>= 261 && point.y <= 261+231)
	{
		m_Level = 5;
		return;
	}
	if(m_Menuflag == 1 && point.x >= 812 &&  point.x <= 812 + 144
		&& point.y>= 237 && point.y <= 237 + 230)
	{
		m_Level = 6;
		return;
	}
	if(m_Menuflag == 0 && point.x >= 642 && point.x <= 877 && point.y>= 163 && point.y <= 383)
	{
		m_Menuflag = 1;	
		return;
	}
}
void CGameMenu::ReturnMenu(POINT point)		//返回主
{
	if(m_Menuflag == 1 && point.x >= 30 && point.x <= 175 && point.y >= 175 && point.y <= 541)
	{
		m_Menuflag = 0;
		return;
	}
}
void CGameMenu::MenuInit(HINSTANCE hIns)
{
	m_hLevelAll   =::LoadBitmap(hIns,MAKEINTRESOURCE(Menu_Level_All));
	m_hLevel2_Val = ::LoadBitmap(hIns,MAKEINTRESOURCE(Menu_Level2_Val));
	m_hLevel3_Val = ::LoadBitmap(hIns,MAKEINTRESOURCE(Menu_Level3_Val));
	m_hLevel4_Val = ::LoadBitmap(hIns,MAKEINTRESOURCE(Menu_Level4_Val));
	m_hLevel5_Val = ::LoadBitmap(hIns,MAKEINTRESOURCE(Menu_Level5_Val));
	m_hLevel6_Val = ::LoadBitmap(hIns,MAKEINTRESOURCE(Menu_Level6_Val));
	m_hMain_Menu =  ::LoadBitmap(hIns,MAKEINTRESOURCE(Menu_Main_Menu));
	m_hMain_SdMenu= ::LoadBitmap(hIns,MAKEINTRESOURCE(Menu_Main_Sound));
}
void CGameMenu::MenuShow(HDC hMemDC)
{
	HDC hTempDC = CreateCompatibleDC(hMemDC);

	if(m_Menuflag == 0)
	{
		if(m_soundflag == false)
			SelectObject(hTempDC,m_hMain_SdMenu);
		else
			SelectObject(hTempDC,m_hMain_Menu);

		BitBlt(hMemDC,0,0,1000,562,hTempDC,0,0,SRCCOPY);
	}
		
	if(m_Menuflag == 1 )
	{
		SelectObject(hTempDC,m_hLevelAll);
		BitBlt(hMemDC,0,0,1000,562,hTempDC,0,0,SRCCOPY);
	}

	if(m_Menuflag == 1 && m_bLevelFlag[1] == true)
	{
		SelectObject(hTempDC,m_hLevel2_Val);
		BitBlt(hMemDC,442,72,147,244,hTempDC,0,0,SRCCOPY);
	}
	if(m_Menuflag == 1 && m_bLevelFlag[2] == true)
	{
		SelectObject(hTempDC,m_hLevel3_Val);
		BitBlt(hMemDC,676,33,160,241,hTempDC,0,0,SRCCOPY);
	}
	if(m_Menuflag == 1 && m_bLevelFlag[3] == true)
	{
		SelectObject(hTempDC,m_hLevel4_Val);
		BitBlt(hMemDC,313,288,146,233,hTempDC,0,0,SRCCOPY);
	}
	if(m_Menuflag == 1 && m_bLevelFlag[4] == true)
	{
		SelectObject(hTempDC,m_hLevel5_Val);
		BitBlt(hMemDC,577,261,140,231,hTempDC,0,0,SRCCOPY);
	}
	if(m_Menuflag == 1 && m_bLevelFlag[5] == true)
	{
		SelectObject(hTempDC,m_hLevel6_Val);
		BitBlt(hMemDC,812,247,144,230,hTempDC,0,0,SRCCOPY);
	}
	DeleteDC(hTempDC);
}

bool* CGameMenu::GetLevelState()
{
	return m_bLevelFlag;
}
void CGameMenu::SetLevelState(int i )
{
	m_bLevelFlag[i-1] = true;
	*m_TipCount += 5;
}

int CGameMenu::GetLevel()
{
	return m_Level;
}
void CGameMenu::SetLevel(int Level)
{
	m_Level = Level;
}

void CGameMenu::SetMenuFlag(int flag)
{
	m_Menuflag = flag;
}