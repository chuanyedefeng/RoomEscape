#pragma once
#include "cgamectrl.h"
#include "Level.h"
#include "LevelFirst.h"
#include "Back.h"
#include <queue>
#include <list>
using namespace std;
#include "ToolBox.h"
#include "LevelSecond.h"
#include "LevelThrid.h"
#include "LevelFour.h"
#include "LevelFive.h"
#include "LevelSix.h"
#include "GameMenu.h"
//声音播放头文件和库
#include <mmsystem.h>
#pragma comment(lib, "WINMM.LIB")

class CEscapeRoom :
	public CGameCtrl
{
	public:
	_DECLEAR_()

public:
	CEscapeRoom(void);
	~CEscapeRoom(void);
public:
	virtual void OnCreatGame();                                       
	virtual void OnGameRun(WPARAM n_TimerID);
	virtual void OnGameDraw();
	virtual void OnLButtonDown(POINT point);
	virtual void OnLbuttonUp(POINT point);
	virtual void OnGameQuit();
public:
	int m_wlevel;                    //标志   哪一关
	HDC dc;						 	//窗口DC
	HDC hMemDC ;				// 兼容性DC
	HBITMAP hBitmap;			//兼容性位图
	HBITMAP m_hmpend;
public:
	list<CLevel*> m_lstlevel;       //用来选关
	CLevel* m_level;					//记录当前关
	CBack back;                    //背景对象
	CToolBox m_tool;
public:
	CGameMenu m_menu;
	bool m_bflagMenutoLevel;
	int m_isvertory;

};

