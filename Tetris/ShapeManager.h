#pragma once

#include "StdAfx.h"

class CShapeManager
	: public Singleton<CShapeManager>
{
public:
	CShapeManager();
	~CShapeManager();

private:
	class CShape* m_pCurShape;	// 현재 도형
	class CShape* m_pNextShape; // 다음에 나타날 도형
	int	  m_nSpeed;				// 도형을 움직일 틱

public:
	void Update();
	void Render();
	class CShape* CreateShape(SHAPE_TYPE eType);
	class CShape* CreateRandomShape();
};


