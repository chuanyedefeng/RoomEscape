#include "sys.h"
#include "Level.h"
#include "Clue.h"
#include "LevelThrid.h"
#include "LevelFive.h"
#include "LevelSix.h"
#pragma once
class CToolBox
{
public:
	HBITMAP m_hToolBack;		//工具箱背景
	HBITMAP m_htoolBoxWhite;	//亮工具框
	HBITMAP m_htoolBoxBlack;	//亮工具框

	bool m_ToolEnterFlag;		//进入标志
	bool m_ToolQuitFlag;
public:
	CToolBox();
	~CToolBox(void);
public:
	void ToolBoxShow(HDC hMemDC);
	void ToolBoxInit(HINSTANCE hinstance);


	bool IsEnterToolBox(POINT point);
	bool IsQuitTool(POINT point);
	void InOrOutDown(POINT point);
	void InOrOutUp(POINT point);

	void IsCarryClue(POINT point);
	void ChangeLevel(CLevel*& level);
	void ResetToolBox();			//重置工具箱
	void ToolRun();
	bool ReturnMenu(POINT point);
public:
	CLevel* m_level;		
	CClue* m_strClue[5];			//管理线索
	int m_WClueLight;				//点击的工具框
	int m_ClueSelectFlag;
};

