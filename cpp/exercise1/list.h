#include <iostream>

/*typedef unsigned char uint8;*/

class List {
	struct Elem {
		char val;
		Elem* next;
	};

	Elem* header;
	friend class StrList;
	friend class FileList;

public:
	List() {
		header = 0;
	}

	~List() {
		while(header) {
			Elem* t= header;
			header = header->next;
			delete t;
		}
	}

	void print() {
		Elem* p = header;
		for (;; p = p->next) {
			printf("%c ", p->val);
			if (p->next == 0)
				break;
		}
		puts("");
	}

	bool isEmpty() const {
		return header == 0;
	}

	void push_back(char val) {
		Elem* p = new Elem;
		p->val = val;
		p->next = 0;
		
		if (isEmpty()) {
			header = p;
		}
		else {
			Elem* cur = header;
			for (cur = header; cur->next; cur = cur->next);
			cur->next = p;
		}
	}

	void pop_back() {
		if (isEmpty())
			return;

		if (header->next == 0) {
			delete header;
			header = 0;
		}
		else {
			Elem* cur;
			for (cur = header; cur->next->next; cur = cur->next);
			delete cur->next;
			cur->next = 0;
		}
	}

	void push_at(char val, int pos) {
		if (pos < 0)
			return;

		Elem* p = new Elem;
		p->val = val;

		if (isEmpty() || pos == 0) {
			p->next = header;
			header = p;
		}
		else {
			Elem* cur;
			int i = 1;
			for (cur = header, i = 1; i < pos && cur->next; i++, cur = cur->next);
			p->next = cur->next;
			cur->next = p;
		}
	}

	void pop_at(int pos) {
		if (pos < 0 || isEmpty())
			return;

		if (pos == 0) {
			Elem* t = header;
			header = t->next;
			delete t;
		}
		else {
			Elem* cur;
			int i = 1;
			for (cur = header, i = 1; i < pos && cur->next; i++, cur = cur->next);
			Elem* t = cur->next;
			cur->next = t->next;
			delete t;
		}
	}

	char min() {
		if (isEmpty())
			return 0;

		int min = 255;
		for (Elem* cur = header; cur; cur = cur->next) {
			if (cur->val < min)
				min = cur->val;
		}

		return min;
	}

	float avg() {
		if (isEmpty())
			return 0.0;

		int s = 0;
		int c = 0;
		for (Elem* cur = header; cur; cur = cur->next) {
			s += cur->val;
			c++;
		}

		return (float)s / c;
	}

	char at(int i) {
		if (i >= 0 && i <= size()) {
			Elem* p = header;
			for (int j = 0; j < i; j++)
				p = p->next;
			return p->val;
		}
		return 0;
	}

	int size() {
		Elem* p = header;
		int n = 0;
		for(;p->next; p = p->next)
			n++;
		return n;
	}
};