#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "combination.h"
#include "bitmap.h"

void main() {
// 	int A[] = {0, 1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 14, 15};
// 
// 	Combination comb;
// 	comb.all(A);

	Bitmap bmp;
	bmp.load("XING_B24.BMP");
// 	bmp.bright(0.7f);
// 	bmp.save("br7.BMP");
// 	bmp.getFlip();
// 	bmp.bright(0.4f);
// 	bmp.save("br4.BMP");
// 	bmp.getFlip(false);
// 	bmp.bright(0.1f);
// 	bmp.save("br1.BMP");

// 	Bitmap* r = bmp.getRotate90(1);
// 	r->save("r.BMP");
// 	bmp.bright(1.0f);
// 	bmp.drawRect(1, 1,30, 30, 255, 0 ,0);
// 

	Bitmap* c = bmp.getCrop(3,3,8,10);

 	c->save("cccc.BMP");
}
