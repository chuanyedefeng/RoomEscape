#pragma once
#include "sys.h"
#include "Clue.h"
#include "LevelTip.h"
class CLevel
{
public:
	int m_Flag;             // 每一关的标志     m_flag = -m_flag  通过当前关      m_flag = n  进入第n关
	HBITMAP m_bmpBack;     // 哪一关的背景图
	list<CClue*> m_clue;   //线索类链表
	CLevelTip* m_ptip;
	int m_levelTemp;
	bool m_tipflag;
public:
	CLevel(void);
	virtual ~CLevel(void);

public:
	virtual void LevelBackInit(HINSTANCE hIns) = 0;
	virtual void LevelBackShow(HDC hMemDC) = 0;

	virtual void LevelClueInit(HINSTANCE hIns) = 0;
	virtual void LevelClueShow(HDC hMemDC) = 0;

	virtual void LevelRun(POINT point)   = 0 ;    //每关开始运行
	virtual void LevelDraw(HDC hMemDC)  = 0;   //每关的重绘

	virtual void LevelLButtonUp(POINT point){};
	virtual void LevelReset(){};
	bool IsPassLevel()          //是否通关
	{
		if(m_Flag < 0)
			return true;
		else
			return false;
	}
	void GetTipState()
	{
		
	}
	virtual void Return()
	{
	
	}
	virtual void LevelClueMove(){};
};

