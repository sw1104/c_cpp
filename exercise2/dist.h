#include <stdio.h>

typedef unsigned char uint8;

#define _pow(a) ((a) * (a))
#define _abs(a) ((a) < 0 ? (a) * -1 : (a))
#define FLT_MAX 99999;

float _sqrt(float n) {
	float s = 0.0f;
	float t = 0.0f;
	s = (float)(n / 2);
	for (; s != t;) {
		t = s;
		s = ((n / t) + t) / 2;
	}
	return s;
}

float L1_dist(uint8 *A, uint8 *B, int len) {
	float dist = 0.0f;
	for (int i = 0; i < len; i++)
		dist += _abs((float)A[i] - B[i]);
	return dist;
}

float L2_dist(uint8 *A, uint8 *B, int len)
{
	float dist = 0.0f;
	for (int i = 0; i < len; i++)
		dist += _pow((float)A[i] - B[i]);
	return _sqrt(dist);
}

uint8 *find_best_match(uint8 *R, uint8 *Q, int rN, int qN, float *pd, bool L1) {
	uint8 *pR = 0;
	float dist = FLT_MAX;

	for (uint8 *p = R; p <= &R[rN - qN]; p++) {
		float cur;
		L1 ? cur = L1_dist(p, Q, qN) : cur = L2_dist(p, Q, qN);
		if (cur < dist) {
			dist = cur;
			pR = p;
		}
	}
	*pd = dist;
	return pR;
}
