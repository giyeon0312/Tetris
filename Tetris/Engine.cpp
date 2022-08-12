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
	// 스테이지 관리자 초기화한다.
	if (!CStageManager::GetInstance()->Init())
		return false;

	return true;
}

void CEngine::Run()
{
	CStageManager::GetInstance()->Run();
}