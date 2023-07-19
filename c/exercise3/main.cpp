#include <stdio.h>
#include "bmp.h"
/*#include "list.h"*/

void main() {
	BinImg bin;

	bim_init(&bin);

	bim_alloc(&bin, 16, 12);

	uint8 a = at(&bin, 16, 12);
/*	printf("%d", a);*/

/*	fillRect(&bin, 1, 1, 2, 2, 1);*/

// 	drawRect(&bin, 8, 2, 18, 3, 1);

	drawCircle(&bin, 3, 5, 7, 1);

	draw(&bin);


// 	flip_vertical(&bin);
// 	flip_horizontal(&bin);

// 	rotate90(&bin, 1);
// 
// 	printf("1------------------------");
// 
// 	draw(&bin);


// 	rotate90(&bin, 2);
// 
// 	printf("2------------------------");
// 	draw(&bin);
// 
// 	rotate90(&bin, 3);
// 
// 	printf("3------------------------");
// 	draw(&bin);
// 
// 	rotate90(&bin, 4);
// 
// 
// 	printf("------------------------");

/*	free(&bin);*/


// 	List list;
// 	list.header = 0;
// 
// 	list_push_back(&list, 35);
// 	list_push_back(&list, 30);
// 	list_push_back(&list, 25);
// 	list_push_back(&list, 20);
// 	list_push_back(&list, 15);
// 	list_push_back(&list, 10);
// 
// 	list_view(&list);
// 	printf("--------------35 30 25 20 15 10 --------------\n");
// 
// 	list_push_at(&list, 100, 3);
// 
// 	list_view(&list);
// 	printf("--------------35 30 25 100 20 15 10 --------------\n");
// 
// 	printf("min: %d\n", list_min(&list));
// 	printf("avg: %.4f\n", list_avg(&list));
// 
// 	list_pop_at(&list, 2);
// 
// 	list_view(&list);
// 	printf("--------------35 30 25 100 20 15 10 --------------\n");
// 
// 	printf("min: %d\n", list_min(&list));
// 	printf("avg: %.4f\n", list_avg(&list));
// 
// 	list_pop_back(&list);
// 
// 	list_view(&list);
// 	printf("--------------30 25 100 20 15 --------------\n");
// 
// 	printf("min: %d\n", list_min(&list));
// 	printf("avg: %.4f\n", list_avg(&list));
}