#include "Back.h"


CBack::CBack(void)
{
	doorflag  = 0;
	for(int i = 0;i < 3;i++)
	{
		m_Door[i] = 0;
	}
	for(int i = 0;i < 6;i++)
	{
		for(int j = 0;j < 2;j++)
		{
			m_hBack[i][j] = 0;
		}
	}



}

CBack::~CBack(void)
{
	for(int i = 0; i < 3; i++)
	{
		if(m_Door[i])
		{
			DeleteObject(m_Door[i]);
			m_Door[i] = 0;
		}
	}
	for(int i = 0;i < 6;i++)
	{
		for(int j = 0;j < 2;j++)
		{
			if(m_hBack[i][j])
			{
				DeleteObject(m_hBack[i][j]);
				m_hBack[i][j] = 0;
			}
		}
	}
}

void CBack::BackInit(HINSTANCE hIns)
{

	m_Door[0] = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_BACKORL));    //最开始的门
	m_Door[1] = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_BACKLIGHT));  //紧急通道亮的门
	m_Door[2] = LoadBitmap(hIns,MAKEINTRESOURCE(IDB_DoorOpen));   //打开的门

	m_hBack[0][0] = LoadBitmap(hIns,MAKEINTRESOURCE(Level1_Light));
	m_hBack[0][1] = LoadBitmap(hIns,MAKEINTRESOURCE(Level1_END_Back));	

	m_hBack[1][0] = LoadBitmap(hIns,MAKEINTRESOURCE(Level2_Light));
	m_hBack[1][1] = LoadBitmap(hIns,MAKEINTRESOURCE(Level2_END_Back));

	m_hBack[2][0] = LoadBitmap(hIns,MAKEINTRESOURCE(Level3_Light));
	m_hBack[2][1] = LoadBitmap(hIns,MAKEINTRESOURCE(Level3_END_Back));

	m_hBack[3][0] = LoadBitmap(hIns,MAKEINTRESOURCE(Level4_Light));
	m_hBack[3][1] = LoadBitmap(hIns,MAKEINTRESOURCE(Level4_END_Back));

	m_hBack[4][0] = LoadBitmap(hIns,MAKEINTRESOURCE(Level5_Light));
	m_hBack[4][1] = LoadBitmap(hIns,MAKEINTRESOURCE(Level5_END_Back));

	m_hBack[5][0] = LoadBitmap(hIns,MAKEINTRESOURCE(Level6_Light));
	m_hBack[5][1] = LoadBitmap(hIns,MAKEINTRESOURCE(Level6_END_Back));  
}

void CBack::OrgDoorShow(HDC HMemDC)
{
	HDC hTempDC = CreateCompatibleDC(HMemDC);
	SelectObject(hTempDC,m_Door[0]);
	BitBlt(HMemDC,0,0,1000,563,hTempDC,0,0,SRCCOPY);
	DeleteDC(hTempDC);
}

void CBack::LightDoorShow(HDC HMemDC,int i)
{
	HDC hTempDC = CreateCompatibleDC(HMemDC);
	SelectObject(hTempDC,m_hBack[i-1][0]);
	BitBlt(HMemDC,0,0,1000,563,hTempDC,0,0,SRCCOPY);
	DeleteDC(hTempDC);
} 


void CBack::OpenDoorShow(HDC HMemDC,int i)
{
	HDC hTempDC = CreateCompatibleDC(HMemDC);
	SelectObject(hTempDC,m_hBack[i-1][1]);
	BitBlt(HMemDC,0,0,1000,563,hTempDC,0,0,SRCCOPY);
	DeleteDC(hTempDC);
}

int CBack::ChangeDoorFlag(POINT point)
{
	if(point.x >= 426 && point.x <= 593 && point.y >= 133 && point.y <= 487)
	this->doorflag ++;
	return doorflag;
}

void CBack::ResetDoorFlag()
{
	doorflag = 0;
}
