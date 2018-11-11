#include "ToolBox.h"


CToolBox::CToolBox()
{
	m_htoolBoxWhite  = 0;
	m_htoolBoxBlack  = 0;

	m_hToolBack = 0;
	m_ToolEnterFlag = false;
	m_ToolQuitFlag = true;
	m_level = NULL;
	for(int i =0 ;i < 5;i++)
	{
		m_strClue[i] = NULL;
	}
	m_WClueLight  = -1 ;

	m_ClueSelectFlag = 0;   //线索选中取消标志
}


CToolBox::~CToolBox(void)
{
	DeleteObject(m_htoolBoxWhite);
	m_htoolBoxWhite = 0;		   
	DeleteObject(m_htoolBoxBlack);
	m_htoolBoxBlack = 0;
	DeleteObject(m_hToolBack);
	m_hToolBack = 0;

	m_ToolEnterFlag = 0;

}

void CToolBox::ToolBoxInit(HINSTANCE hinstance)
{
	m_hToolBack = LoadBitmap(hinstance,MAKEINTRESOURCE(IDB_TOOLBOXBACK));
	m_htoolBoxBlack	 = LoadBitmap(hinstance,MAKEINTRESOURCE(IDB_Tool_BoxBlack));
	m_htoolBoxWhite = LoadBitmap(hinstance,MAKEINTRESOURCE(IDB_Tool_BoxWhite));
}


void CToolBox::ToolBoxShow(HDC hMemDC)
{
	HDC hTempDC = CreateCompatibleDC(hMemDC);
	SelectObject(hTempDC,m_hToolBack);
	BitBlt(hMemDC,0,0,1000,562,hTempDC,0,0,SRCCOPY);
	
	
	if(m_WClueLight != -1)
	{
		//贴亮工具框----------
		SelectObject(hTempDC,m_htoolBoxWhite);
		BitBlt(hMemDC,140 + m_WClueLight*138,429,130,133,hTempDC,0,0,SRCAND);
		SelectObject(hTempDC,m_htoolBoxBlack);
		BitBlt(hMemDC,140 + m_WClueLight*138,429,130,133,hTempDC,0,0,SRCPAINT);
		//-----------贴亮工具框


		//----将选择的物品展示
		int ClueID  = 0;
		if( m_strClue[m_WClueLight] != NULL)
			ClueID = m_strClue[m_WClueLight]->m_clueID;
		switch (ClueID)
		{
			case ID_LEVEL3_KEY:
				{
					SelectObject(hTempDC,((CLevel3_Key*)m_strClue[m_WClueLight])->m_htoolkey);
					BitBlt(hMemDC,295,125,425,221,hTempDC,0,0,SRCCOPY);
				}
				break;
			case ID_LEVEL3_HOOK:
				{
					SelectObject(hTempDC,((CLevel3_Hook*)m_strClue[m_WClueLight])->m_htoolHook);
					BitBlt(hMemDC,298,111,437,290,hTempDC,0,0,SRCCOPY);
				}
				break;
			case ID_LEVEL5_KEY:
				{
					SelectObject(hTempDC,((CClue_Screen*)m_strClue[m_WClueLight])->m_hTool_KeyW);
					BitBlt(hMemDC,298,121,431,276,hTempDC,0,0,SRCAND);
					SelectObject(hTempDC,((CClue_Screen*)m_strClue[m_WClueLight])->m_hTool_KeyB);
					BitBlt(hMemDC,298,121,431,276,hTempDC,0,0,SRCPAINT);
				}
				break;
			case ID_LEVEL6_KET:
				{
					SelectObject(hTempDC,((CClue_Puzzle*)m_strClue[m_WClueLight])->m_hTool_Key_W);
					BitBlt(hMemDC,298,121,431,276,hTempDC,0,0,SRCAND);
					SelectObject(hTempDC,((CClue_Puzzle*)m_strClue[m_WClueLight])->m_hTool_Key_B);
					BitBlt(hMemDC,298,121,431,276,hTempDC,0,0,SRCPAINT);
				}
				break;
		}
	}
	
	
	if(m_strClue[0] != NULL || m_strClue[1] != NULL)
	{
		for(int i = 0;i < 5;i++)
		{
			if(m_strClue[i] == NULL)
				continue;
			m_strClue[i]->ToolClueShow(hMemDC,i);
		}
	}

	DeleteDC(hTempDC);
}

bool CToolBox::IsEnterToolBox(POINT point)
{
	if(point.x > 7 && point.x < 109 &&point.y > 450 && point.y < 544 )
		return true;
	else
		return false;
}
bool CToolBox::IsQuitTool(POINT point)
{
	if(point.x > 27 && point.x < 93 &&point.y > 461 && point.y < 520 )
		return true;
	else
		return false;
}
void CToolBox::InOrOutDown(POINT point)
{
	/********************************进入和退出工具箱**************************************************/
	if(true == IsEnterToolBox(point) && true == m_ToolQuitFlag)  
	{
		m_ToolEnterFlag = true;
		m_ToolQuitFlag = false;
	}
	if(m_ToolEnterFlag == false && false == m_ToolQuitFlag)
	{
		if(true == IsQuitTool(point))
		{
			m_ToolQuitFlag = true;
		}
	}
	/*********************************************************************************************/
}
void CToolBox::InOrOutUp(POINT point)
{
	/***************************************进入和退出工具箱******************************************/
	if(true == m_ToolEnterFlag && true == IsEnterToolBox(point))
		m_ToolEnterFlag = false;
	if(m_ClueSelectFlag == 1)
		m_ClueSelectFlag = 2;
	/***********************************************************************************************/
}
void CToolBox::IsCarryClue(POINT point)
{
	//选择线索-------------
	for(int i = 0;i < 5;i++)
	{
		if(point.x >= 145+ i*140 &&point.x <= 145 + (1+i)*140 
			&&point.y >= 433 &&point.y <= 558 )
		{
			m_ClueSelectFlag = 1;
			m_WClueLight = i;
			break;
		}
	}//-------------选择线索
	
	//取消选定------------
	//if(m_ClueSelectFlag  == 2 )
	//{
	//	for(int i = 0;i < 5;i++)
	//	{
	//		if(m_WClueLight == i && point.x >= 140+ i*138 &&point.x <= 140 + (1+i)*138 
	//			&&point.y >= 433 &&point.y <= 558 )
	//		{
	//			m_WClueLight = -1;
	//			break;
	//		}
	//	}
	//	m_ClueSelectFlag = 1;
	//}//------------取消选择

	//点击拿起按钮---选中------
	if(m_WClueLight != -1 && point.x >= 861
		&&point.x <=990 &&point.y >= 427 &&point.y <= 557)
	{
		if(m_strClue[m_WClueLight] != NULL)
		{
			int ClueID = m_strClue[m_WClueLight]->m_clueID;
			switch (ClueID)
			{
				case ID_LEVEL3_KEY:
					{
						((CLevelThrid*)m_level)->m_ThirdFlag = LEVEL3_GET_KEY;
						m_ToolEnterFlag = false; //退出工具箱
						m_ToolQuitFlag = true;
					}
					break;
				case ID_LEVEL3_HOOK:
					{
						((CLevelThrid*)m_level)->m_clueFlag = 1;
						((CLevelThrid*)m_level)->m_ThirdFlag = 3;
						m_ToolEnterFlag = false;
						m_ToolQuitFlag = true;
					}
					break;
				case ID_LEVEL5_KEY:
					{
						((CLevelFive*)m_level)->m_clueScreen->m_flag = Level5_GET_KEY;
						m_ToolEnterFlag = false;
						m_ToolQuitFlag = true;
					}
					break;
				case ID_LEVEL6_KET:
					{
					/*	((CLevelSix*)m_level)->GetCluePuzzle()->m_flag = LEVEL6_GET_KEY;*/
						((CLevelSix*)m_level)->GetCluePuzzle()->m_clueflag = true;
						m_ToolEnterFlag = false;
						m_ToolQuitFlag = true;
					}
					break;
			}
		}
	}
	
}
void CToolBox::ChangeLevel(CLevel*& level)
{
	m_level = level;
}
void CToolBox::ResetToolBox()
{
	//m_level = NULL;
	for(int i = 0;i < 5;i++)
	{
		m_strClue[i] = NULL;
	}
	m_WClueLight = -1;
}
//---选中------点击拿起按钮
void CToolBox::ToolRun()
{
//----将选择的物品展示
	if(m_level->m_Flag == 6)
	{
		if(((CLevelSix*)m_level)->GetCluePuzzle()->m_flag == 2)
		{
			CClue **Tempstr = &m_strClue[0]; 
			while(*Tempstr++);
			Tempstr--;
			*Tempstr = ((CLevelSix*)m_level)->GetCluePuzzle();
			((CLevelSix*)m_level)->GetCluePuzzle()->m_flag = -2;
		}
		return ;
	}
	if(m_level->m_Flag == 5)
	{
		if(((CLevelFive*)m_level)->m_clueScreen->m_flag == 3)
		{
			CClue **Tempstr = &m_strClue[0]; 
			while(*Tempstr++);
			Tempstr--;
			*Tempstr = ((CLevelFive*)m_level)->m_clueScreen;
			((CLevelFive*)m_level)->m_clueScreen->m_flag = 4;
		}
		return ;
	}


	if(m_level->m_Flag == 3)
	{
		if(((CLevelThrid*)m_level)->m_HookFlag == 2)
		{
			CClue **Tempstr = &m_strClue[0]; 
			while(*Tempstr++);
			Tempstr--;
			*Tempstr = ((CLevelThrid*)m_level)->m_pClue_Hook;
			((CLevelThrid*)m_level)->m_HookFlag = 3;
		}
		if(((CLevelThrid*)m_level)->m_KeyFlag == 2)
		{
			CClue **Tempstr = &m_strClue[0]; 
			while(*Tempstr++);
			Tempstr--;
			*Tempstr = ((CLevelThrid*)m_level)->m_pClue_Key;
			((CLevelThrid*)m_level)->m_KeyFlag = 3;
		}
		if(((CLevelThrid*)m_level)->m_clueFlag == 2)	//用掉钩子
		{
			for(int i = 0;i < 5;i++)
			{
				if(m_strClue[i]->m_clueID == ID_LEVEL3_HOOK)
				{
					m_strClue[i] = nullptr;
					break;
				}

			}
			((CLevelThrid*)m_level)->m_clueFlag = 3;
		}
	}
	return ;
}

bool CToolBox:: ReturnMenu(POINT point)
{
	if(point.x >= 8 && point.x <= 147 && point.y >= 80 && point.y <= 215)
		return true;
	return false;
}