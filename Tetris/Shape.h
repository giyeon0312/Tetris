#pragma once
#include "StdAfx.h"

class CShape
{
public:
	CShape();
	~CShape();

protected:
	char		m_cShape[MAX_SHAPE_SIZE][MAX_SHAPE_SIZE];
	POSITION	m_tPos;
	POSITION	m_tPivot;			// ȸ�� ��
	int			m_nWidth;			// �Ǻ����κ��� ���� ����

public:
	void SetPosition(int x, int y)
	{
		//m_tPos = POSITION(x, y);
		m_tPos.x = x;
		m_tPos.y = y;
	}

	void SetPosition(const POSITION& tPos)
	{
		m_tPos = tPos;
	}

	POSITION GetPosition()	const
	{
		return m_tPos;
	}

	POSITION GetPivot()	const
	{
		return m_tPivot;
	}

	const char GetBlock(int x,int y) const
	{
		return m_cShape[y][x];
	}

public:
	virtual bool Init();
	void Render();
	void RenderNext();
	bool MoveDown();
	void MoveRight();
	void MoveLeft();
};

