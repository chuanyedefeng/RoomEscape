#include "Level4_Clue.h"


CLevel4_Clue::CLevel4_Clue(void)
{
	m_hBmpCodeAll = 0;
	for(int i=0;i<8;i++)
	{
		arrBrightDark[i]=1;
		m_hBmpCodeBright[i] = 0;
		m_hBmpCodeDark[i] = 0;
	}
	m_hBmpBackClue1=0;
	//m_hBmpBackClue2=0;
	m_flag = 0;
}


CLevel4_Clue::~CLevel4_Clue(void)
{
	DeleteObject(m_hBmpCodeAll);
	m_hBmpCodeAll = 0;
	for(int i=0;i<8;i++)
	{
		DeleteObject(m_hBmpCodeBright[i]);
		m_hBmpCodeBright[i] = 0;
	}
	DeleteObject(m_hBmpBackClue1);
	m_hBmpBackClue1 = 0;
	//DeleteObject(m_hBmpBackClue2);
	//m_hBmpBackClue2 = 0;
}

void CLevel4_Clue::ClueShow(HDC hMemDC)
{
	HDC hTempDC = CreateCompatibleDC(hMemDC);
	//ÌùÃÜÂëÍ¼
	if(m_flag == 2)
	{
		SelectObject(hTempDC,m_hBmpCodeAll);
		BitBlt(hMemDC,0,0,1000,562,hTempDC,0,0,SRCCOPY);
		for(int i=0;i<8;i++)
		{
			if(arrBrightDark[i] == 1)
			{
				SelectObject(hTempDC,m_hBmpCodeBright[i]);
				BitBlt(hMemDC,252+i*68,250,65,65,hTempDC,0,0,SRCCOPY);
			}
			else
			{
				SelectObject(hTempDC,m_hBmpCodeDark[i]);
				BitBlt(hMemDC,252+i*68,250,65,65,hTempDC,0,0,SRCCOPY);
			}
		}
	}
	if(m_flag == 4)
	{
		SelectObject(hTempDC,m_hBmpBackClue1);
		BitBlt(hMemDC,0,0,1000,562,hTempDC,0,0,SRCCOPY);
	}
	//if(m_flag == 2)
	//{
	//	SelectObject(hTempDC,m_hBmpBackClue1);
	//	BitBlt(hMemDC,0,0,1136,640,hTempDC,0,0,SRCCOPY);
	//}
	//if(m_flag == 3)
	//{
	//	SelectObject(hTempDC,m_hBmpBackClue2);
	//	BitBlt(hMemDC,0,0,1136,640,hTempDC,0,0,SRCCOPY);
	//}
	DeleteDC(hTempDC);
}
void CLevel4_Clue::ClueInit(HINSTANCE hIns)
{
	m_hBmpCodeAll = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level4_Clue_BACK2));
	m_hBmpCodeDark[0] = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level4_B1));
	m_hBmpCodeDark[1] = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level4_B2));
	m_hBmpCodeDark[2] = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level4_B3));
	m_hBmpCodeDark[3] = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level4_B4));
	m_hBmpCodeDark[4] = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level4_B5));
	m_hBmpCodeDark[5] = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level4_B6));
	m_hBmpCodeDark[6] = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level4_B7));
	m_hBmpCodeDark[7] = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level4_B8));
	m_hBmpCodeBright[0] = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level4_W_1));
	m_hBmpCodeBright[1] = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level4_W_2));
	m_hBmpCodeBright[2] = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level4_W_3));
	m_hBmpCodeBright[3] = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level4_W_4));
	m_hBmpCodeBright[4] = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level4_W_5));
	m_hBmpCodeBright[5] = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level4_W_6));
	m_hBmpCodeBright[6] = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level4_W_7));
	m_hBmpCodeBright[7] = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level4_W_8));
	m_hBmpBackClue1 = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level4_Clue_BACK1));
	/*m_hBmpBackClue2 = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_BACKCLUE2));*/
}


	

