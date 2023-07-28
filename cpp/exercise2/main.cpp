#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include "combination.h"
#include "bitmap.h"
#include "timer.h"

void main() {
	Bitmap bmp;
	bmp.load("img/XING_B24.BMP");

// 	bmp.bright(0.5f);
// 	bmp.save("img/br.BMP");

// 	Bitmap* r = bmp.getRotate90(1);
// 	r->save("img/r.BMP");



// 	Bitmap* f = bmp.getFlip(0);
// 	f->save("img/hhhh.BMP");

	Bitmap* c = bmp.getCrop(200,1,28,77);
	c->save("img/crop.BMP");
	bmp.drawRect(200, 1,28,77, 0, 0 ,0);
	bmp.save("img/rect.BMP");

	Timer t;
	Bitmap* f = bmp.findBestMatch(&bmp, c);
	printf("%dms\n", t.off());
	f->save("img/find.BMP");
	
}
