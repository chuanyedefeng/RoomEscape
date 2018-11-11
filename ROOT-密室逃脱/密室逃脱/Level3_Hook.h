#pragma once
#include "Clue.h"
class CLevel3_Hook :
	public CClue
{
public:
	CLevel3_Hook(void);
	~CLevel3_Hook(void);
public:
	virtual void ClueShow(HDC hMemDC);
	virtual void ClueInit(HINSTANCE hIns);
	virtual void ClueReset();
	virtual void ClueMove();
	void ToolClueShow(HDC hMemDC,int i);
public:
	HBITMAP m_htoolHook;
};

