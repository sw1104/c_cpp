#include <windows.h>

class Thread {
	HANDLE _hThr;
	Semaphore _sem;
protected:
	virtual int thr() {
		_sem.post();
		CloseHandle(_hThr);
		return 0;
	}
	static int thr_init(void* param) {
		return ((Thread*)param)->thr();
	}

	inline HANDLE thread_start(int(*thr)(void*), void* para) {
		return CreateThread(0, 0, (LPTHREAD_START_ROUTINE)thr, para, 0, 0);
	}
public:
	void start() { _hThr= thread_start(thr_init, this); }
	void join() { _sem.wait(); }
};

class TThread : public Thread {
	Mutex& m;
	Semaphore _sem;
public:
	TThread(Mutex& mutex) : m(mutex) {}

	int thr() override {
		m.lock();
		for (int i = 0; i < 11; i++) {
			printf("Thread : %d \n", i);
			Sleep(500);
		}
		m.unlock();
		return 0;
	}
};


