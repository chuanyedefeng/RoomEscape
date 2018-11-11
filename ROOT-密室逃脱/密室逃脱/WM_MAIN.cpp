#include<Windows.h>
#include <iostream>
#include"CGameCtrl.h"
#include "resource.h"
//#include<Gdiplus.h>
using namespace std;

////��GDI+�����ռ�
//using namespace Gdiplus;
////��Ӷ�̬����
//#pragma comment(lib,"gdiplus.lib")

//������Ϣ������
LRESULT CALLBACK WndProc(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam);

PFUN_CREATE_OBJECT CGameCtrl::pfunctrlobject = 0;// ���� ����:: ������ = ֵ
CGameCtrl* Game = NULL;
HINSTANCE hins;

int CALLBACK WinMain(HINSTANCE hInstance,HINSTANCE hPreinstance,LPSTR pCmdLine,int nCmdShow)
{
	////��������
	//ULONG_PTR token ;
	////����GDI+��ʼ�������
	//GdiplusStartupInput gdiplusStartiput;
	////��ʼGDI+
	//::GdiplusStartup(&token,&gdiplusStartiput,NULL);
	hins = hInstance;
	//���ڻ�ˢ��Ҫɾ�������Ե���д�ȽϷ���
	//1.�������
	WNDCLASSEX wnd_feng;
	wnd_feng.cbClsExtra = 0;//�Ƿ�Ҫ�������Ŀռ�
	wnd_feng.cbWndExtra = 0;
	wnd_feng.hCursor = LoadCursor(NULL,IDC_ARROW);;
	wnd_feng.cbSize = sizeof(wnd_feng); // ������Ĵ�С
	wnd_feng.hbrBackground = ::CreateSolidBrush(RGB(0,225,0));//���ڱ�������ɫ
	wnd_feng.hIconSm = LoadIcon(hInstance,MAKEINTRESOURCE(IDI_ICON2));// �������Ͻǵ�ͼ��
	wnd_feng.hInstance = hInstance;// ��ǰʵ��Ӧ�ó���ľ��
	wnd_feng.lpfnWndProc = WndProc; //��Ϣ��������ָ��
	wnd_feng.lpszClassName = "feng";// �����������
	wnd_feng.style = CS_HREDRAW | CS_VREDRAW;// ���ڵ���ʽ
	wnd_feng.lpszMenuName = NULL;//���ڲ˵���
	wnd_feng.hIcon = LoadIcon(hInstance,MAKEINTRESOURCE(IDI_ICON1));
	// 2.ע�ᴰ��
	if(RegisterClassEx(&wnd_feng) == false)
	{
		::MessageBox(NULL,"ע��ʧ��","��ʾ",MB_OK);
		return 0;
	}

	//3.��������
	HWND hWnd = ::CreateWindow("feng","!��_��_��_��!",WS_OVERLAPPEDWINDOW,100,100,1016,600,NULL,NULL,hInstance,NULL);
	if(hWnd == NULL)
	{
		MessageBox(NULL,"����ʧ��","��ʾ" ,MB_OK);
		return 0;
	}
	//4.��ʾ����
	ShowWindow(hWnd,SW_SHOW);
	//5. ��Ϣѭ��
	MSG msg;
	while(GetMessage(&msg,0,0,0))
	{
		TranslateMessage(&msg);//������Ϣ
		DispatchMessage(&msg);// �ַ���Ϣ
	}
	//����GDI+��ͼ
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
				MessageBox(NULL,"����ʧ��","��ʾ",MB_OK);
				DestroyWindow(hWnd);
				PostQuitMessage(0);
			}
			else
			{
				Game = (*CGameCtrl::pfunctrlobject)();   //��������Ķ��󣬲��ø����ָ��ָ������Ķ���
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
