#include <iostream>
#include "list.h"

class StrList {
	List list;

public:
	void print() {
		list.print();
	}

	void push_front(char* str) {
		list.push_at(*str, 0);
	}

	void pop_front() {
		list.pop_at(0);
	}

	void push_back(char* str) {
		list.push_back(*str);
	}

	void pop_back() {
		list.pop_back();
	}

	char at(int i) {
		return list.at(i);
	}

	int size() {
		return list.size();
	}
};