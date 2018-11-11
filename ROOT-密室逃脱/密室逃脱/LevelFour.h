#pragma once
#include "level.h"
#include "Level4_Clue.h"
class CLevelFour :
	public CLevel
{
public:
	CLevelFour(void);
	virtual ~CLevelFour(void);
public:
	virtual void LevelBackInit(HINSTANCE hIns) ;
	virtual void LevelBackShow(HDC hMemDC) ;

	virtual void LevelClueInit(HINSTANCE hIns) ;
	virtual void LevelClueShow(HDC hMemDC);

	virtual void LevelRun(POINT point) ;    //每关开始运行
	virtual void LevelDraw(HDC hMemDC) ;   //每关的重绘
	void LevelLButtonUp(POINT point);
	virtual void LevelReset();
	bool IsOK();
private:
	CLevel4_Clue* m_pClue;
};

