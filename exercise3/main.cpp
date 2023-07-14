#include <stdio.h>
#include "bmp.h"

void main() {
	BinImg bin;

	bim_init(&bin);

	bim_alloc(&bin, 16, 16);

	uint8 a = at(&bin, 16, 16);
	printf("%d", a);

/*	fillRect(&bin, 2, 2, 6, 3, 1);*/

	drawRect(&bin, 2, 2, 6, 3, 1);
}