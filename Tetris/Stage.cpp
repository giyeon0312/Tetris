#include "Stage.h"

CStage::CStage()
{
}

CStage::~CStage()
{
}

bool CStage::Init()
{
	memset(m_Stage, 0, STAGE_WIDTH * STAGE_HEIGHT);

	return true;
}


void CStage::Render()
{
	for (int i = 0; i < STAGE_HEIGHT + 1; ++i)
	{
		for (int j = 0; j < STAGE_WIDTH + 2; ++j)
		{
			if (j == 0 || j == STAGE_WIDTH + 1)
				cout << "��";
			else if (i == STAGE_HEIGHT)
				cout << "��";
			else
				cout << "  ";
		}
		cout << '\n';
	}
}