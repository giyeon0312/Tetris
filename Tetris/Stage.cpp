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
			if (pCurShape->GetBlock(j, i) == '0')
			{
				// 피봇이 맨 아래 왼쪽이므로 i=0일 때 가장 위다.
				m_Stage[tPos.y - (3 - i)][tPos.x + j] = '0';
			
				// 현재 줄이 다 차있는지 체크하고 삭제한다.
				bool bLine = true;
				for (int k = 0; k < STAGE_WIDTH; ++k)
				{
					if (m_Stage[tPos.y - (3 - i)][k] != '0')
					{
						bLine = false;
						break;
					}
				}
				// 위의 블럭들을 모두 한칸씩 내려줘서 지운다.
				if (bLine)
				{
					for (int k = tPos.y - (3 - i); k > 0; --k)
					{
						for (int l = 0; l < STAGE_WIDTH; ++l)
						{
							m_Stage[k][l] = m_Stage[k - 1][l];
						}
					}
				}
			}	
		}
	}
}

bool CStage::CheckBlock(int x, int y)
{
	// 바닥에 닿았을 경우 true 반환
	if (y >= STAGE_HEIGHT)
		return true;
	// 좌우에 닿았을 경우도 true 반환
	else if (x < 0 || x >= STAGE_WIDTH)
		return true;

	return m_Stage[y][x] == '0';
}

bool CStage::Init()
{
	//memset(m_Stage, 0, STAGE_WIDTH * STAGE_HEIGHT);
	for (int i = 0; i < STAGE_HEIGHT; ++i)
	{
		for (int j = 0; j < STAGE_WIDTH; ++j)
		{
			m_Stage[i][j] = '1';
		}
	}
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
			else
			{
				if (m_Stage[i][j - 1] == '1')
					cout << "  ";
				else
					cout << "□";
			}
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