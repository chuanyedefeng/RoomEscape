#pragma once
#include "clue.h"
//�����и����ԣ�����һ��ʹ��
class CCodesLock :
	public CClue
{

public:
	CCodesLock(void);
	~CCodesLock(void);
public:
	virtual void ClueShow(HDC hMemDC,int code[5]) ;       //��������ʾ
	virtual void ClueInit(HINSTANCE hIns) ;				 //��������ʼ��
private:
	HBITMAP m_BmpCodes[10];
	int m_CodeFlag[5];
};


