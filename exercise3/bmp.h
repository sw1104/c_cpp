#include <stdio.h>
#include <string.h>
#include <math.h>

typedef unsigned char uint8;

typedef struct {
	uint8* bmp;
	int W, H;
} BinImg;

void bim_init(BinImg* bin) {
	memset(bin, 0, sizeof(BinImg));
}

void bim_alloc(BinImg* bin, int w, int h) {
	bin->W = w;
	bin->H = h;
	bin->bmp = new uint8[w*h];
}

uint8 at(BinImg* bin, int x, int y) {
	return bin->bmp[y * bin->W + x];
}

int _start(int point) {
	return (point < 0) ? 0 : point;
}

int _end(int point, int size, int limit) {
	return (point + size >= limit) ? limit : point + size;
}


void fillRect(BinImg* bin, int x, int y, int w, int h, uint8 val) {
	uint8* p = bin->bmp;

	int startX = _start(x);
	int startY = _start(y);
	int endX = _end(x, w + 1, bin->W);
	int endY = _end(y, h + 1, bin->H);

	for (int j = startY; j < endY; j++) {
		for (int i = startX; i < endX; i++) {
			p[j * bin->W + i] = val;
		}
	}
}

void drawRect(BinImg* bin, int x, int y, int w, int h, uint8 val) {
	uint8* p = bin->bmp;

	int startX = _start(x);
	int startY = _start(y);
	int endX = _end(x, w + 1, bin->W);
	int endY = _end(y, h + 1, bin->H);

	for (int i = startX; i < endX; i++) {
		if (startY >= 0 && startY < bin->H)
			p[startY * bin->W + i] = val;
		if (endY >= 0 && endY < bin->H)
			p[endY * bin->W + i] = val;
	}

	for (int j = startY + 1; j < endY; j++) {
		if (startX >= 0 && startX < bin->W)
			p[j * bin->W + startX] = val;
		if (endX >= 0 && endX < bin->W)
			p[j * bin->W + endX] = val;
	}
}

// void drawLine(BinImg* bin, int x0, int y0, int x1, int y1, uint8 val) {
// 	uint8* p = bin->bmp;
// 
// 	int dx = abs(x1 - x0);
// 	int dy = abs(y1 - y0);
// 	int sx = x0 < x1 ? 1 : -1;
// 	int sy = y0 < y1 ? 1 : -1;
// 	int e = (dx > dy ? dx : -dy) / 2;
// 
// 
// 	for (int t; x0 != x1 + 1 || y0 != y1 + 1;) {
// 		p[y0 * bin->W + x0] = val;
// 		t = e;
// 		if (t >= -dx) {
// 			e -= dy;
// 			x0 += sx;
// 		}
// 		if (t <= dy) {
// 			e += dx;
// 			y0 += sy;
// 		}
// 	}
// }

void drawLine(BinImg* bin, int x0, int y0, int x1, int y1, uint8 val) {
	uint8* p = bin->bmp;
	int s = (y1 - y0) / (x1 - x0);

	for (int x = x0; x < x1 + 1; x++) {
		int y = y0 + (s * (x - x0));
		p[y * bin->W + x] = val;
	}
}

void flip_vertical(BinImg* bin) {
	for (int y = 0; y < bin->H; y++) {
		uint8* left = bin->bmp + y * bin->W;
		uint8* right = bin->bmp + (y + 1) * bin->W - 1;

		for (; left < right; left++, right--) {
			uint8 t = *left;
			*left = *right;
			*right = t;
		}
	}
}

void flip_horizontal(BinImg* bin) {
	uint8* top = bin->bmp;
	uint8* bottom = bin->bmp + (bin->H - 1) * bin->W;

	for (; top < bottom; top += bin->W, bottom -= bin->W) {
		for (int i = 0; i < bin->W; i++) {
			uint8 t = top[i];
			top[i] = bottom[i];
			bottom[i] = t;
		}
	}
}

void _newSize(int W, int H, int n, int* newW, int* newH) {
	if (n % 2 == 0) {
		*newW = H;
		*newH = W;
	}
	else {
		*newW = W;
		*newH = H;
	}
}

void _rotate(int* x, int* y, int n, int w, int h) {
	if (n == 1) {
		int t = *x;
		*x = *y;
		*y = w - 1 - t;
	}
	else if (n == 2) {
		*x = w - 1 - *x;
		*y = h - 1 - *y;
	}
	else {
		int t = *x;
		*x = h - 1 - *y;
		*y = t;
	}
}

void rotate90(BinImg* bin, int n) {
	uint8* p = new uint8[bin->W * bin->H];

	int newW, newH;
	_newSize(bin->W, bin->H, n, &newW, &newH);

	for (int y = 0; y < bin->H; y++) {
		for (int x = 0; x < bin->W; x++) {
			int newX = x;
			int newY = y;
			_rotate(&newX, &newY, n, bin->W, bin->H);

			p[newY * newW + newX] = bin->bmp[y * bin->W + x];
		}
	}

	delete[] bin->bmp;
	bin->bmp = p;
	bin->W = newW;
	bin->H = newH;
}


void behalf(BinImg* bin) {
	int newW = bin->W / 2;
	int newH = bin->H / 2;

	uint8* p = new uint8[newW * newH];

	for (int y = 0; y < newH; y++) {
		for (int x = 0; x < newW; x++) {
			p[y * newW + x] = bin->bmp[(y * 2) * bin->W + (x * 2)];
		}
	}

	delete[] bin->bmp;
	bin->bmp = p;
	bin->W = newW;
	bin->H = newH;
}

void draw(BinImg* bin) {
	for (int y = 0; y < bin->H; y++) {
		for (int x = 0; x < bin->W; x++) {
			printf("%c ", bin->bmp[y * bin->W + x] ? '*' : ' ');
		}
		printf("\n");
	}
}

void free(BinImg* bin) {
	delete[] bin->bmp;
	bin->W = 0;
	bin->H = 0;
}