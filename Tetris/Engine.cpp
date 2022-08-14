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
	CStageManager::GetInstance()->Run();
}

void CEngine::SetConsolePos(int x, int y)
{
	// �� ĭ�� 2byte�� ����ϹǷ�
	COORD	pos = { x * 2,y };
	SetConsoleCursorPosition(m_hConsole, pos);
}
