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
	// �ܼ�â �ڵ� ����
	m_hConsole = GetStdHandle(STD_OUTPUT_HANDLE);

	if (m_hConsole == INVALID_HANDLE_VALUE)
		return false;
	
	// �������� ������ �ʱ�ȭ�Ѵ�.
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

		Sleep(1000);		// �ʴ� �ѹ��� ���ư����� �����Ѵ�.
	}
	
}

void CEngine::SetConsolePos(int x, int y)
{
	// �� ĭ�� 2byte�� ����ϹǷ�
	COORD	pos = { x * 2,y };
	SetConsoleCursorPosition(m_hConsole, pos);
}
