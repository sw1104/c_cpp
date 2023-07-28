#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "file.h"
#include "bmp_err.h"

class Bitmap {
	typedef unsigned char uint8;
	typedef unsigned short uint16;
	typedef unsigned int uint32;
	uint8* _bmp;
	File file;
	BmpErr err;
public:
	int W, H;
	Bitmap() : _bmp(0), W(0), H(0) {}
	~Bitmap() {
		delete _bmp;
		W = 0;
		H = 0;
	}

	bool load(char* path) {
		file.open(path);
		uint8* header = new uint8[54];
		file.read((char*)header, 54);

		if (err.fileType(header))
			return false;

		W = *(int*)&header[18];
		H = *(int*)&header[22];

		int size = W * H * 3;

		_bmp = new uint8[size + 54];

		memcpy(_bmp, header, 54);

		file.read((char*)&_bmp[54], size);
		file.close();
		return true;
	}

	bool save(char* path){
		file.open(path, "wb");
		int size = W * H * 3;
		file.write((char*)_bmp, size + 54);
		file.close();
		return true;
	}

	uint32 at(int x, int y) {
		uint8 p = (y * W + x) * 3 + 54;
		uint8 r = _bmp[p + 2];
		uint8 g = _bmp[p + 1];
		uint8 b = _bmp[p];
		uint32 rgb = (uint32)r * 65536 + (uint32)g * 256 + (uint32)b;
		return rgb;
	}

	uint8* ptr(int x, int y) {
		return &_bmp[54] + (y * W + x) * 3;
	}

	void flip_vertical(uint8* q) {
		for (int y = 0; y < H; y++) {
			uint8* left = &q[54] + y * W * 3;
			uint8* right = &q[54] + (y + 1) * W * 3 - 1;

			for (; left < right; left++, right--) {
				uint8 t = *left;
				*left = *right;
				*right = t;
			}
		}
		for (int i = 0; i < W * H * 3; i += 3) {
			uint8 t = q[54 + i];
			q[54 + i] = q[54 + i + 2];
			q[54 + i + 2] = t;
		}
	}

	void flip_horizontal(uint8* q) {
		for (int y = 0; y < H / 2; y++) {
			uint8* top = &q[54] + y * W * 3;
			uint8* bottom = &q[54] + (H - 1 - y) * W * 3;

			for (int x = 0; x < W * 3; x++) {
				uint8 t = top[x];
				top[x] = bottom[x];
				bottom[x] = t;
			}
		}
	}

	Bitmap* createBitmap(int w, int h, uint8* _bmp) {
		Bitmap* bmp = new Bitmap();
		bmp->W = w;
		bmp->H = h;

		int size = w * h * 3;
		bmp->_bmp = new uint8[size + 54];

		memcpy(bmp->_bmp, _bmp, 54);
		bmp->_bmp[18] = w;
		bmp->_bmp[22] = h;

		return bmp;
	}

	Bitmap* getFlip(bool vertical=true) {
		Bitmap* f = createBitmap(W, H, _bmp);
		memcpy(&f->_bmp[54], &_bmp[54], W*H*3);
		if (vertical)
			flip_vertical(f->_bmp);
		else
			flip_horizontal(f->_bmp);
		return f;
	}

	Bitmap* getRotate90(int nth) {
		Bitmap* r = createBitmap(H, W, _bmp);
		for (int y = 0; y < r->H; y++) {
			for (int x = 0; x < r->W; x++) {
				uint8* src = ptr(-y - 1, x + 1);
				uint8* dst = r->ptr(x, y);
				memcpy(dst, src, 3);
			}
		}
		return r;
	}

	void bright(float ratio) {
		int size = W * H * 3;
		for (int i = 0; i < size; i++) {
			int v = _bmp[54 + i] * ratio;
			if (v > 255)
				v = 255;
			_bmp[54 + i] = (uint8)v;
		}
	}

	void drawRect(int x, int y, int w, int h, int R, int G, int B) {
		for (int j = y; j < y + h; j++) {
			for (int i = x; i < x + w; i++) {
				if (i == x || i == x + w - 1 || j == y || j == y + h - 1) {
					uint8* p = ptr(i, j);
					p[0] = B;
					p[1] = G;
					p[2] = R;
				}
			}
		}
	}

	Bitmap* getCrop(int x, int y, int w, int h) {
		Bitmap* c = createBitmap(w, h, _bmp);

		for (int j = 0; j < h; j++) {
			for (int i = 0; i < w; i++) {
				uint8* src = ptr((x + i), (y + j));
				uint8* dst = c->ptr(i, j);
				memcpy(dst, src, 3);
			}
		}
		return c;
	}

	Bitmap* findBestMatch(Bitmap* q, Bitmap* r) {
		int maxInt = 2100000000;
		int x0;
		int y0;
		for(int y = 0; y < q->H - r->H; y++) {
			for(int x = 0; x < q->W - r->W; x++) {
				int dist = 0;
				for(int ry = 0; ry < r->H; ry++) {
					for(int rx = 0; rx < r->W; rx++) {
						uint8* orig = q->ptr(x + rx, y + ry);
						uint8* crop = r->ptr(rx, ry);

						dist += abs(orig[0] - crop[0]) + abs(orig[1] - crop[1]) + abs(orig[2] - crop[2]);
					}
				}
				if(dist < maxInt) {
					maxInt = dist;
					x0 = x;
					y0 = y;
				}
			}
		}

		q->drawRect(x0, y0, r->W, r->H, 255, 0, 0);
		return q;
	}
};


