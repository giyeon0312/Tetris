#include "Shape.h"
#include "Engine.h"
#include "Stage.h"
#include "StageManager.h"

CShape::CShape()
{
	//memset(m_cShape, 0, MAX_SHAPE_SIZE * MAX_SHAPE_SIZE);
	for (int i = 0; i < MAX_SHAPE_SIZE; ++i)
	{
		for (int j = 0; j < MAX_SHAPE_SIZE; ++j)
		{
			m_cShape[i][j] = '1';
		}
	}

	m_nWidth = 0;
	m_iDir = RD_UP;
}

CShape::~CShape()
{

}

bool CShape::Init()
{
	m_tPivot.x = 0;
	m_tPivot.y = 3;

	return true;
}

void CShape::Rotation()
{
}

void CShape::Render()
{
	for (int i = 0; i < MAX_SHAPE_SIZE; ++i)
	{
		// 콘솔 창에 출력할 좌표를 설정한 후에 출력한다.
		// 4*4의 피봇이 맨 왼쪽 아래이므로 -3,-2,-1,-0만큼 갔다가 그리는 순서이다.
		int iYindex = m_tPos.y - (3 - i);
		if (iYindex < 0) continue;

		CEngine::GetInstance()->SetConsolePos(m_tPos.x, iYindex);

		for (int j = 0; j < MAX_SHAPE_SIZE; ++j)
		{
			if (m_tPos.x + j >= STAGE_WIDTH)
				continue;

			if (m_cShape[i][j] == '0')
				cout << "□";
			else
				cout << "  ";
		}
		cout << '\n';
	}
}

void CShape::RenderNext()
{
	for (int i = 0; i < MAX_SHAPE_SIZE; ++i)
	{
		// 콘솔 창에 출력할 좌표를 설정한 후에 출력한다.
		// 4*4의 피봇이 맨 왼쪽 아래이므로 -3,-2,-1,-0만큼 갔다가 그리는 순서이다.
		int iYindex = m_tPos.y - (3 - i);
		if (iYindex < 0) continue;

		CEngine::GetInstance()->SetConsolePos(m_tPos.x, iYindex);

		for (int j = 0; j < MAX_SHAPE_SIZE; ++j)
		{
			if (m_cShape[i][j] == '0')
				cout << "□";
			else
				cout << "  ";
		}
		cout << '\n';
	}
}

/// <summary>
/// 한 칸씩 현재 도형의 위치를 내리며 닿았는지 체크한다.
/// </summary>
/// <returns>바닥이나 다른 도형에 닿으면 true, 아직 안 닿았으면 false</returns>
bool CShape::MoveDown()
{
	// 도형을 순회하며 바닥이나 다른 도형에 닿았는지 체크
	CStage* pStage = CStageManager::GetInstance()->GetCurrentStage();

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			// 4*4 모양의 i,j칸에 도형이 있으며 아래에 다른 도형이 있으며 닿은 것이다.
			// y에서 3-i 칸을 빼줬었는데 바로 그 아래칸을 체크해야하므로 2-i칸을 탐색한다.
			if ((m_cShape[i][j] == '0')
				&& pStage->CheckBlock(m_tPos.x + j, m_tPos.y - (3 - i) + 1))
			{
				// 바닥에 닿은 후 현재 도형의 블럭인 부분이 하나라도 좌표가 0보다 작다면 종료한다.
				for(int  k =0;k< MAX_SHAPE_SIZE; ++k)
				{
					for (int l = 0; l < MAX_SHAPE_SIZE; ++l)
					{
						if (m_cShape[k][l] == '0')
						{
							if (m_tPos.y - (3 - k) < 0)
								CEngine::GetInstance()->End();
							break;
						}
					}
				}
				return true;
			}
		}
	}

	m_tPos.y++;

	return false;
}

void CShape::MoveRight()
{
	if ((m_tPos.x + m_nWidth) >= STAGE_WIDTH)
		return;

	CStage* pStage = CStageManager::GetInstance()->GetCurrentStage();

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (m_cShape[i][j] == '0' && pStage->CheckBlock(m_tPos.x + j - 1, m_tPos.y - (3 - i)))
			//if (m_cShape[i][j] == '0' && pStage->CheckBlock(m_tPos.x + j, m_tPos.y - (3 - i)))
				return;
		}
	}

	m_tPos.x++;
}

void CShape::MoveLeft()
{
	if (m_tPos.x == 0)
		return;

	CStage* pStage = CStageManager::GetInstance()->GetCurrentStage();

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			if (m_cShape[i][j] == '0' && pStage->CheckBlock(m_tPos.x + j - 1, m_tPos.y - (3 - i)))
				return;
		}
	}

	m_tPos.x--;
}

