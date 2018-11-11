#pragma once
#include "sys.h"
class CArrow
{
public:
	HBITMAP m_ArrowBlack;			 //��ɫ��ͷ
	HBITMAP m_ArrowWhite;			 //��ɫ��ͷ
	double Arrow_x;                  //��ͷ�ĺ�����
	double Arrow_y;                  //��ͷ��������
	int Arrow_t;		             //��ͷ���ƶ�ʱ��
	int Arrow_up;                    //��ͷ�����ƶ���־
	int Arrow_down;                  //��ͷ�����ƶ���־
public:
	CArrow(void);
	~CArrow(void);
public:
	void ArrowShow(HDC hMemDC);         //��ͷ��ʾ
	void ArrowMove();					//��ͷ�ƶ�
	void ArrowInit(HINSTANCE hIns);     //��ͷ��ʼ��
};

