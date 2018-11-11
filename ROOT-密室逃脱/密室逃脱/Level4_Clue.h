#pragma once
#include "clue.h"
class CLevel4_Clue :
	public CClue
{
public:
	CLevel4_Clue(void);
	virtual ~CLevel4_Clue(void);
public:
	virtual void ClueShow(HDC hMemDC);
	virtual void ClueInit(HINSTANCE hIns);
public:
	int arrBrightDark[8];
	HBITMAP m_hBmpCodeAll;
	HBITMAP m_hBmpCodeBright[8];
	HBITMAP m_hBmpCodeDark[8];
	HBITMAP m_hBmpBackClue1;
	//HBITMAP m_hBmpBackClue2;
	int m_flag;
};

