#pragma once
#include "level.h"
class CLevelSecond :
	public CLevel
{
public:
	CLevelSecond(void);
	virtual ~CLevelSecond(void);
public:
	virtual void LevelBackInit(HINSTANCE hIns) ;
	virtual void LevelBackShow(HDC hMemDC);

	virtual void LevelClueInit(HINSTANCE hIns);
	virtual void LevelClueShow(HDC hMemDC);

	virtual void LevelRun(POINT point)  ;    //ÿ�ؿ�ʼ����
	virtual void LevelDraw(HDC hMemDC) ;   //ÿ�ص��ػ�

	virtual void LevelClueMove();

	virtual void LevelReset();
private:
	HBITMAP m_hLight[4][5];		
	HBITMAP m_Clue_B;
	HBITMAP m_Clue_W;
	POINT m_cluepoint;

	int m_secondflag;			//�ڶ���״̬�ı��
		
	int m_arrClue[4][5] ;
	int m_clueflag;
	
};
