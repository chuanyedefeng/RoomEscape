#pragma once
#include "level.h"
#include "Level3_Hook.h"
#include "Level3_Key.h"
class CLevelThrid :
	public CLevel
{
public:
	CLevelThrid(void);
	virtual ~CLevelThrid(void);

public:
	virtual void LevelBackInit(HINSTANCE hIns);
	virtual void LevelBackShow(HDC hMemDC);
	virtual void LevelClueInit(HINSTANCE hIns);
	virtual void LevelClueShow(HDC hMemDC) ;
	virtual void LevelRun(POINT point);    //每关开始运行
	virtual void LevelDraw(HDC hMemDC);   //每关的重绘
	virtual void LevelClueMove();
public:
	virtual void LevelReset();
	
public:
	int m_ThirdFlag;		//标记此关的状态
	HBITMAP m_hGun[3];
	HBITMAP m_ClueBack;
	int m_KeyFlag;
	int m_HookFlag;
	bool m_returnflag;
	CClue* m_pClue_Hook;
	CClue* m_pClue_Key;
	int m_clueFlag;			//用来标记钩子是否用出
private:
	int m_keyarr[5];


};

