
/*
#include <stdio.h>
#include "str_func.h"

void main() {
	//     char *a = "hello";
	//     int len = str_length(a);
	//     printf("str_length : %d\n", len);
	//
	//     char str[] = "HelLo";
	//     str_lower(str);
	//     printf("str_lower : %s\n", str);
	//
	//     char a_compare[] = "abcd";
	//     char b_compare[] = "abcd";
	//     int compare = str_compare(a_compare, b_compare);
	//     printf("str_compare : %d\n", compare);
	//
	//     char src_copy[] = "abcd";
	//     char dst_copy[50];
	//     str_copy(dst_copy, src_copy);
	//     printf("%s\n", dst_copy);

	//     char str_duplicate[] = "adwas";
	//     char* str = str_dup(str_duplicate);
	//     printf("str_dup : %s\n", str);
	//     delete[] str;

	//     char a[100] = "abc";
	//     char b[] = "gef";
	//     str_append(a, b);
	//     printf("str_append : %s\n", a);

	char a[] = "Hello World";
	char b[] = "el";
	char* str = str_find(a, b);
	printf("str_find : %p\n", str);

	// char a[] = "  abc ";
	// str_trim(a);
	// printf("%s\n", a);

	// char a[] = "4143";
	// int n = str_to_int(a);
	// printf("%d\n", n);
}
*/

// -----------------------------------------------------------

/*
#include <stdio.h>
#include "arr.h"

void main() {
	Arr arr;
	arr_alloc(&arr, 5);

	arr_push_back(&arr, 10);
	arr_push_back(&arr, 20);
	arr_push_back(&arr, 30);

	for (int i = 0; i < arr.N; i++) {
		printf("%d ", arr_at(arr, i));
	}
	printf("\n");


	arr_push_at(&arr, 15, 1);
	for (int i = 0; i < arr.N; i++) {
		printf("%d ", arr_at(arr, i));
	}
	printf("\n");

	uint8 minVal = arr_min(&arr);
	printf("%d\n", minVal);


	float avgVal = arr_avg(&arr);
	printf("%.2f\n", avgVal);


	arr_pop_back(&arr);
	for (int i = 0; i < arr.N; i++) {
		printf("%d ", arr_at(arr, i));
	}
	printf("\n");

	arr_free(&arr);
}

*/

// ----------------------------------------------------

/*
#include <stdio.h>
#include "arr2.h"

typedef unsigned char uint8;

void main() {
	Arr2 arr;
	arr_alloc(&arr);

	arr_push_back(&arr, 10);
	arr_push_back(&arr, 20);
	arr_push_back(&arr, 30);
	arr_push_back(&arr, 40);

	for (int i = 0; i < arr.N; i++) {
		printf("%d ", arr.A[i]);
	}
	printf("\n");

	arr_push_at(&arr, 15, 1);
	for (int i = 0; i < arr.N; i++) {
		printf("%d ", arr.A[i]);
	}
	printf("\n");

	uint8 minVal = arr_min(&arr);

	float avgVal = arr_avg(&arr);
	printf("%.2f\n", avgVal);

	arr_pop_back(&arr);
	for (int i = 0; i < arr.N; i++) {
		printf("%d ", arr.A[i]);
	}
	printf("\n");

	arr_free(&arr);
}

*/


// ---------------------------------------------

/*
#include <stdio.h>
#include "heap.h"
#include "str_func.h"

void main() {
	Heap heap;
	heap_init(&heap);

 	char* heap1 = heap_alloc(&heap, 3);
 	if (heap1 != NULL) {
 		printf("heap1 메모리 1 size: %d : %s\n", 10, heap1);
		printf("%p\n", heap1);
	}
	else {
		printf("heap1 실패\n");
	}

	char* heap2 = heap_alloc(&heap, 3);
	if (heap2 != NULL) {
		printf("heap2 메모리 size: %d : %s\n", 50, heap2);
	}
	else {
		printf("heap2 실패.\n");
	}

	char* heap3 = heap_alloc(&heap, 3);
	if (heap3 != NULL) {
		printf("heap3 메모리 size: %d : %s\n", 10, heap3);
	}
	else {
		printf("heap3 실패.\n");
	}

	char* heap4 = heap_alloc(&heap, 3);
	if (heap4 != NULL) {
		printf("heap4 메모리 size: %d : %s\n", 20, heap3);
	}
	else {
		printf("heap4 실패.\n");
	}

	heap_free(heap2);
	printf("heap2 free\n");
	heap_free(heap4);
	printf("heap4 free\n");
	heap_free(heap3);
	printf("heap3 free\n");
	heap_free(heap1);
	printf("heap1 free\n");

	char* heap5 = heap_alloc(&heap, 200);
	if (heap5 != NULL) {
		printf("heap5 메모리 size: %d : %s\n", 200, heap3);
	}
	else {
		printf("heap5 실패.\n");
	}

	heap_free(heap5);
	printf("heap5 free\n");
}


*/
