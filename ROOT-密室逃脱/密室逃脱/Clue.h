#pragma once
#include "sys.h"
class CClue
{
public:
	HBITMAP m_bmpClue;
	HBITMAP m_bmpClue2;
	POINT clue_point;    //����������
	POINT clue_cpoint;   //�����ĳ��ȺͿ��
	int m_clueID;
public:
	CClue(void);
	virtual ~CClue(void);     //������
public:
	virtual void ClueShow(HDC hMemDC)
	{}
	virtual void ClueInit(HINSTANCE hIns){};

	virtual void ClueMove(){};

	virtual void ClueReset(){};

	virtual void ToolClueShow(HDC hMemDC,int i){};
	bool IsGetClue(int x,int y)
	{
		//�жϹ���λ���ڲ��������ľ��ο���
		if( x >= clue_point.x &&  x <= clue_point.x + clue_cpoint.x
			&&y >= clue_point.y &&  y <= clue_point.y + clue_cpoint.y)  
			return true;
		else
			return false;
	}
};

