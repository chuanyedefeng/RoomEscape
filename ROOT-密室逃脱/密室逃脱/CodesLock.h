#pragma once
#include "clue.h"
//不具有复用性，仅第一关使用
class CCodesLock :
	public CClue
{

public:
	CCodesLock(void);
	~CCodesLock(void);
public:
	virtual void ClueShow(HDC hMemDC,int code[5]) ;       //密码锁显示
	virtual void ClueInit(HINSTANCE hIns) ;				 //密码锁初始化
private:
	HBITMAP m_BmpCodes[10];
	int m_CodeFlag[5];
};


