class Bitmap {
	typedef unsigned char uint8;
	typedef unsigned short uint16;
	typedef unsigned int uint32;
	uint8* _bmp;
public:
	int W, H;
	Bitmap() : _bmp(0), W(0), H(0) {

	}

	~Bitmap() {

	}

	bool load(char* path) {

	}

	bool save(char* path) {

	}

	uint32 at(int x, int y) {

	}

	uint8* ptr(int x, int y) {

	}

	Bitmap* getFlip(bool vertical=true) {
	
	}

	Bitmap* getRotate90(int nth) {
	
	}

	void bright(float) {
	
	}

	void drawRect(int x, int y, int w, int h, int color) {
	
	}

	Bitmap* getCrop(int x, int y, int w, int h) {
	
	}

};
