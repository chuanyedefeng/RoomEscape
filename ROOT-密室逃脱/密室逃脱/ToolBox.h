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
	HBITMAP m_hToolBack;		//�����䱳��
	HBITMAP m_htoolBoxWhite;	//�����߿�
	HBITMAP m_htoolBoxBlack;	//�����߿�

	bool m_ToolEnterFlag;		//�����־
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
	void ResetToolBox();			//���ù�����
	void ToolRun();
	bool ReturnMenu(POINT point);
public:
	CLevel* m_level;		
	CClue* m_strClue[5];			//��������
	int m_WClueLight;				//����Ĺ��߿�
	int m_ClueSelectFlag;
};

