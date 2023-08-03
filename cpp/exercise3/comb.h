#include "def.h"
#include <stdio.h>
#include <vector>
#include "hamming.h"

class Comb{
	std::vector<uint16> A, B;

	int _near(std::vector<uint16>& B, uint16 x) {
		int md = 16;
		for (uint16 b : B) {
			int d = hm.hamming_dist16(b, x);
			if (d<md)
				md=d;
		}
	}

public:
	Hamming hm;

	int all() {
		for (int i = 0; i < 0x10000; i++) {
			if(hm.hamming_dist16(i, 0) == 7)
				A.push_back(i);
		}
	}

	int all3() {
		for (int i = 0; i < A.size(); i++) {
			if(_near(B, A[i]) >= 4) {
				B.push_back((A[i]));
			}
		}
	}
};