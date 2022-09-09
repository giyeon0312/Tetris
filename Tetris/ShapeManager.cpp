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
	m_pNextShape = CreateRandomShape();
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

	// 틱이 다 돌았을 경우
	if (pCurStage->GetSpeed() == m_nSpeed)
	{
		// 현재 도형이 바닥이나 다른 도형 위에 닿았을 경우
		if (m_pCurShape->MoveDown())
		{
			pCurStage->AddBlock(m_pCurShape,m_pCurShape->GetPosition());

			SAFE_DELETE(m_pCurShape);

			m_pCurShape = m_pNextShape;
			m_pCurShape->SetPosition(4, 0);

			m_pNextShape = CreateRandomShape();
		}

		m_nSpeed = 0;
	}

	if (GetAsyncKeyState('A') & 0x8000) // 0x8000은 이전에 누른 적이 없고 호출 시점에서 눌린 상태
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

	m_pNextShape->SetPosition(12, 3);
	m_pNextShape->RenderNext();
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
