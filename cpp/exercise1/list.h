#include <iostream>

typedef unsigned char uint8;

class List {
	struct Elem {
		uint8 v;
		Elem* next;
	};

	Elem* header;

public:
	List() : header(nullptr) {}
	~List() {
		Elem* t = header;
		header = header->next;
		delete t;
	}

	void print() {
		Elem* p = header;
		while (p) {
			printf("%d", p->v);
			p = p->next;
		}
		puts("");
	}

	bool isEmpty() {
		return header == 0;
	}

	void push_back(int val) {
		Elem* p = new Elem;
		p->v = val;
		p->next = 0;

		if (isEmpty())
			header = p;
		else {
			Elem* cur = header;
			while (cur->next)
				cur = cur->next;
			cur->next = p;
		}
	}

	void pop_back() {
		if(isEmpty())
			return;

		if(header->next == 0){
			
		}
		











	void pop_back() {
		if (isEmpty())
			return;

		if (header->next == nullptr) {
			delete header;
			header = nullptr;
		}
		else {
			Elem* cur = header;
			while (cur->next->next) {
				cur = cur->next;
			}
			delete cur->next;
			cur->next = nullptr;
		}
	}

	void push_at() {

	}

	void pop_at() {

	}

	uint8 min() {

	}

	uint8 max() {

	}

	float avg() {

	}
};