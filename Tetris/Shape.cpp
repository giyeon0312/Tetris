#include "Shape.h"
#include "Engine.h"

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
			if (m_cShape[i][j] == '0')
				cout << "��";
			else
				cout << "  ";
		}
		cout << '\n';
	}
}

void CShape::MoveDown()
{
	if (m_tPos.y == STAGE_HEIGHT - 1)
		return;

	m_tPos.y++;
}

void CShape::MoveRight()
{
	if ((m_tPos.x + m_nWidth) >= STAGE_WIDTH)
		return;

	m_tPos.x++;
}

void CShape::MoveLeft()
{
	if (m_tPos.x == 0)
		return;

	m_tPos.x--;
}

