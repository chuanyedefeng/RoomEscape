#pragma once
#include "clue.h"
class CClue_Screen :
	public CClue
{
public:
	CClue_Screen(void);
	virtual ~CClue_Screen(void);
public:
	virtual void ClueShow(HDC hMemDC);
	virtual void ClueInit(HINSTANCE hIns);
	virtual void ToolClueShow(HDC hMemDC,int i);
	virtual void ClueMove();
	virtual void ClueReset();
public:
	HBITMAP m_hBmpScreen;
	HBITMAP m_hBack1;
	HBITMAP m_hBack2;
	HBITMAP m_hBack3;
	HBITMAP m_hKey_W;
	HBITMAP m_hKey_B;
	HBITMAP m_hTool_KeyW;
	HBITMAP m_hTool_KeyB;
	int arrIsScreen[3][3];  //记录有无Screen的数组
	int m_flag;
};

