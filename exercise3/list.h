#include <stdio.h>

typedef unsigned char uint8;

typedef struct elem {
	uint8 val;
	elem* next;
} Elem;

typedef struct {
	elem* header;
} List;

void list_view(List* list) {
	elem* p = list->header;
	for (;; p = p->next) {
		int a = p->val;
		printf("%d ", a);
		if (p->next == 0)
			break;
	}
	puts("");
}

bool list_isEmpty(List* list) {
	return list->header == 0;
}

void list_push_back(List* list, uint8 val) {
	
	elem* p = new elem[sizeof(elem)];
	p->val = val;
	p->next = 0;

	if (list_isEmpty(list)) {
		list->header = p;
	} else {
		elem* cur;
		for (cur = list->header; cur->next; cur = cur->next);
		cur->next = p;
	}
}

void list_pop_back(List* list) {
	if (list_isEmpty(list))
		return;

	elem* cur;
	for (cur = list->header; cur->next && cur->next->next; cur = cur->next);

	if (cur->next != 0) {
		delete cur->next;
		cur->next = 0;
	}
	else {
		delete list->header;
		list->header = 0;
	}
}

void list_push_at(List* list, uint8 val, int pos) {
	if(pos < 0)
		return;

	elem* p = new elem[sizeof(elem)];
	p->val = val;

	if(list_isEmpty(list) || pos == 0) {
		p->next = list->header;
		list->header = p;
	} 
	else {
		elem* cur;
		int i;
		for(cur = list->header, i = 1; i < pos && cur->next; i++, cur = cur->next);
		p->next = cur->next;
		cur->next = p;
	}
}

void list_pop_at(List* list, int pos) {
	if(pos < 0 || list_isEmpty(list))
		return;

	if(pos == 0) {
		elem* t = list->header;
		list->header = t->next;
		delete t;
	} else {
		elem* cur;
		int i;
		for(cur = list->header, i = 1; i < pos && cur->next; i++, cur = cur->next);
		elem* t = cur->next;
		cur->next = t->next;
		delete t;
	}


}

uint8 list_min(List* list) {
	if (list_isEmpty(list))
		return 0;

	uint8 min = 255;
	for (elem* cur = list->header; cur; cur = cur->next) {
		if (cur->val < min)
			min = cur->val;
	}

	return min;
}

float list_avg(List* list) {
	if (list_isEmpty(list))
		return 0.0;
	int s = 0;
	int c = 0;
	for (elem* cur = list->header; cur; cur = cur->next) {
		s += cur->val;
		c++;
	}

	return (float)s / c;
}

