#include "Engine.h"
#include "StageManager.h"
#include "ShapeManager.h"

CEngine* CEngine::_instance = nullptr;

CEngine::CEngine()
{
	srand(time(0));
}

CEngine::~CEngine()
{
	CStageManager::GetInstance()->DestroyInstance();
	CShapeManager::GetInstance()->DestroyInstance();
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
	while (true)
	{
		system("cls");
		CShapeManager::GetInstance()->Update();

		CStageManager::GetInstance()->Run();
		CShapeManager::GetInstance()->Render();

		Sleep(1000);		// 초당 한번만 돌아가도록 제어한다.
	}
	
}

void CEngine::SetConsolePos(int x, int y)
{
	// 한 칸에 2byte를 사용하므로
	COORD	pos = { x * 2,y };
	SetConsoleCursorPosition(m_hConsole, pos);
}
