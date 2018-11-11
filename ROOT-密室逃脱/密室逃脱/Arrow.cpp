#include "Arrow.h"


CArrow::CArrow(void)
{
	m_ArrowBlack = 0;
	m_ArrowWhite = 0;
	Arrow_x = 458;    //��ͷ�ĺ�����
	Arrow_y = 290;    // ��ͷ��������
	Arrow_up = 0;		//��ͷ�����ƶ���־
	Arrow_down = 0;   //��ͷ�����ƶ���־
	Arrow_t = 0;	  //��ͷ��ʱ��
}


CArrow::~CArrow(void)
{
	DeleteObject(m_ArrowBlack);
	DeleteObject(m_ArrowWhite);
	m_ArrowBlack = 0;
	m_ArrowWhite = 0;
}


void CArrow::ArrowInit(HINSTANCE hIns)      //��ͷ��ʼ��
{
	m_ArrowWhite = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_ArrowWhite));
	m_ArrowBlack =  LoadBitmap(hIns,MAKEINTRESOURCE(IDB_ArrowBlack));
}

void CArrow::ArrowMove()					//��ͷ�ƶ�
{
	Arrow_t++;      // ʱ������   
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
	if(Arrow_up == 1)        //�����ƶ�
		Arrow_y = 290- Arrow_t*Arrow_t;
	if(Arrow_down == 1)      // �����ƶ�
	    Arrow_y ++;

	if(Arrow_y == 280)        //���м俪ʼ����
		Arrow_t = 0;
}


void CArrow::ArrowShow(HDC hMemDC)      //��ͷ��ʾ
{
	HDC hTempDC = CreateCompatibleDC(hMemDC);
	SelectObject(hTempDC,m_ArrowWhite);
	BitBlt(hMemDC,458,Arrow_y,120,108,hTempDC,0,0,SRCAND);
	SelectObject(hTempDC,m_ArrowBlack);
	BitBlt(hMemDC,458,Arrow_y,120,108,hTempDC,0,0,SRCPAINT);
	DeleteDC(hTempDC);
}
