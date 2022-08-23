#pragma once

#include "StdAfx.h"

class CShapeManager
	: public Singleton<CShapeManager>
{
public:
	CShapeManager();
	~CShapeManager();

private:
	class CShape* m_pCurShape;	// ���� ����
	class CShape* m_pNextShape; // ������ ��Ÿ�� ����
	int	  m_nSpeed;				// ������ ������ ƽ

public:
	void Update();
	void Render();
	class CShape* CreateShape(SHAPE_TYPE eType);
	class CShape* CreateRandomShape();
};


