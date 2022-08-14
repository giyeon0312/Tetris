#include "ShapeManager.h"
#include "Rectangle.h"

CShapeManager* CShapeManager::_instance = nullptr;

CShapeManager::CShapeManager():
	m_pCurShape(NULL), m_pNextShape(NULL)
{
	m_pCurShape = CreateRandomShape();
}

CShapeManager::~CShapeManager()
{
	SAFE_DELETE(m_pCurShape);
	SAFE_DELETE(m_pNextShape);
}

void CShapeManager::Update()
{
	m_pCurShape->MoveDown();
}

void CShapeManager::Render()
{
	m_pCurShape->Render();
}

CShape* CShapeManager::CreateShape(SHAPE_TYPE eType)
{
	CShape* pShape = NULL;

	switch (eType)
	{
	case SHAPE_TYPE::ST_RECT:
		pShape = new CRectangle();
		break;
	}

	if (!pShape->Init())
	{
		SAFE_DELETE(pShape);
		return NULL;
	}

	return pShape;
}

CShape* CShapeManager::CreateRandomShape()
{
	CShape* pShape = NULL;
	int randomShape = rand() % ST_END;

	switch ((SHAPE_TYPE)randomShape)
	{
	case ST_RECT:
		pShape = new CRectangle();
		break;
	}
	
	if (!pShape->Init())
	{
		SAFE_DELETE(pShape);
		return NULL;
	}

	return pShape;
}
