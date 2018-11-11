#pragma once
#include "clue.h"
class CClue_Puzzle :
	public CClue
{
public:
	CClue_Puzzle(void);
	~CClue_Puzzle(void);
public:
	void ClueShow(HDC hMemDC);
	void ClueInit(HINSTANCE hIns);

	void ClueMove();

	void ClueReset();

	void ToolClueShow(HDC hMemDC,int i);
public:

	int ArrNum[3][3];
	HBITMAP m_hBmpCodeAll;
	HBITMAP m_hBmpNum[9];
	HBITMAP m_hBmpBackClue2;
	HBITMAP m_hBmpBackClue3;
	HBITMAP m_hBmpBackClue4;
	HBITMAP m_hKey_W;
	HBITMAP m_hKey_B;
	HBITMAP m_hTool_Key_W;
	HBITMAP m_hTool_Key_B;
public:
	int m_flag;
	bool m_clueflag; //获得此状态才能插进钥匙
};

