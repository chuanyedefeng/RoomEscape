#pragma once
#include "level.h"
#include "CodesLock.h"
#include "CatEye.h"
class CLevelFirst :
	public CLevel
{
private:
	int first_flag;            // first_flag  = 2 密码锁，first_flag = 0 进入第一关，  first_flag  = 1猫眼
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

	virtual void Return();                     //返回主界面

	virtual void LevelReset();
};

