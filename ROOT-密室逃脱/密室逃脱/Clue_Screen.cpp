#include "Clue_Screen.h"


CClue_Screen::CClue_Screen(void)
{
	m_clueID = ID_LEVEL5_KEY;
	clue_point.x = 290;    //移动钥匙的坐标
	clue_point.y = 198;
	clue_cpoint.x = 100;   //移动钥匙的长度和宽度
	clue_cpoint.y = 64;   
	m_hBmpScreen = 0;
	m_hBack1 = 0;
	m_hBack2 = 0;
	m_hBack3 = 0;
	m_hKey_W = 0;
	m_hKey_B = 0;
	m_hTool_KeyW = 0;
	m_hTool_KeyB = 0;
	m_flag = 0;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		arrIsScreen[i][j]=-1;
	}
}


CClue_Screen::~CClue_Screen(void)
{
	DeleteObject(m_hKey_W);
	m_hKey_W = NULL;
	DeleteObject(m_hTool_KeyB);
	m_hTool_KeyB = NULL;

	DeleteObject(m_hBmpScreen);
	m_hBmpScreen = NULL;
	DeleteObject(m_hBack1);
	m_hBack1 = NULL;
	DeleteObject(m_hBack2);
	m_hBack2 = NULL;
	DeleteObject(m_hBack3);
	m_hBack3 = NULL;

	DeleteObject(m_hTool_KeyW);
	m_hTool_KeyW = NULL;
	DeleteObject(m_hTool_KeyB);
	m_hTool_KeyB = NULL;
}

void CClue_Screen::ClueShow(HDC hMemDC)
{
	HDC hTempDC = CreateCompatibleDC(hMemDC);
	SelectObject(hTempDC,m_hBmpScreen);
	//贴Screen图
	if(m_flag == 0)
	{
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(arrIsScreen[i][j]==1)
				{
					BitBlt(hMemDC,644+j*114,148+i*107,95,95,hTempDC,0,0,SRCCOPY);
				}
			}
		}
	}
	if(m_flag == 2 )
	{
		SelectObject(hTempDC,m_hKey_W);
		BitBlt(hMemDC,clue_point.x,clue_point.y,clue_cpoint.x,clue_cpoint.y,hTempDC,0,0,SRCAND);
		SelectObject(hTempDC,m_hKey_B);
		BitBlt(hMemDC,clue_point.x,clue_point.y,clue_cpoint.x,clue_cpoint.y,hTempDC,0,0,SRCPAINT);
	}

	DeleteDC(hTempDC);
}
void CClue_Screen::ClueInit(HINSTANCE hIns)
{
	m_hBmpScreen = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_SCREENCLUE));
	m_hBack1 = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_BACKCLUE2_1));
	m_hBack2 = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_BACKCLUE2_2));
	m_hBack3 = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_BACKCLUE2_3));
	m_hTool_KeyW  = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level5_Key_W));
	m_hTool_KeyB  = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level5_Key_B));
	m_hKey_W =  LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level5_Tool_Key_W));
	m_hKey_B =  LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level5_Tool_Key_B));
}

void CClue_Screen::ToolClueShow(HDC hMemDC,int i)
{
	HDC hTempDC = CreateCompatibleDC(hMemDC);
	SelectObject(hTempDC,m_hKey_W);
	BitBlt(hMemDC,155+ i*140,460,100,64,hTempDC,0,0,SRCAND);
	SelectObject(hTempDC,m_hKey_B);
	BitBlt(hMemDC,155+ i*140,460,100,64,hTempDC,0,0,SRCPAINT);
	DeleteDC(hTempDC);
}

void CClue_Screen::ClueMove()
{
	if(m_flag == 2)
	{
		clue_point.x -= 4;
		clue_point.y += 4;
		if(clue_point.x <= 27)
		{
			m_flag = 3;
		}
	}
}
void CClue_Screen::ClueReset()
{
	m_clueID = ID_LEVEL5_KEY;
	clue_point.x = 290;    //移动钥匙的坐标
	clue_point.y = 198;
	clue_cpoint.x = 100;   //移动钥匙的长度和宽度
	clue_cpoint.y = 64;  
	m_flag = 0;
	for(int i=0;i<3;i++)
	{
		for(int j=0;j<3;j++)
		arrIsScreen[i][j]=-1;
	}
}