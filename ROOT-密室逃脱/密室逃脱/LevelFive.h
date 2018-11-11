#pragma once
#include "level.h"
#include "Clue_Screen.h"
class CLevelFive :
	public CLevel
{
public:
	CLevelFive(void);
	virtual ~CLevelFive(void);
public:
	virtual void LevelBackInit(HINSTANCE hIns);
	virtual void LevelBackShow(HDC hMemDC) ;

	virtual void LevelClueInit(HINSTANCE hIns);
	virtual void LevelClueShow(HDC hMemDC);

	virtual void LevelRun(POINT point) ;    //ÿ�ؿ�ʼ����
	virtual void LevelDraw(HDC hMemDC) ;   //ÿ�ص��ػ�

	virtual void LevelLButtonUp(POINT point);
	virtual void LevelReset();
	bool IsOK() ;  //��Ļȫ��
	virtual void LevelClueMove();
public:
	CClue_Screen* m_clueScreen;
};

