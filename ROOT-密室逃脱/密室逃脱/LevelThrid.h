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
	virtual void LevelRun(POINT point);    //ÿ�ؿ�ʼ����
	virtual void LevelDraw(HDC hMemDC);   //ÿ�ص��ػ�
	virtual void LevelClueMove();
public:
	virtual void LevelReset();
	
public:
	int m_ThirdFlag;		//��Ǵ˹ص�״̬
	HBITMAP m_hGun[3];
	HBITMAP m_ClueBack;
	int m_KeyFlag;
	int m_HookFlag;
	bool m_returnflag;
	CClue* m_pClue_Hook;
	CClue* m_pClue_Key;
	int m_clueFlag;			//������ǹ����Ƿ��ó�
private:
	int m_keyarr[5];


};

