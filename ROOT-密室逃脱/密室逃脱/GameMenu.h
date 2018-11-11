#pragma once
#include "sys.h"
#include <cstring>
class CGameMenu
{
public:
	CGameMenu(void);
	~CGameMenu(void);
public:
	HBITMAP m_hLevelAll;
	HBITMAP m_hLevel2_Val;
	HBITMAP m_hLevel3_Val;
	HBITMAP m_hLevel4_Val;
	HBITMAP m_hLevel5_Val;
	HBITMAP m_hLevel6_Val;
	HBITMAP m_hMain_Menu;
	HBITMAP m_hMain_SdMenu;
public:
	void ChangeSound(POINT point);
	void PlayGame(POINT point);		//进入游戏，选关
	void ReturnMenu(POINT point);		//返回主菜单

	void MenuInit(HINSTANCE hIns);
	void MenuShow(HDC hMemDC);

	int GetLevel();
	void SetLevel(int Level);

	bool* GetLevelState();
	void SetLevelState(int i);

	void SetMenuFlag(int flag);
	char* GetSoundWav()
	{
		return m_sound;
	}
	bool Getsoundflag()
	{
		return m_soundflag;
	}
private:
	bool m_soundflag;
	bool m_bLevelFlag[6];
	int m_Menuflag;
	int m_Level;
	char* m_sound;
public:
	int* m_TipCount;
	
};

