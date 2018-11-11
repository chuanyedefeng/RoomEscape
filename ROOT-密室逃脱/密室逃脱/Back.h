#pragma once
#include "sys.h"
#include "Arrow.h"
class CBack
{
public:
	HBITMAP m_Door[3];   
	CArrow arrow;
	int doorflag;
public:
	CBack(void);
	~CBack(void);
public:
	void BackInit(HINSTANCE hIns);     //背景初始化
	void OpenDoorShow(HDC HMemDC,int i);       //显示打开的门
	void LightDoorShow(HDC HMemDC,int i);		//显示灯亮的门
	void OrgDoorShow(HDC HMemDC);		// 显示的原始门
	int ChangeDoorFlag(POINT point);
	void ResetDoorFlag(); 
private:
	HBITMAP m_hBack[6][2];

};

