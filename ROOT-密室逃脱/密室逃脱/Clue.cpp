#include "Clue.h"


CClue::CClue(void)
{
	m_bmpClue = 0;
	m_bmpClue2 = 0;
	clue_point.x = 0;        //线索的横坐标为0
	clue_point.y = 0;       //线索的纵坐标为0

	clue_cpoint.x = 0;       //线索的宽度为0
	clue_cpoint.y = 0;		//线索的长度为0
}


CClue::~CClue(void)
{
	DeleteObject(m_bmpClue);
	m_bmpClue = 0;
	DeleteObject(m_bmpClue2);
	m_bmpClue2 = 0;
}
