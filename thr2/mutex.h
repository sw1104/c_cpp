#include <windows.h>

class Semaphore {
	HANDLE m_hSem;
public:
	Semaphore(int initCnt=0)
		: m_hSem(CreateSemaphore(0, initCnt, 1, 0)) {}
	~Semaphore() { ReleaseSemaphore(m_hSem, 1, 0); }
	void wait(bool bTry=0) {
		WaitForSingleObject(m_hSem, bTry ? 0 : INFINITE);
	}
	void post() {
		ReleaseSemaphore(m_hSem, 1, 0);
	}
};

class Mutex {
	CRITICAL_SECTION m_cs;
public:
	Mutex() {
		InitializeCriticalSection(&m_cs);
	}
	~Mutex() {
		DeleteCriticalSection(&m_cs);
	}
	void lock() {
		EnterCriticalSection(&m_cs);
	}
	void unlock() {
		LeaveCriticalSection(&m_cs);
	}
};

