#pragma once

#include "StdAfx.h"

class CEngine
	: public Singleton<CEngine>
{
public:
	bool Init();
	void Run();


};

