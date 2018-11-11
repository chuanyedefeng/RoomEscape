#pragma once
#include "clue.h"
class CLevel3_Key :
	public CClue
{
public:
	CLevel3_Key(void);
	~CLevel3_Key(void);
public:
	virtual void ClueShow(HDC hMemDC);
	virtual void ClueInit(HINSTANCE hIns);
	virtual void ClueMove();
	virtual void ClueReset();
	void ToolClueShow(HDC hMemDC,int i);
public:
	HBITMAP m_htoolkey;
};

