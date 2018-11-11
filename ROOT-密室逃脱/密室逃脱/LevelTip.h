#pragma once
#include "sys.h"
class CLevelTip
{
public:
	CLevelTip();
	~CLevelTip(void);
public:
	void TipShow(HDC hMemDC);
	void TipInit(HINSTANCE hIns);
	bool TipState()
	{
		if(*m_ntipcount >= 10)
		{
			*m_ntipcount -= 10;
			return true;
		}
		return false;
	}
	void SetTipCount(int *&count)
	{
		m_ntipcount = count;
	}
	int GetTipcount()
	{
		return *m_ntipcount;
	}
public:
	int m_tipflag;
	HBITMAP m_hlevel1_tip[6];
private:
	int *m_ntipcount;
};

