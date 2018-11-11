#include "Level3_Hook.h"


CLevel3_Hook::CLevel3_Hook(void)
{
	m_bmpClue = 0;
	m_bmpClue2 = 0;
	m_htoolHook =0;
	clue_point.x = 735;    //线索的坐标
	clue_point.y = 506;  
	clue_cpoint.x = 71;
	clue_cpoint.y = 42;//线索的长度和宽度
	m_clueID = ID_LEVEL3_HOOK;
}


CLevel3_Hook::~CLevel3_Hook(void)
{
	DeleteObject(m_bmpClue);
	m_bmpClue = 0;
	
	DeleteObject(m_bmpClue2);
	m_bmpClue2 = 0;

	DeleteObject(m_htoolHook);
	m_htoolHook = 0;
}

void CLevel3_Hook::ClueInit(HINSTANCE hIns)
{
	m_bmpClue = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level3_WHook)); ///bai
	m_bmpClue2 =LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level3_BHook));

	m_htoolHook =LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level3_ToolHook));
}

void CLevel3_Hook::ClueShow(HDC hMemDC)
{
	HDC hTempDC = CreateCompatibleDC(hMemDC);
	SelectObject(hTempDC,m_bmpClue);
	BitBlt(hMemDC,clue_point.x,clue_point.y,clue_cpoint.x,clue_cpoint.y,hTempDC,0,0,SRCAND);
	SelectObject(hTempDC,m_bmpClue2);
	BitBlt(hMemDC,clue_point.x,clue_point.y,clue_cpoint.x,clue_cpoint.y,hTempDC,0,0,SRCPAINT);

	DeleteDC(hTempDC);
	
}
void CLevel3_Hook::ToolClueShow(HDC hMemDC,int i)
{
	HDC hTempDC = CreateCompatibleDC(hMemDC);
	SelectObject(hTempDC,m_bmpClue);
	BitBlt(hMemDC,168+ i*140,477,71,42,hTempDC,0,0,SRCAND);
	SelectObject(hTempDC,m_bmpClue2);
	BitBlt(hMemDC,168+ i*140,477,71,42,hTempDC,0,0,SRCPAINT);
	DeleteDC(hTempDC);

}

void CLevel3_Hook::ClueMove()
{
	clue_point.x-= 5;
}

void CLevel3_Hook::ClueReset()
{
	clue_point.x = 735;    //线索的坐标
	clue_point.y = 506; 
}