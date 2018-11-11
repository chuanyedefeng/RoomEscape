#include "Arrow.h"


CArrow::CArrow(void)
{
	m_ArrowBlack = 0;
	m_ArrowWhite = 0;
	Arrow_x = 458;    //箭头的横坐标
	Arrow_y = 290;    // 箭头的纵坐标
	Arrow_up = 0;		//箭头向上移动标志
	Arrow_down = 0;   //箭头向下移动标志
	Arrow_t = 0;	  //箭头的时间
}


CArrow::~CArrow(void)
{
	DeleteObject(m_ArrowBlack);
	DeleteObject(m_ArrowWhite);
	m_ArrowBlack = 0;
	m_ArrowWhite = 0;
}


void CArrow::ArrowInit(HINSTANCE hIns)      //箭头初始化
{
	m_ArrowWhite = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_ArrowWhite));
	m_ArrowBlack =  LoadBitmap(hIns,MAKEINTRESOURCE(IDB_ArrowBlack));
}

void CArrow::ArrowMove()					//箭头移动
{
	Arrow_t++;      // 时间增加   
	if(Arrow_y <= 270 )
	{
		Arrow_up = 0;
		Arrow_down = 1;
		Arrow_t = 1;
	}
	if(Arrow_y >= 290)
	{
		Arrow_up = 1;
		Arrow_down = 0;
		Arrow_t = 1;
	}
	if(Arrow_up == 1)        //向上移动
		Arrow_y = 290- Arrow_t*Arrow_t;
	if(Arrow_down == 1)      // 向下移动
	    Arrow_y ++;

	if(Arrow_y == 280)        //到中间开始减速
		Arrow_t = 0;
}


void CArrow::ArrowShow(HDC hMemDC)      //箭头显示
{
	HDC hTempDC = CreateCompatibleDC(hMemDC);
	SelectObject(hTempDC,m_ArrowWhite);
	BitBlt(hMemDC,458,Arrow_y,120,108,hTempDC,0,0,SRCAND);
	SelectObject(hTempDC,m_ArrowBlack);
	BitBlt(hMemDC,458,Arrow_y,120,108,hTempDC,0,0,SRCPAINT);
	DeleteDC(hTempDC);
}
