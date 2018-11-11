#pragma once
#include<Windows.h>
#include<list>
#include <Gdiplus.h>
#include "resource.h"

////打开GDI+命名空间
//using namespace Gdiplus;
////添加动态链库
//#pragma comment(lib,"gdiplus.lib")
using namespace std;

//定时器
#define ARROWMOVE			  0
#define LEVEL2_CLUE_MOVE	  1
#define LEVEL3_KEY_MOVE       2
#define LEVEL3_HOOK_MOVE      3
#define TOOLBOX_RUN           4
#define LEVEL5_KEY_MOVE       5
#define LEVEL6_KEY_MOVE       6
#define MENU_SOUND			  7
//线索ID
#define ID_LEVEL2_CODELOCK	21
#define ID_LEVEL3_KEY		31
#define ID_LEVEL3_HOOK		32
#define ID_LEVEL5_KEY       51
#define ID_LEVEL6_KET       61

//获得线索时的标志
#define LEVEL3_GET_KEY      33
#define LEVEL3_GET_HOOK     34
#define Level5_GET_KEY      52
#define LEVEL6_GET_KEY      62
#define LEVEL_TIP           10

#define MENU_STATE          11

//定义存档包的类型
typedef struct Save_Game
{
	bool m_bLevelFlag[6]; //过了几关
	int m_Level;
	int m_wlevel;                    //标志   哪一关					 	//窗口DC
};

