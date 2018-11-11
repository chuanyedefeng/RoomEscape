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
	void BackInit(HINSTANCE hIns);     //������ʼ��
	void OpenDoorShow(HDC HMemDC,int i);       //��ʾ�򿪵���
	void LightDoorShow(HDC HMemDC,int i);		//��ʾ��������
	void OrgDoorShow(HDC HMemDC);		// ��ʾ��ԭʼ��
	int ChangeDoorFlag(POINT point);
	void ResetDoorFlag(); 
private:
	HBITMAP m_hBack[6][2];

};

