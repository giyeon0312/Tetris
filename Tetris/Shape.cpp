#include "Shape.h"

CShape::CShape()
{
	//memset(m_cShape, 0, MAX_SHAPE_SIZE * MAX_SHAPE_SIZE);
	for (int i = 0; i < MAX_SHAPE_SIZE; ++i)
	{
		for (int j = 0; j < MAX_SHAPE_SIZE; ++j)
		{
			m_cShape[i][j] = 1;
		}
	}
}

CShape::~CShape()
{

}

bool CShape::Init()
{
	return true;
}

void CShape::Render()
{
}
