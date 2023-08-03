#include "def.h"
#include <stdio.h>

class Hamming {
public:
	int hamming_dist(uint8 a, uint8 b) {
		uint8 x = a^b, n = 0;
		for (int i = 0; i < 8; i++) {
			n += x&1;
			x >>= 1;
		}
		return n;
	}

	int hamming_dist16(uint16 a, uint16 b) {
		uint8* pa = (uint8*)&a;
		uint8* pb = (uint8*)&b;
		return hamming_dist(*pa, *pb) + hamming_dist(*(pa + 1), *(pb + 1));
	}
};