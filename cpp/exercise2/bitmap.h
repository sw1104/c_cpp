#include <stdio.h>
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
	Bitmap() : _bmp(0), W(0), H(0) {

	}

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

		file.dup((char*)header, (char*)_bmp);

		file.read((char*)&_bmp[54], size);
		file.close();
		return true;
	}

	bool save(char* path){ 
		file.open(path, "wb");
		int size = W * H * 3;
		file.write((char*)_bmp, size);
		file.close();
		return true;
	}

	uint32 at(int x, int y) {

	}

	uint8* ptr(int x, int y) {
		return (uint8*)((y * W + x) * 3);  
	}

	void flip_vertical(uint8* q) {
		for (int y = 0; y < H; y++) {
			uint8* left = &_bmp[54] + y * W;
			uint8* right = _bmp + (y + 1) * W - 1;

			for (; left < right; left++, right--) {
				uint8 t = *left;
				*left = *right;
				*right = t;
			}
		}
	}

	void flip_horizontal(uint8* q) {
		uint8* top = _bmp;
		uint8* bottom = _bmp + H * W;

		for (; top < bottom; top += W, bottom -= W) {
			for (int i = 0; i < W; i++) {
				uint8 t = top[i];
				top[i] = bottom[i];
				bottom[i] = t;
			}
		}
	}

	void getFlip(bool vertical=true) {
		if (vertical) {
			uint8* p = 
			flip_vertical(_bmp);
			save("vertical.BMP");

		}
		flip_horizontal(_bmp);
		save("horizontal.BMP");
	}

	Bitmap* getRotate90(int nth) {
	
	}

	void bright(float) {
	
	}

	void drawRect(int x, int y, int w, int h, int color) {
	
	}

	Bitmap* getCrop(int x, int y, int w, int h) {
	
	}

	Bitmap* findBestMatch(Bitmap* q, Bitmap* r) {

	}
};
