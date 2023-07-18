#include <stdio.h>

typedef unsigned char uint8;

#define MaxArrL 1024

typedef struct {
	uint8 A[MaxArrL];
	int N;
} Arr2;

bool arr_alloc(Arr2* pA) {
	pA->N = 0;
	return pA->A != 0;
}

void arr_free(Arr2* pA) {
	pA->N = 0;
}

#define arr_isFull(a) ((a).N == MaxArrL)
#define arr_isEmpty(a) ((a).N == 0)
#define arr_at(a, i) a.A[i]

bool arr_push_back(Arr2* pA, uint8 val) {
	if (arr_isFull(*pA))
		return 0;
	pA->A[pA->N++] = val;
	return 1;
}

bool arr_pop_back(Arr2* pA) {
	if (arr_isEmpty(*pA))
		return 0;
	pA->N--;
	return 1;
}

bool arr_push_at(Arr2* pA, uint8 val, int pos) {
	if (arr_isFull(*pA) || pos < 0 || pos > pA->N)
		return 0;
	for (int i = pA->N; i > pos; i--)
		pA->A[i] = pA->A[i - 1];
	pA->A[pos] = val;
	pA->N++;
	return 1;
}

uint8 arr_min(Arr2* pA) {
	if (arr_isEmpty(*pA))
		return 0;

	uint8 minVal = pA->A[0];
	for (int i = 1; i < pA->N; i++)
		if (pA->A[i] < minVal)
			minVal = pA->A[i];
	return minVal;
}

float arr_avg(Arr2* pA) {
	if (arr_isEmpty(*pA))
		return 0.0;

	int sum = 0;
	for (int i = 0; i < pA->N; i++)
		sum += pA->A[i];
	return (float)sum / pA->N;
}