#pragma once

#include "StdAfx.h"

class CStageManager
	: public Singleton<CStageManager>
{
private:
	CStageManager();
	~CStageManager();

public:
	bool Init();
	void Run();
};

