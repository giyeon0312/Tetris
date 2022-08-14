#include "Engine.h"
#include "StageManager.h"

CEngine* CEngine::_instance = nullptr;

CEngine::CEngine()
{
	srand(time(0));
}

CEngine::~CEngine()
{
	CStageManager::GetInstance()->DestoryInstance();
}

bool CEngine::Init()
{
	// 콘솔창 핸들 생성
	m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (m_hConsole == INVALID_HANDLE_VALUE)
		return false;
	
	// 스테이지 관리자 초기화한다.
	if (!CStageManager::GetInstance()->Init())
		return false;


	return true;
}

void CEngine::Run()
{
	CStageManager::GetInstance()->Run();
}

void CEngine::SetConsolePos(int x, int y)
{
	// 한 칸에 2byte를 사용하므로
	COORD	pos = { x * 2,y };
	SetConsoleCursorPosition(m_hConsole, pos);
}
