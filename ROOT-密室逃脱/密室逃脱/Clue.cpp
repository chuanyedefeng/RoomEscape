#include "Clue.h"


CClue::CClue(void)
{
	m_bmpClue = 0;
	m_bmpClue2 = 0;
	clue_point.x = 0;        //�����ĺ�����Ϊ0
	clue_point.y = 0;       //������������Ϊ0

	clue_cpoint.x = 0;       //�����Ŀ��Ϊ0
	clue_cpoint.y = 0;		//�����ĳ���Ϊ0
}


CClue::~CClue(void)
{
	DeleteObject(m_bmpClue);
	m_bmpClue = 0;
	DeleteObject(m_bmpClue2);
	m_bmpClue2 = 0;
}
