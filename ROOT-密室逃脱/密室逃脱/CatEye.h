#pragma once
#include "clue.h"
class CCatEye :
	public CClue
{
public:
	CCatEye(void);
	~CCatEye(void);
public:
	virtual void ClueShow(HDC hMemDC);
	virtual void ClueInit(HINSTANCE hIns);
};

