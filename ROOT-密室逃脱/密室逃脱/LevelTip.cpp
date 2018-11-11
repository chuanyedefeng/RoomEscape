#include "LevelTip.h"


CLevelTip::CLevelTip()
{
	m_tipflag = 0;
	for(size_t i = 0;i < 6;i++)
	{
		m_hlevel1_tip[i] = 0;
	}
	m_ntipcount = nullptr;
}


CLevelTip::~CLevelTip(void)
{
	for(size_t i = 0;i < 6;i++)
	{
		DeleteObject(m_hlevel1_tip[i]);
		m_hlevel1_tip[i] = 0;
	}
}
void CLevelTip::TipShow(HDC hMemDC)
{
	HDC hTempDC = CreateCompatibleDC(hMemDC);
	SelectObject(hTempDC,m_hlevel1_tip[m_tipflag-1]);
	BitBlt(hMemDC,0,0,1000,562,hTempDC,0,0,SRCCOPY);
	DeleteDC(hTempDC);
	
}
void CLevelTip::TipInit(HINSTANCE hIns)
{
	for(size_t i = 0;i < 5;i++)
	{
		m_hlevel1_tip[i] = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_BITMAP1+ i));
	}
	m_hlevel1_tip[5] = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_END));

}
	
