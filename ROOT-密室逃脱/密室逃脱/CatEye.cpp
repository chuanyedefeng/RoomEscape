#include "Cateye.h"


CCatEye::CCatEye(void)
{
	m_bmpClue = 0 ;
	//clue_point  ;    //����������
	//clue_cpoint;   //�����ĳ��ȺͿ��
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
