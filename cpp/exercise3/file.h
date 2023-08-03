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
	int size() {
		fseek(m_fd, 0L, SEEK_END);
		int sz = ftell(m_fd);
		fseek(m_fd, 0L, SEEK_SET);
		return sz;
	}
	void flush() { fflush(m_fd); }

	char* readline(char* buf, int len) {
		char c;
		int i = 0;
		while (i < len - 1) {
			if (read(&c, 1) != 1)
				break;
			if (c == '\n')
				break;
			buf[i++] = c;
		}
		buf[i] = 0;
		return i > 0 ? buf : 0;
	}
};