#include <stdio.h>

class File {
	FILE* m_fd;
public:
	bool open(char* path, char* opt="rb") {
		return (m_fd=fopen(path, opt))!=0;
	}
	void close() {
		if (m_fd)
			fclose(m_fd);
	}
	bool read(char* buf, int len) {
		return fread(buf, 1, len, m_fd)==len;
	}
	bool write(char* buf, int len) {
		return fwrite(buf, 1, len, m_fd)==len;
	}
	bool seek(int offset, int origin) {
		return fseek(m_fd, offset, origin)==0;
	}
	int size() {}

	static bool dup(char* src, char* dst) {
		for (int i = 0; i < 54; i++)
			*dst++ = src[i];
		return true;
	}

	static bool is_exist(char* path) {
	}
	void flush() { fflush(m_fd); }
};
