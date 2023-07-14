#include <stdio.h>


int str_length(char* str) {
	int n = 0;
	for (char* p = str; *p; p++)
		n++;
	return n;
}

void str_lower(char* str) {
	for (char* p = str; *p; p++) {
		if (*p < 'a')
			*p += ('a' - 'A');
	}
}

int str_compare(char* a, char* b) {
	int i;
	for (i = 0; a[i] && b[i]; i++) {
		if (a[i] != b[i])
			return 0;
	}
	return a[i] == b[i];
}

void str_copy(char* dst, char* src) {
	for (char* p = src; *p; p++)
		*dst++ = *p;
	*dst = 0;
}

char* str_dup(char* str) {
	int n = 0;
	while (str[n] != 0)
		n++;
	char* buf = new char[n + 1];

	for (char* p = str; *p; p++)
		*buf++ = *p;
	*buf = 0;
	return buf - n;
}

void str_append(char* str, char* str2) {
	for (char* p = str; *p; p++)
		str++;
	for (char* p = str2; *p; p++)
		*str++ = *p;
	*str = 0;
}

char* str_find(char* str, char* sub) {
	if (*sub == 0)
		return NULL;
	for (int i = 0; str[i]; i++) {
		if (str[i] == *sub) {
			int j;
			for (j = 0; str[i] == sub[j] && sub[j]; str[i++], j++);
			if (sub[j] == 0)
				return &str[i];
		}
	}
	return NULL;
}

void str_trim(char* str) {
	char* start = str;
	for (char* p = start; *p == ' '; p++)
		start++;

	char* end = start;
	for (; *end; end++);
	for (end--; *end == ' '; end--);
	*(end + 1) = 0;

	char* p = str;
	for (; *start; start++, p++)
		*p = *start;
	*p = 0;
}

int str_to_int(char* str) {
	int n = 0;
	for (char* p = str; *p; p++) {
		if (*p >= '0' && *p <= '9') {
			n = n * 10 + (*p - '0');
		}
		else {
			return 0;
		}
	}
	return n;
}