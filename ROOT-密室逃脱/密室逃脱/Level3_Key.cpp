#include "Level3_Key.h"


CLevel3_Key::CLevel3_Key(void)
{
	m_htoolkey = 0;
	m_bmpClue = 0;
	m_bmpClue2 = 0;
	clue_point.x= 261;    //线索的坐标
	clue_point.y= 471;    

	clue_cpoint.x = 71;   //线索的长度和宽度
	clue_cpoint.y = 36;   
	m_clueID = ID_LEVEL3_KEY;
}


CLevel3_Key::~CLevel3_Key(void)
{
	DeleteObject(m_bmpClue);
	m_bmpClue = 0;
	DeleteObject(m_bmpClue2);
	m_bmpClue2 = 0;
	DeleteObject(m_htoolkey);
	m_htoolkey = 0;
	
}

void CLevel3_Key::ClueInit(HINSTANCE hIns)
{
	m_bmpClue = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level3_WKey));   //bai
	m_bmpClue2 = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level3_BKey));
	m_htoolkey = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level3_ToolKey));
}

void CLevel3_Key::ClueShow(HDC hMemDC)
{
	HDC hTempDC = CreateCompatibleDC(hMemDC);
	SelectObject(hTempDC,m_bmpClue);
	BitBlt(hMemDC,clue_point.x,clue_point.y,clue_cpoint.x,clue_cpoint.y,hTempDC,0,0,SRCAND);
	SelectObject(hTempDC,m_bmpClue2);
	BitBlt(hMemDC,clue_point.x,clue_point.y,clue_cpoint.x,clue_cpoint.y,hTempDC,0,0,SRCPAINT);

	DeleteDC(hTempDC);
}

void CLevel3_Key::ToolClueShow(HDC hMemDC,int i)
{
	HDC hTempDC = CreateCompatibleDC(hMemDC);
	SelectObject(hTempDC,m_bmpClue);
	BitBlt(hMemDC,168+ i*140,477,71,36,hTempDC,0,0,SRCAND);
	SelectObject(hTempDC,m_bmpClue2);
	BitBlt(hMemDC,168+ i*140,477,71,36,hTempDC,0,0,SRCPAINT);
	DeleteDC(hTempDC);
}
void CLevel3_Key::ClueMove()
{
	clue_point.x -= 3;
}

void CLevel3_Key::ClueReset()
{
	clue_point.x= 261;    //线索的坐标
	clue_point.y= 471; 
}