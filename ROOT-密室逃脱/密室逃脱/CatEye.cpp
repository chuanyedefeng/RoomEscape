#include "Cateye.h"


CCatEye::CCatEye(void)
{
	m_bmpClue = 0 ;
	//clue_point  ;    //线索的坐标
	//clue_cpoint;   //线索的长度和宽度
}


CCatEye::~CCatEye(void)
{
	DeleteObject(m_bmpClue);
	m_bmpClue = NULL;
}
void CCatEye::ClueShow(HDC hMemDC)
{
	HDC hTempDC = CreateCompatibleDC(hMemDC);
	SelectObject(hTempDC,m_bmpClue);
	BitBlt(hMemDC,0,0,1000,563,hTempDC,0,0,SRCCOPY);
	DeleteDC(hTempDC);
}
void CCatEye::ClueInit(HINSTANCE hIns)
{
	m_bmpClue = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_BmpCat));
}
