#include <fstream>
#include "list.h"

using namespace std;

class FileList{
	List list;
public:
	void print() {
		list.view();
	}

	void push_front(char* str) {
		int n = strlen(str);
		for (int i = n - 1; i >= 0; --i) {
			list.push_at(str[i], 0);
		}
	}

	void pop_front() {
		list.pop_at(0);
	}

	void push_back(char* str) {
		int n = strlen(str);
		for (int i = 0; i < n; ++i) {
			list.push_back(str[i]);
		}
	}

	void pop_back() {
		list.pop_back();
	}

	bool save(char* path) {
		ofstream f(path);
		int s = list.size();
		for (int i = 0; i < s + 1; i++) {
			char p = list.at(i);
			f << p;
		}
		f.close();
		return true;
	}

	bool load(char* path) {
		ifstream f(path);
		char t;
		while (f.get(t)) {
			list.push_back(t);
		}
		f.close();
		return true;
	}

	char at(int i) {
		return list.at(i);
	}
	
	int size() {
		return list.size();
	}
};