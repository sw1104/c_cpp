#include <stdio.h>
#include <string.h>
#include <vector>
#include "file.h"
#include "def.h"

class IDSet {
	std::vector<char*> L;
	
public:
	void clear() {
		L.clear();
	}

	bool open(char* path) {
		File file;
		file.open(path);
		char buf[200];

		while (file.readline(buf, sizeof(buf))) {
			char* t = strtok(buf, "\t");
			t = strtok(0, "\t");
			if (t) {
				char* id = new char[strlen(t) + 1];
				strcpy(id, t);
				L.push_back(id);
			}
		}
		file.close();
		return true;
	}

	void has(char* path) {
		File file;
		file.open(path);

		File newFile;
		newFile.open("result.txt", "w+b");

		char buf[200];
		while (file.readline(buf, sizeof(buf))) {
			char* id = strtok(buf, "\t");
			if (!dup(id)) {
				char* url = strtok(0, "\t");
				newFile.write(id, strlen(id));
				newFile.write("\t", 1);
				if (url) {
					newFile.write(url, strlen(url));
					newFile.write("\n", 1);
				}
			}
		}
		file.close();
		newFile.close();
	}

	bool dup(const char* id) {
		for(auto i = L.begin(); i != L.end(); i++) {
			if(strcmp(*i, id) == 0)
				return 1;
		}
		return 0;
	}
};
