#include "StageManager.h"
#include "Stage.h"

#include "ShapeManager.h"
#include "Rectangle.h"
#include "ShapeGun.h"
#include "ShapeRGun.h"
#include "ShapeLine.h"
#include "ShapeS.h"
#include "ShapeT.h"
#include "ShapeZ.h"

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

	// ƽ�� �� ������ ���
	if (pCurStage->GetSpeed() == m_nSpeed)
	{
		// ���� ������ �ٴ��̳� �ٸ� ���� ���� ����� ���
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
	case SHAPE_TYPE::ST_GUN:
		pShape = new CShapeGun();
		break;
	case SHAPE_TYPE::ST_RGUN:
		pShape = new CShapeRGun();
		break;
	case SHAPE_TYPE::ST_LINE:
		pShape = new CShapeLine();
		break;
	case SHAPE_TYPE::ST_S:
		pShape = new CShapeS();
		break;
	case SHAPE_TYPE::ST_T:
		pShape = new CShapeT();
		break;
	case SHAPE_TYPE::ST_Z:
		pShape = new CShapeZ();
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
		case SHAPE_TYPE::ST_RECT:
			pShape = new CRectangle();
			break;
		case SHAPE_TYPE::ST_GUN:
			pShape = new CShapeGun();
			break;
		case SHAPE_TYPE::ST_RGUN:
			pShape = new CShapeRGun();
			break;
		case SHAPE_TYPE::ST_LINE:
			pShape = new CShapeLine();
			break;
		case SHAPE_TYPE::ST_S:
			pShape = new CShapeS();
			break;
		case SHAPE_TYPE::ST_T:
			pShape = new CShapeT();
			break;
		case SHAPE_TYPE::ST_Z:
			pShape = new CShapeZ();
			break;
		}
	
	if (!pShape->Init())
	{
		SAFE_DELETE(pShape);
		return NULL;
	}

	return pShape;
}
