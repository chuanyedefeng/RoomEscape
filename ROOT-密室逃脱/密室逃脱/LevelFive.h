#pragma once
#include "level.h"
#include "Clue_Screen.h"
class CLevelFive :
	public CLevel
{
public:
	CLevelFive(void);
	virtual ~CLevelFive(void);
public:
	virtual void LevelBackInit(HINSTANCE hIns);
	virtual void LevelBackShow(HDC hMemDC) ;

	virtual void LevelClueInit(HINSTANCE hIns);
	virtual void LevelClueShow(HDC hMemDC);

	virtual void LevelRun(POINT point) ;    //每关开始运行
	virtual void LevelDraw(HDC hMemDC) ;   //每关的重绘

	virtual void LevelLButtonUp(POINT point);
	virtual void LevelReset();
	bool IsOK() ;  //屏幕全对
	virtual void LevelClueMove();
public:
	CClue_Screen* m_clueScreen;
};

