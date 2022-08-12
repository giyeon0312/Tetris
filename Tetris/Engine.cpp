#include "Engine.h"
#include "StageManager.h"

CEngine* CEngine::_instance = nullptr;

CEngine::CEngine()
{
}

CEngine::~CEngine()
{
	//CStageManager::GetInstance()->DestoryInstance();
}

bool CEngine::Init()
{
	// �������� ������ �ʱ�ȭ�Ѵ�.
	if (!CStageManager::GetInstance()->Init())
		return false;

	return true;
}

void CEngine::Run()
{
	CStageManager::GetInstance()->Run();
}