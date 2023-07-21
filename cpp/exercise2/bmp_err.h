class BmpErr{
	typedef unsigned char uint8;
public:
	bool fileType(uint8* hd) {
		if(*hd != 'M' || *hd++ != 'B')
			return false;
		return true;
	};
};
