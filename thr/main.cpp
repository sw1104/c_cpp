/* 
#include <iostream>
int main() {
	int b = 1, c = 1;
	for(int i=0; i<98; ++i) {
		int t = c;
		c = c + b;
		b = t;
	}
	std::cout << "F100: " << c << std::endl;
}
*/


/*
#include <iostream>
#include <thread>
using std::thread;

void func1() {
	for (int i=0; i<10; i++) {
		std::cout << "thr 1 ing\n";
	}
}

void func2() {
	for (int i=0; i<10; i++) {
		std::cout << "thr 2 ing\n";
	}
}

void func3() {
	for (int i=0; i<10; i++) {
		std::cout << "thr 1 ing\n";
	}
}

int main() {
	thread t1(func1);
	thread t2(func2);
	thread t3(func3);

	t1.join();
	t2.join();
	t3.join();

// 	t1.detach();
// 	t2.detach();
// 	t3.detach();
}
*/

/*
#include <cstdio>
#include <iostream>
#include <thread>
#include <vector>
using std::thread;
using std::vector;

void worker(vector<int>::iterator start, vector<int>::iterator end, int* result) {
	int sum = 0;
	for (auto itr = start; itr < end; ++itr)
		sum += *itr;
	*result = sum;

	thread::id this_id = std::this_thread::get_id();
	printf("thr id : %x, start : %d, end : %d, sum : %d\n", this_id, *start, *(end-1), sum);
}

void main() {
	vector<int> data(10000);
	for (int i=0; i<10000; ++i) {
		data[i] = i;
	}

	vector<int> partial_sums(4);

	vector<thread> workers;
	for (int i=0; i<4; ++i) {
		workers.push_back(thread(worker, data.begin() + i * 2500, data.begin() + (i + 1) * 2500, &partial_sums[i]));
	}

	for (int i=0; i<4; ++i) {
		workers[i].join();
	}

	int total=0;
	for (int i=0; i<4; ++i)
		total += partial_sums[i];

	std::cout << "Total sum: " << total << std::endl;
}

*/


// /*
#include <iostream>
#include <cstring>
#include <thread>
#include <vector>
#include <time.h>
using std::thread;
using std::vector;

typedef long long LL;

LL fibo_c(int x) {
	if (x <= 2)
		return 1;

	LL res = fibo_c(x-1) + fibo_c(x-2);
	return res;
}

LL fibo_c2(int x, LL* result) {
	if (x<=2) {
		*result=1;
		return 1;
	}

	*result = fibo_c(x-1) + fibo_c(x-2);
	return *result;
}


int main() {
	time_t start, end;
	int x;
	LL result;

	x = 50;

	start = clock();
	result = fibo_c(x);
	end = clock();

	std::cout << "fibo in single (" << x << ") : " << " / Time elapsed : " << (double)(end - start) << std::endl;

	LL r1, r2;
	start = clock();

	thread f1(fibo_c2, x-2, &r1);
	thread f2(fibo_c2, x-1, &r2);
	f1.join();
	f2.join();
	result = r1 + r2;

	end = clock();

	std::cout << "fibo in multi (" << x << ") : " << " / Time elapsed : " << (double)(end - start) << std::endl;
}
// */