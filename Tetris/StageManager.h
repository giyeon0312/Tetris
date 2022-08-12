#pragma once

#include "StdAfx.h"

class CStageManager
	: public Singleton<CStageManager>
{
public:
	CStageManager();
	~CStageManager();

public:
	bool Init();
	void Run();

private:
	class CStage* m_pCurStage;

};

