#pragma once

#include "StdAfx.h"

class CStageManager
	: public Singleton<CStageManager>
{
public:
	CStageManager();
	~CStageManager();

private:
	class CStage* m_pCurStage;

public:
	class CStage* GetCurrentStage() const
	{
		return m_pCurStage;
	}
public:
	bool Init();
	void Run();

};

