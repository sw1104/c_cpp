#include <stdio.h>
#include "mutex.h"
#include "thr.h"

void main() {
	Mutex m;

	TThread a(&m), b(&m);

	a.start();
	a.join();

	b.start();
	b.join();
}
