#include <stdio.h>

#define w 50

void star() {
	for(int y = 0; y <= w; y++) {
		for(int x = 0; x <= w; x++)
			printf("%c ", (y > x - 25 && y < x + 25) ? '*' : ' ');
		printf("\n");
	}
}

#define w 80
#define h 70


void star2() {
	for(int y = 0; y <= h / 2; y++) {
		for(int x = 0; x <= w; x++)
			printf("%c", (w / 2 - y <= x && w / 2 + y >= x) ? '*' : ' ');
		printf("\n");
	}
	for (int y = h / 2 + 1; y >= 0; y--) {
		for (int x = 0; x <= w; x++)
			printf("%c", (w / 2 - y <= x && w / 2 + y >= x) ? '*' : ' ');
		printf("\n");
	}
}