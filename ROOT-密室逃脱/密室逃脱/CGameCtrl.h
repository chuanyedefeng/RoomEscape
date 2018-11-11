#pragma once

#define _DECLEAR_()  static CGameCtrl* CreatObject();

#define _IMPLEMENT_(ThisClass)  	\
	CGameCtrl* ThisClass::CreatObject()\
	{\
		return  new ThisClass;\
	}\
	Init init##ThisClass(&ThisClass::CreatObject);

#ifndef _CGAMECTRL_H
#define _CGAMECTRL_H
#include<Windows.h>
class CGameCtrl;//Ç°ÏîÉùÃ÷
typedef CGameCtrl* (*PFUN_CREATE_OBJECT)();
class CGameCtrl 
{
public:
	static PFUN_CREATE_OBJECT pfunctrlobject;
protected:
	HINSTANCE m_hIn;
	HWND  hWnd_Main;
public :
	CGameCtrl ()
	{
		m_hIn = 0;
		hWnd_Main = 0;
	}
	virtual ~CGameCtrl ()
	{
	
	}
	virtual void OnCreatGame()
	{
	
	}
	virtual void SetHandle(HINSTANCE hinstance,	HWND  hWnd)
	{
		m_hIn = hinstance;
		hWnd_Main = hWnd;
	}
	virtual void OnGameRun(WPARAM n_TimerID)
	{
		
	}
	virtual void OnGameDraw()
	{
	
	}
	virtual void OnGameKeyDown(WPARAM onkey)
	{
		
	}
	virtual void OnGameKeyUp(WPARAM waparam)
	{
	
	}
	virtual void OnGameMouseMove(POINT point)
	{
	
	}

	virtual void OnLButtonDown(POINT point)
	{
	
	}
	virtual void OnLbuttonUp(POINT point)
	{
	
	}
	virtual void OnGameQuit()
	{
		
	}
};
class Init
{
public:
	Init(PFUN_CREATE_OBJECT pfun)
	{
		CGameCtrl::pfunctrlobject = pfun;
	}
};

#endif
