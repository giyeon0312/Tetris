#pragma once
#include <mutex>
#include <thread>

using namespace std;

static mutex _mutex;

template<typename T>
class Singleton
{
private:
	static T* _instance;

public:
	static T* GetInstance()
	{
		if (_instance == NULL)
		{
			_mutex.lock();
			if (_instance == NULL)
			{
				_instance = new T;
			}
			_mutex.unlock();
		}
		return _instance;
	}

	static void DestoryInstance()
	{
		SAFE_DELETE(_instance);
	}
};