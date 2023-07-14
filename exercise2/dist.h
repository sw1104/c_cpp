#include <stdio.h>

typedef unsigned char uint8;

#define _pow(a) (a*a)

float _sqrt(float n) {
	float s = 0.0f;
	float t = 0.0f;

	s = (float)(n / 2);
	for(; s != t;) {
		t = s;
		s = ((n / t) + t) / 2;
	}
	return s;
}

float L1_dist(uint8* A, uint8* B, int len) {
	float dist = 0.0f;
	for(int i = 0; i < len; i++) {
		dist += (float)(A[i] - B[i]);
	}
	if(dist < 0)
		return dist *= -1;
	return dist;
}

float L2_dist(uint8* A, uint8* B, int len) {
	float dist = 0.0f;
	for(int i = 0; i < len; i++) {
		dist += _pow((float)(A[i] - B[i]));
	}
	return _sqrt(dist);
}


uint8* find_best_match(uint8* R, uint8* Q, int rN, int qN, float* pd, bool L1) {
	uint8* pR = 0;
	float dist = 0.0f;

	for (uint8* p = R; p <= &R[rN - qN]; p++){
		float cur;
		if(L1) {
			cur = L1_dist(p, Q, qN);
		} else {
			cur= L2_dist(p, Q, qN);
		}
		if (p == &R[0] || cur < dist) {
			dist = cur;
			pR = p;
		}
	}

	*pd = dist;
	return pR;
}
