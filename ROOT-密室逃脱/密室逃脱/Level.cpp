#include "Level.h"


CLevel::CLevel(void)
{
	m_Flag = 0 ;           // 那一关的标志
	m_bmpBack = 0;   // 哪一关的背景图
	m_ptip = new CLevelTip;
	m_levelTemp = 0;
	m_tipflag = false;
	
}


CLevel::~CLevel(void)
{
	DeleteObject(m_bmpBack);
	list<CClue*> ::iterator ite = m_clue.begin();
	while( ite != m_clue.end() )
	{
		delete (*ite);
		ite++;
	}
	delete m_ptip;
	m_ptip = nullptr;
}
