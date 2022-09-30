#include "Engine.h"
#include "StageManager.h"
#include "ShapeManager.h"

CEngine* CEngine::_instance = nullptr;

CEngine::CEngine():
	m_bLoop(true)
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
	while (m_bLoop)
	{
		system("cls");
		CShapeManager::GetInstance()->Update();

		CStageManager::GetInstance()->Run();	// 스테이지 렌더
		CShapeManager::GetInstance()->Render();	// 도형 렌더

		Sleep(5);		// 초당 한번만 돌아가도록 제어한다.
	}
	
}

void CEngine::SetConsolePos(int x, int y)
{
	// 한 칸에 2byte를 사용하므로
	COORD	pos = { (x + 1) * 2,y };
	SetConsoleCursorPosition(m_hConsole, pos);
}
