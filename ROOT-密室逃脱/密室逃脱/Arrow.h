#pragma once
#include "sys.h"
class CArrow
{
public:
	HBITMAP m_ArrowBlack;			 //黑色箭头
	HBITMAP m_ArrowWhite;			 //白色箭头
	double Arrow_x;                  //箭头的横坐标
	double Arrow_y;                  //箭头的纵坐标
	int Arrow_t;		             //箭头的移动时间
	int Arrow_up;                    //箭头向上移动标志
	int Arrow_down;                  //箭头向下移动标志
public:
	CArrow(void);
	~CArrow(void);
public:
	void ArrowShow(HDC hMemDC);         //箭头显示
	void ArrowMove();					//箭头移动
	void ArrowInit(HINSTANCE hIns);     //箭头初始化
};

