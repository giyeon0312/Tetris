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
		// �ܼ� â�� ����� ��ǥ�� ������ �Ŀ� ����Ѵ�.
		// 4*4�� �Ǻ��� �� ���� �Ʒ��̹Ƿ� -3,-2,-1,-0��ŭ ���ٰ� �׸��� �����̴�.
		int iYindex = m_tPos.y - (3 - i);
		if (iYindex < 0) continue;

		CEngine::GetInstance()->SetConsolePos(m_tPos.x, iYindex);

		for (int j = 0; j < MAX_SHAPE_SIZE; ++j)
		{
			if (m_tPos.x + j >= STAGE_WIDTH)
				continue;

			if (m_cShape[i][j] == '0')
				cout << "��";
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
		// �ܼ� â�� ����� ��ǥ�� ������ �Ŀ� ����Ѵ�.
		// 4*4�� �Ǻ��� �� ���� �Ʒ��̹Ƿ� -3,-2,-1,-0��ŭ ���ٰ� �׸��� �����̴�.
		int iYindex = m_tPos.y - (3 - i);
		if (iYindex < 0) continue;

		CEngine::GetInstance()->SetConsolePos(m_tPos.x, iYindex);

		for (int j = 0; j < MAX_SHAPE_SIZE; ++j)
		{
			if (m_cShape[i][j] == '0')
				cout << "��";
			else
				cout << "  ";
		}
		cout << '\n';
	}
}

/// <summary>
/// �� ĭ�� ���� ������ ��ġ�� ������ ��Ҵ��� üũ�Ѵ�.
/// </summary>
/// <returns>�ٴ��̳� �ٸ� ������ ������ true, ���� �� ������� false</returns>
bool CShape::MoveDown()
{
	// ������ ��ȸ�ϸ� �ٴ��̳� �ٸ� ������ ��Ҵ��� üũ
	CStage* pStage = CStageManager::GetInstance()->GetCurrentStage();

	for (int i = 0; i < 4; ++i)
	{
		for (int j = 0; j < 4; ++j)
		{
			// 4*4 ����� i,jĭ�� ������ ������ �Ʒ��� �ٸ� ������ ������ ���� ���̴�.
			// y���� 3-i ĭ�� ������µ� �ٷ� �� �Ʒ�ĭ�� üũ�ؾ��ϹǷ� 2-iĭ�� Ž���Ѵ�.
			if ((m_cShape[i][j] == '0')
				&& pStage->CheckBlock(m_tPos.x + j, m_tPos.y - (3 - i) + 1))
			{
				// �ٴڿ� ���� �� ���� ������ ���� �κ��� �ϳ��� ��ǥ�� 0���� �۴ٸ� �����Ѵ�.
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

