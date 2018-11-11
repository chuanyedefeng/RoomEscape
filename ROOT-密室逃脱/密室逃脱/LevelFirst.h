#pragma once
#include "level.h"
#include "CodesLock.h"
#include "CatEye.h"
class CLevelFirst :
	public CLevel
{
private:
	int first_flag;            // first_flag  = 2 ��������first_flag = 0 �����һ�أ�  first_flag  = 1è��
	int first_code[5];
public:
	CLevelFirst(void);
	virtual ~CLevelFirst(void);
public:
	virtual void LevelBackInit(HINSTANCE hIns);
	virtual void LevelBackShow(HDC hMemDC);

	virtual void LevelClueInit(HINSTANCE hIns);
	virtual void LevelClueShow(HDC hMemDC);

	virtual void LevelRun(POINT point) ;
	virtual void LevelDraw(HDC hMemDC);

	virtual void Return();                     //����������

	virtual void LevelReset();
};

