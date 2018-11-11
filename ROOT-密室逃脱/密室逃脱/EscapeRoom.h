#pragma once
#include "cgamectrl.h"
#include "Level.h"
#include "LevelFirst.h"
#include "Back.h"
#include <queue>
#include <list>
using namespace std;
#include "ToolBox.h"
#include "LevelSecond.h"
#include "LevelThrid.h"
#include "LevelFour.h"
#include "LevelFive.h"
#include "LevelSix.h"
#include "GameMenu.h"
//��������ͷ�ļ��Ϳ�
#include <mmsystem.h>
#pragma comment(lib, "WINMM.LIB")

class CEscapeRoom :
	public CGameCtrl
{
	public:
	_DECLEAR_()

public:
	CEscapeRoom(void);
	~CEscapeRoom(void);
public:
	virtual void OnCreatGame();                                       
	virtual void OnGameRun(WPARAM n_TimerID);
	virtual void OnGameDraw();
	virtual void OnLButtonDown(POINT point);
	virtual void OnLbuttonUp(POINT point);
	virtual void OnGameQuit();
public:
	int m_wlevel;                    //��־   ��һ��
	HDC dc;						 	//����DC
	HDC hMemDC ;				// ������DC
	HBITMAP hBitmap;			//������λͼ
	HBITMAP m_hmpend;
public:
	list<CLevel*> m_lstlevel;       //����ѡ��
	CLevel* m_level;					//��¼��ǰ��
	CBack back;                    //��������
	CToolBox m_tool;
public:
	CGameMenu m_menu;
	bool m_bflagMenutoLevel;
	int m_isvertory;

};

