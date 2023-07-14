#include <stdio.h>
#include <string.h>

typedef unsigned char uint8;

typedef struct {
	uint8* bmp;
	int W, H;
} BinImg;

void bim_init(BinImg* bin) {
	memset(bin, 0, sizeof(BinImg));
}

void bim_alloc(BinImg* bin, int w, int h) {
	bin -> W = w;
	bin -> H = h;
	bin -> bmp = new uint8[w*h];
}

uint8 at(BinImg* bin, int x, int y) {
	return bin->bmp[y * bin->W + x];
}

void fillRect(BinImg* bin, int x, int y, int w, int h, uint8 val) {
	uint8* p = bin -> bmp;
	p += bin -> W * y + x;

	for(y = 0; y < h + 1; y++) {
		for(x = 0; x < w + 1; x++) {
			p[bin->W * y + x] = val;
		}
	}
}

void drawRect(BinImg* bin, int x, int y, int w, int h, uint8 val) {
	uint8* p = bin -> bmp;
	p += bin -> W *y + x;

	for (x = 0; x < w + 1; x++) {
		p[x] = val;
		p[x + bin -> W * h] = val;
	}

	for(y = 1; y < h; y++) {
		p[bin -> W * y] = val;
		p[bin -> W * y + w] = val;
	}
}

// void drawLine(BinImg* bin, int x0, int y0, int x1, int y1, uint8 val) {
// 
// }
// void flip_vertical(BinImg* bin) {
// 
// }
// void flip_horizontal(BinImg* bin) {
// 
// }
// void rotate90(BinImg* bin, int n) {
// 
// }
// void behalf(BinImg* bin) {
// 
// }
// void draw(BinImg* bin) {
// 
// }
// void free(BinImg* bin) {
// 
// }
