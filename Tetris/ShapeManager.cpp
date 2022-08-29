#include "ShapeManager.h"
#include "Rectangle.h"
#include "StageManager.h"
#include "Stage.h"
#include <Windows.h>

CShapeManager* CShapeManager::_instance = nullptr;

CShapeManager::CShapeManager():
	m_pCurShape(NULL), m_pNextShape(NULL)
{
	m_pCurShape = CreateRandomShape();
	m_nSpeed = 0;
}

CShapeManager::~CShapeManager()
{
	SAFE_DELETE(m_pCurShape);
	SAFE_DELETE(m_pNextShape);
}

void CShapeManager::Update()
{

	CStage* pCurStage = CStageManager::GetInstance()->GetCurrentStage();
	++m_nSpeed;

	// ƽ�� �� ������ ���
	if (pCurStage->GetSpeed() == m_nSpeed)
	{
		m_pCurShape->MoveDown();
		m_nSpeed = 0;
	}

	if (GetAsyncKeyState('A') & 0x8000) // 0x8000�� ������ ���� ���� ���� ȣ�� �������� ���� ����
	{
		m_pCurShape->MoveLeft();
	}

	if (GetAsyncKeyState('D') & 0x8000) 
	{
		m_pCurShape->MoveRight();
	}
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
