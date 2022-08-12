#pragma once
#include "StdAfx.h"


class CStage
{
public:
	CStage();
	~CStage();

private:
	friend class CStageManager;

private:
	char m_Stage[STAGE_HEIGHT][STAGE_WIDTH];

public:
	bool Init();
	void Render();
};

