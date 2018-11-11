#pragma once
#include "sys.h"
#include "Clue.h"
#include "LevelTip.h"
class CLevel
{
public:
	int m_Flag;             // ÿһ�صı�־     m_flag = -m_flag  ͨ����ǰ��      m_flag = n  �����n��
	HBITMAP m_bmpBack;     // ��һ�صı���ͼ
	list<CClue*> m_clue;   //����������
	CLevelTip* m_ptip;
	int m_levelTemp;
	bool m_tipflag;
public:
	CLevel(void);
	virtual ~CLevel(void);

public:
	virtual void LevelBackInit(HINSTANCE hIns) = 0;
	virtual void LevelBackShow(HDC hMemDC) = 0;

	virtual void LevelClueInit(HINSTANCE hIns) = 0;
	virtual void LevelClueShow(HDC hMemDC) = 0;

	virtual void LevelRun(POINT point)   = 0 ;    //ÿ�ؿ�ʼ����
	virtual void LevelDraw(HDC hMemDC)  = 0;   //ÿ�ص��ػ�

	virtual void LevelLButtonUp(POINT point){};
	virtual void LevelReset(){};
	bool IsPassLevel()          //�Ƿ�ͨ��
	{
		if(m_Flag < 0)
			return true;
		else
			return false;
	}
	void GetTipState()
	{
		
	}
	virtual void Return()
	{
	
	}
	virtual void LevelClueMove(){};
};

