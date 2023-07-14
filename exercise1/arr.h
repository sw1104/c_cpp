#include <stdio.h>

typedef unsigned char uint8;

typedef struct {
	uint8* A;
	int N;
	int size;
} Arr;

bool arr_alloc(Arr* pA, int size) {
	pA->A = new uint8[size];
	pA->N = 0;
	pA->size = size;
	return pA->A != 0;
}

void arr_free(Arr* pA) {
	if (pA->A)
		delete pA->A;
	pA->A = 0, pA->N = pA->size = 0;
}

#define arr_isFull(a) ((a).N == (a).size)
#define arr_isEmpty(a) ((a).N == 0)
#define arr_at(a, i) a.A[i]

bool arr_push_back(Arr* pA, uint8 val) {
	if (arr_isFull(*pA))
		return 0;
	pA->A[pA->N++] = val;
	return 1;
}

bool arr_pop_back(Arr* pA) {
	if (arr_isEmpty(*pA))
		return 0;
	pA->N--;
	return 1;
}

bool arr_push_at(Arr* pA, uint8 val, int pos) {
	if (arr_isFull(*pA) || pos < 0 || pos > pA->N)
		return 0;
	for (int i = pA->N; i > pos; i--)
		pA->A[i] = pA->A[i - 1];
	pA->A[pos] = val;
	pA->N++;
	return 1;
}

uint8 arr_min(Arr* pA) {
	if (arr_isEmpty(*pA))
		return 0;
	uint8 minVal = pA->A[0];
	for (int i = 1; i < pA->N; i++) {
		if (pA->A[i] < minVal)
			minVal = pA->A[i];
	}
	return minVal;
}

float arr_avg(Arr* pA) {
	if (arr_isEmpty(*pA))
		return 0.0;
	int sum = 0;
	for (int i = 0; i < pA->N; i++)
		sum += pA->A[i];
	return (float)sum / pA->N;
}
