#include "Clue_Puzzle.h"


CClue_Puzzle::CClue_Puzzle(void)
{
	m_bmpClue = NULL ;
	m_bmpClue2 = NULL;
	m_hKey_W = 0;
	m_hKey_B = 0;
	m_hTool_Key_W = 0;
	m_hTool_Key_B = 0;
	clue_point.x  = 730;    //钥匙的坐标
	clue_point.y  = 175;
	clue_cpoint.x = 80;  //钥匙的大小
	clue_cpoint.y = 48;  
	m_clueID = ID_LEVEL6_KET;

	for(int i=0;i<3;i++)
		for(int j=0;j<3;j++)
			ArrNum[3][3] = 0;
	m_hBmpCodeAll = 0;
	for(int i=0;i<9;i++)
	{
		m_hBmpNum[i] = 0;
	}
	
	m_hBmpBackClue2 = 0;
	m_hBmpBackClue3 = 0;
	m_hBmpBackClue4 = 0;

	m_flag = 0;
	m_clueflag = false;
}


CClue_Puzzle::~CClue_Puzzle(void)
{
	if(m_bmpClue)
	{
		DeleteObject(m_bmpClue);
		m_bmpClue = NULL ;
	}
	if(m_bmpClue)
	{
		DeleteObject(m_bmpClue2);
		m_bmpClue2 = NULL ;
	}
	if(m_hKey_W)
	{
		DeleteObject(m_hKey_W);
		m_hKey_W = 0;
	}
	if(m_hKey_B)
	{
		DeleteObject(m_hKey_B);
		m_hKey_B = 0;
	}
	if(m_hTool_Key_W)
	{
		DeleteObject(m_hTool_Key_W);
		m_hTool_Key_W = 0;
	}
	if(m_hTool_Key_B)
	{
		DeleteObject(m_hTool_Key_B);
		m_hTool_Key_B = 0;
	}
	DeleteObject(m_hBmpCodeAll);
	m_hBmpCodeAll = 0;
	for(int i=0;i<9;i++)
	{
		DeleteObject(m_hBmpNum[i]);
		m_hBmpNum[i] = 0;
	}
	DeleteObject(m_hBmpBackClue2);
	m_hBmpBackClue2 = 0;
	DeleteObject(m_hBmpBackClue3);
	m_hBmpBackClue3 = 0;
	DeleteObject(m_hBmpBackClue4);
	m_hBmpBackClue4 = 0;
}

void CClue_Puzzle::ClueShow(HDC hMemDC)
{
	HDC hTempDC = CreateCompatibleDC(hMemDC);
	//贴密码图
	if( m_flag == 1 )	//点击获得钥匙，并且开始移动
	{
		SelectObject(hTempDC,m_hKey_W);
		BitBlt(hMemDC,clue_point.x,clue_point.y,clue_cpoint.x,clue_cpoint.y,hTempDC,0,0,SRCAND);
		SelectObject(hTempDC,m_hKey_B);
		BitBlt(hMemDC,clue_point.x,clue_point.y,clue_cpoint.x,clue_cpoint.y,hTempDC,0,0,SRCPAINT);
	}
	if(m_flag == 3) //点击线索
	{
		SelectObject(hTempDC,m_hBmpCodeAll);
		BitBlt(hMemDC,0,0,1000,563,hTempDC,0,0,SRCCOPY);
		for(int i=0;i<3;i++)
		{
			for(int j=0;j<3;j++)
			{
				if(ArrNum[i][j] != 5)
				{
					SelectObject(hTempDC,m_hBmpNum[ArrNum[i][j]-1]);
					BitBlt(hMemDC,262+j*157,76+i*157,155,155,hTempDC,0,0,SRCCOPY);
				}
			}
		}
	}
	if(m_flag == 4)//点击通过，出现钥匙孔
	{
		SelectObject(hTempDC,m_hBmpBackClue2);
		BitBlt(hMemDC,0,0,1000,562,hTempDC,0,0,SRCCOPY);
	}
	if(m_flag == 5)	//将钥匙插进钥匙孔
	{
		SelectObject(hTempDC,m_hBmpBackClue3);
		BitBlt(hMemDC,0,0,1000,562,hTempDC,0,0,SRCCOPY);
	}
	if(m_flag == 6)	//钥匙旋转，在次点击通关
	{
		SelectObject(hTempDC,m_hBmpBackClue4);
		BitBlt(hMemDC,0,0,1000,562,hTempDC,0,0,SRCCOPY);
	}
	
	DeleteDC(hTempDC);
}
void CClue_Puzzle::ClueInit(HINSTANCE hIns)
{
	ArrNum[0][0] = 5; 
	ArrNum[0][1] = 2; 
	ArrNum[0][2] = 8; 
	ArrNum[1][0] = 3; 
	ArrNum[1][1] = 9; 
	ArrNum[1][2] = 6; 
	ArrNum[2][0] = 1; 
	ArrNum[2][1] = 7; 
	ArrNum[2][2] = 4; 
	m_hBmpCodeAll = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level6_Clue_Back));
	
	m_hBmpBackClue2 = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level6_Clue0));
	m_hBmpBackClue3 = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level6_Clue1));
	m_hBmpBackClue4 = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level6_Clue2));
	

	m_hBmpNum[0] = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level6_1));
	m_hBmpNum[1] = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level6_2));
	m_hBmpNum[2] = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level6_3));
	m_hBmpNum[3] = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level6_4));
	m_hBmpNum[5] = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level6_6));
	m_hBmpNum[6] = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level6_7));
	m_hBmpNum[7] = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level6_8));
	m_hBmpNum[8] = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level6_9));

	m_hKey_W = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level6_Key_W));
	m_hKey_B = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level6_Key_B));
	m_hTool_Key_W = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level6_Tool_Key_W));
	m_hTool_Key_B = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_Level6_Tool_Key_B));
}
void CClue_Puzzle::ClueMove()
{
	if(m_flag == 1 )
	{
		clue_point.x -= 7;
		clue_point.y += 3;
		if(clue_point.x < 27)
		{
			m_flag = 2;	//获得钥匙
		}
	}
}
void CClue_Puzzle::ClueReset()
{
	m_flag = 0;
	ArrNum[0][0] = 5; 
	ArrNum[0][1] = 2; 
	ArrNum[0][2] = 8; 
	ArrNum[1][0] = 3; 
	ArrNum[1][1] = 9; 
	ArrNum[1][2] = 6; 
	ArrNum[2][0] = 1; 
	ArrNum[2][1] = 7; 
	ArrNum[2][2] = 4; 
	m_clueflag = false;
}

void CClue_Puzzle::ToolClueShow(HDC hMemDC,int i)
{
	HDC hTempDC = CreateCompatibleDC(hMemDC);
	SelectObject(hTempDC,m_hKey_W);
	BitBlt(hMemDC,160+ i*140,477,clue_cpoint.x,clue_cpoint.y,hTempDC,0,0,SRCAND);
	SelectObject(hTempDC,m_hKey_B);
	BitBlt(hMemDC,160+ i*140,477,clue_cpoint.x,clue_cpoint.y,hTempDC,0,0,SRCPAINT);
	DeleteDC(hTempDC);
}

	

	

