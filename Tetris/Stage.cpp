#include "Stage.h"
#include "Engine.h"
#include "Shape.h"

CStage::CStage()
{
	m_nSpeed = 10;
}

CStage::~CStage()
{
}

void CStage::AddBlock(CShape* pCurShape, const POSITION& tPos)
{
	for (int i = 0; i < MAX_SHAPE_SIZE; i++)
	{
		for (int j = 0; j < MAX_SHAPE_SIZE; j++)
		{
			// 피봇이 맨 아래 왼쪽이므로 i=0일 때 가장 위다.
			if (pCurShape->GetBlock(j,i) == '0')
				m_Stage[tPos.y - (3 - i)][tPos.x + j] = '0';
		}
	}
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
				cout << "■";
			else if (i == STAGE_HEIGHT)
				cout << "■";
			else if (m_Stage[i][j] == '0')
				cout << "□";
			else
				cout << "  ";
		}
		cout << '\n';
	}

	// 다음 도형 보여 줄 네모 칸
	for (int i = 0; i < 7; ++i)
	{
		CEngine::GetInstance()->SetConsolePos(17, i);
		cout << "■";
	}

	for (int i = 0; i < 6; ++i)
	{
		CEngine::GetInstance()->SetConsolePos(11 + i, 6);
		cout << "■";
	}
}