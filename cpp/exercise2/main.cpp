#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "combination.h"
#include "bitmap.h"

void main() {
// 	int A[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
// 
// 	Combination comb;
// 	comb.all(A);

	Bitmap bin;
	bin.load("img.BMP");
	bin.getFlip();
 	bin.save("v.BMP");
// 	bin.load("test.BMP");
}

