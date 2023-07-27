#include <stdio.h>
#include <string.h>
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

		if(err.fileType(header))
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

	}

	uint8* ptr(int x, int y) {
		return &_bmp[54] + (y * W + x) * 3;
	}

	void flip_vertical(uint8* q) {
		for (int y = 0; y < H; y++) {
			uint8* left = q + y * W * 3;
			uint8* right = q + (y + 1) * W * 3 - 1;
			
			for (; left < right; left++, right--) {
				uint8 t = *left;
				*left = *right;
				*right = t;
			}
		}
		for (int i = 0; i < W*H*3; i += 3) {
			uint8 t = q[i];
			q[i] = q[i+2];
			q[i+2] = t;
		}
	}


	void flip_horizontal(uint8* q) {
		int half_height = H / 2;
		int row_stride = W * 3;

		for (int y = 0; y < half_height; y++) {
			uint8* top_row = q + y * row_stride;
			uint8* bottom_row = q + (H - 1 - y) * row_stride;

			for (int x = 0; x < row_stride; x++) {
				uint8 t = top_row[x];
				top_row[x] = bottom_row[x];
				bottom_row[x] = t;
			}
		}
	}

	void getFlip(bool vertical=true) {
		int size = W*H*3;
		uint8* p = new uint8[size];
		memcpy(p, &_bmp[54], size);
		if (vertical) {
			flip_vertical(p);
			memcpy(&_bmp[54], p, size);
			delete[] p;
			save("vertical.BMP");
		} else {
			flip_horizontal(p);
			memcpy(&_bmp[54], p, size);
			delete[] p;
			save("horizontal.BMP");
		}
	}

	Bitmap* getRotate90(int nth) {
		Bitmap* r = new Bitmap();
		r->W = H;
		r->H = W;

		int size = r->W * r->H * 3;
		r->_bmp = new uint8[size + 54];

		memcpy(r->_bmp, _bmp, 54);
		r->_bmp[18] = r->W;
		r->_bmp[22] = r->H;

		for (int y = 0; y < r->H; y++) {
			for (int x = 0; x < r->W; x++) {
				uint8* src = &_bmp[54] + (y * W + x) * 3;
				uint8* dst = &r->_bmp[54] + (x * W + r->W - 1 - y) * 3;
				memcpy(dst, src, 3);
			}
		}
		
		return r;
	}


	void bright(float ratio) {
		int size = W * H * 3;
		for (int i = 0; i < size; i++) {
			int v = _bmp[54 + i] + ratio * 255;
			if (v > 255) 
				v = 255;
			_bmp[54 + i] = (uint8)v;
		}
	}

	void drawRect(int x, int y, int w, int h, int R, int G, int B) {
		for(int j = y; j < y + h; j++) {
			for(int i = x; i < x + w; i++) {
				if(i == x || i == x + w - 1 || j == y || j == y + h - 1) {
					uint8* p = ptr(i, j);
					p[0] = B;
					p[1] = G;
					p[2] = R;
				}
			}
		}
	}
	Bitmap* getCrop(int x, int y, int w, int h) {
		Bitmap* c = new Bitmap();
		c->W = w;
		c->H = h;

		int size = w * h * 3;
		c->_bmp = new uint8[size + 54];

		memcpy(c->_bmp, _bmp, 54);
		c->_bmp[18] = w;
		c->_bmp[22] = h;

		for (int j = 0; j < y + h; j++) {
			for (int i = 0; i < x + w; i++) {
				uint8* src = ptr((x + i), (y + j));
				uint8* dst = ptr(i, j);
				memcpy(dst, src, 3);
			}
		}

		return c;
	}

	Bitmap* findBestMatch(Bitmap* q, Bitmap* r) {

	}
};
