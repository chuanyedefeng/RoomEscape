#pragma once
#include "level.h"
#include "Clue_Puzzle.h"
class CLevelSix :
	public CLevel
{
public:
	CLevelSix(void);
	virtual ~CLevelSix(void);
	

public:
	void LevelBackInit(HINSTANCE hIns);
	void LevelBackShow(HDC hMemDC);

	void LevelClueInit(HINSTANCE hIns);
	void LevelClueShow(HDC hMemDC);

	void LevelRun(POINT point)   ;    //每关开始运行
	void LevelDraw(HDC hMemDC);   //每关的重绘


	void LevelReset();

	void Return();
	void LevelClueMove();
	bool IsOK();
private:
	CClue_Puzzle* m_cluepuzzle;
	HBITMAP m_hBack1;
	HBITMAP m_hBack2;
	HBITMAP m_hBack3;
	
public:
	CClue_Puzzle* GetCluePuzzle()
	{
		return m_cluepuzzle;
	}
public:
	
	bool m_TempFlag;
};

