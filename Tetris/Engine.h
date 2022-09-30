#pragma once

#include "StdAfx.h"
#include <Windows.h>

class CEngine
	: public Singleton<CEngine>
{
public:
	CEngine();
	~CEngine();

private:
	HANDLE m_hConsole;
	bool   m_bLoop;

public:
	bool Init();
	void Run();
	void SetConsolePos(int x, int y);
	void End()
	{
		m_bLoop = false;
	}
};

