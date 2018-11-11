#pragma once
#include "sys.h"
class CClue
{
public:
	HBITMAP m_bmpClue;
	HBITMAP m_bmpClue2;
	POINT clue_point;    //线索的坐标
	POINT clue_cpoint;   //线索的长度和宽度
	int m_clueID;
public:
	CClue(void);
	virtual ~CClue(void);     //虚析构
public:
	virtual void ClueShow(HDC hMemDC)
	{}
	virtual void ClueInit(HINSTANCE hIns){};

	virtual void ClueMove(){};

	virtual void ClueReset(){};

	virtual void ToolClueShow(HDC hMemDC,int i){};
	bool IsGetClue(int x,int y)
	{
		//判断光标的位置在不在线索的矩形框中
		if( x >= clue_point.x &&  x <= clue_point.x + clue_cpoint.x
			&&y >= clue_point.y &&  y <= clue_point.y + clue_cpoint.y)  
			return true;
		else
			return false;
	}
};

