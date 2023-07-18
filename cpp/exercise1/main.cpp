#include <stdio.h>
#include "str.h"

void main() {
	Str str = Str();
	char* a = "hello";
	printf("%d\n",str.length(a));

	str.pop_back(a);

	printf("%s\n", a);
}


