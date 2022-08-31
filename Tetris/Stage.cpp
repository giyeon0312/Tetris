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
			// �Ǻ��� �� �Ʒ� �����̹Ƿ� i=0�� �� ���� ����.
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
				cout << "��";
			else if (i == STAGE_HEIGHT)
				cout << "��";
			else if (m_Stage[i][j] == '0')
				cout << "��";
			else
				cout << "  ";
		}
		cout << '\n';
	}

	// ���� ���� ���� �� �׸� ĭ
	for (int i = 0; i < 7; ++i)
	{
		CEngine::GetInstance()->SetConsolePos(17, i);
		cout << "��";
	}

	for (int i = 0; i < 6; ++i)
	{
		CEngine::GetInstance()->SetConsolePos(11 + i, 6);
		cout << "��";
	}
}