#include <stdio.h>

#define MaxHeapL 1000

typedef struct {
	char pool[MaxHeapL];
} Heap;

void heap_init(Heap* h) {
	h->pool[0] = 'f';
	*((int*)(h->pool + 1)) = MaxHeapL - sizeof(char) - sizeof(int);
}


char* heap_alloc(Heap* h, int sz) {
	char* cur = h->pool;
	if (sz > MaxHeapL - 5)
		return 0;

	while (*cur <= h->pool[MaxHeapL]) {
		if (*cur == 'f') {
			int* memory_len = (int*)(cur + 1);
			int free_sz = *memory_len;
			if (free_sz >= sz + 5) {
				*cur = 'a';
				*memory_len = sz;

				char* memory_p = cur + 5;

				int space = free_sz - sz -5;
				if (space > 5) {
					char* next = cur + sz + 5;
					*next = 'f';
					*((int*)(next + 1)) = space - 5;
				}
				return memory_p;
			}
			cur += free_sz + 5;
		}
		else {
			int* memory_len = (int*)(cur + 1);
			cur += *memory_len + 5;
		}
	}
	return 0;
}



void heap_free(char* p) {
	char* cur = p - 5;
	*cur = 'f';
	int* memory_len = (int*)(cur + 1);

	char* next = cur + *memory_len + 5;
	if (*next == 'f') {
		int* next_memory_len = (int*)(next + 1);

		*memory_len += *next_memory_len + 5;
		*next = 0;
		*next_memory_len = 0;
		
		for (int i = 1; i <= MaxHeapL - *memory_len; i++) {
			if (*(cur - i) == 'f') {
				int* before_memory_len = (int*)(cur - i + 1);
				*before_memory_len += *memory_len + 5;
				*cur = 0;
				*memory_len = 0;
				break;
			} 
			if(*(cur- i) == 'a'){
				break;
			}
		}
	}
}