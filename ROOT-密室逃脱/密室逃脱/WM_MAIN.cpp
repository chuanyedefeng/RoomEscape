#include<Windows.h>
#include <iostream>
#include"CGameCtrl.h"
#include "resource.h"
//#include<Gdiplus.h>
using namespace std;

////打开GDI+命名空间
//using namespace Gdiplus;
////添加动态链库
//#pragma comment(lib,"gdiplus.lib")

//窗口消息处理函数
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

PFUN_CREATE_OBJECT CGameCtrl::pfunctrlobject = 0;// 类型 类名:: 变量名 = 值
CGameCtrl* Game = NULL;
HINSTANCE hins;

int CALLBACK WinMain(HINSTANCE hInstance,HINSTANCE hPreinstance,LPSTR pCmdLine,int nCmdShow)
{
	////定义令牌
	//ULONG_PTR token ;
	////定义GDI+开始输入变量
	//GdiplusStartupInput gdiplusStartiput;
	////开始GDI+
	//::GdiplusStartup(&token,&gdiplusStartiput,NULL);
	hins = hInstance;
	//由于画刷需要删除，所以单独写比较方便
	//1.窗口设计
	WNDCLASSEX wnd_feng;
	wnd_feng.cbClsExtra = 0;//是否要分配额外的空间
	wnd_feng.cbWndExtra = 0;
	wnd_feng.hCursor = LoadCursor(NULL,IDC_ARROW);;
	wnd_feng.cbSize = sizeof(wnd_feng); // 窗口类的大小
	wnd_feng.hbrBackground = ::CreateSolidBrush(RGB(0,225,0));//窗口背景的颜色
	wnd_feng.hIconSm = LoadIcon(hInstance,MAKEINTRESOURCE(IDI_ICON2));// 窗口左上角的图标
	wnd_feng.hInstance = hInstance;// 当前实例应用程序的句柄
	wnd_feng.lpfnWndProc = WndProc; //消息处理函数的指针
	wnd_feng.lpszClassName = "feng";// 窗口类的名字
	wnd_feng.style = CS_HREDRAW | CS_VREDRAW;// 窗口的样式
	wnd_feng.lpszMenuName = NULL;//窗口菜单名
	wnd_feng.hIcon = LoadIcon(hInstance,MAKEINTRESOURCE(IDI_ICON1));
	// 2.注册窗口
	if(RegisterClassEx(&wnd_feng) == false)
	{
		::MessageBox(NULL,"注册失败","提示",MB_OK);
		return 0;
	}

	//3.创建窗口
	HWND hWnd = ::CreateWindow("feng","!密_室_逃_脱!",WS_OVERLAPPEDWINDOW,100,100,1016,600,NULL,NULL,hInstance,NULL);
	if(hWnd == NULL)
	{
		MessageBox(NULL,"创建失败","提示" ,MB_OK);
		return 0;
	}
	//4.显示窗口
	ShowWindow(hWnd,SW_SHOW);
	//5. 消息循环
	MSG msg;
	while(GetMessage(&msg,0,0,0))
	{
		TranslateMessage(&msg);//翻译消息
		DispatchMessage(&msg);// 分发消息
	}
	//结束GDI+绘图
	//::GdiplusShutdown(token);
	return 0;
}
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	switch(uMsg)
	{
		case WM_CREATE:
			if(CGameCtrl::pfunctrlobject == NULL)
			{
				MessageBox(NULL,"创建失败","提示",MB_OK);
				DestroyWindow(hWnd);
				PostQuitMessage(0);
			}
			else
			{
				Game = (*CGameCtrl::pfunctrlobject)();   //创建子类的对象，并用父类的指针指向子类的对象
				Game->SetHandle(hins,hWnd);
				Game->OnCreatGame();
			}
		break;
		case WM_PAINT:
			if(Game != NULL)
			{
				Game->OnGameDraw();
			}
			break;
		case WM_KEYDOWN:
			if(Game != NULL)
			{
				Game->OnGameKeyDown(wParam);
			}
			break;
		case WM_KEYUP:
			if(Game != NULL)
			{
				Game->OnGameKeyUp(wParam);
			}
			break;
		case WM_LBUTTONDOWN:
			if(Game != NULL)
			{
				POINT point;
				point.x = LOWORD(lParam);
				point.y = HIWORD(lParam);
				Game->OnLButtonDown(point);
			}
			break;
		case WM_LBUTTONUP:
			if(Game != NULL)
			{
				POINT point;
				point.x = LOWORD(lParam);
				point.y = HIWORD(lParam);
				Game->OnLbuttonUp(point);
			}
			break;
		case WM_MOUSEMOVE:
			if(Game != NULL)
			{
				POINT point;
				point.x = LOWORD(lParam);
				point.y = HIWORD(lParam);
				Game->OnGameMouseMove(point);
			}
			break;
		case WM_TIMER:
			if(Game != NULL)
			{
				Game->OnGameRun(wParam);
			}
			break;
		case WM_CLOSE:
			{
				Game->OnGameQuit();
				delete Game;
				Game = NULL;
				PostQuitMessage(0);
			}
			break;

	}
	return DefWindowProc( hWnd,  uMsg,  wParam,  lParam);
}
