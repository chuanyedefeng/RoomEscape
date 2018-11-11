#include "CodesLock.h"


CCodesLock::CCodesLock(void)
{
	for(size_t i = 0;i < 5;i++)
		m_CodeFlag[i] = 0;               
	for(size_t i = 0; i < 10;i++)
	{
		m_BmpCodes[i] = 0;
	}
	m_clueID = ID_LEVEL2_CODELOCK;
}


CCodesLock::~CCodesLock(void)
{
	for(size_t i = 0; i < 10;i++)
	{
		DeleteObject(m_BmpCodes[i] );
		m_BmpCodes[i] = 0;
	}
}

void CCodesLock::ClueInit(HINSTANCE hIns) 
{
	m_bmpClue = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Bmp0000));             //初始化密码锁句柄 
	for(size_t i = 0;i < 10 ;i++)                                //初 始化     0—9   密码                                                
	{
		m_BmpCodes[i] = LoadBitmap(hIns,MAKEINTRESOURCE( IDB_Bmp0 + i)); 
	}
}

void CCodesLock::ClueShow(HDC hMemDC, int code[5])      //密码在什么地方显示，显示多少
{
	HDC hTempDC = CreateCompatibleDC(hMemDC);

	SelectObject(hTempDC,m_bmpClue);
	BitBlt(hMemDC,0,0,1000,562,hTempDC,0,0,SRCCOPY);
	for(size_t i = 0; i < 5; i++)
	{
		SelectObject(hTempDC,m_BmpCodes[code[i]] );
		BitBlt(hMemDC,219 + i*128,224,99,126,hTempDC,0,0,SRCCOPY);
	}
	DeleteDC(hTempDC);
}