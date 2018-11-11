#pragma once
#include "level.h"
class CLevelSecond :
	public CLevel
{
public:
	CLevelSecond(void);
	virtual ~CLevelSecond(void);
public:
	virtual void LevelBackInit(HINSTANCE hIns) ;
	virtual void LevelBackShow(HDC hMemDC);

	virtual void LevelClueInit(HINSTANCE hIns);
	virtual void LevelClueShow(HDC hMemDC);

	virtual void LevelRun(POINT point)  ;    //每关开始运行
	virtual void LevelDraw(HDC hMemDC) ;   //每关的重绘

	virtual void LevelClueMove();

	virtual void LevelReset();
private:
	HBITMAP m_hLight[4][5];		
	HBITMAP m_Clue_B;
	HBITMAP m_Clue_W;
	POINT m_cluepoint;

	int m_secondflag;			//第二关状态的标记
		
	int m_arrClue[4][5] ;
	int m_clueflag;
	
};
