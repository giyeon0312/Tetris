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

