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
	int	 m_nSpeed;

public:
	int GetSpeed() const
	{
		return m_nSpeed;
	}

	void SetSpeed(int nSpeed)
	{
		m_nSpeed = nSpeed;
	}
public:
	bool Init();
	void Render();
};

