#include "header.h"

char *mx_str_append(char *str, char symbol) {
	int size = mx_strlen(str) + 1;
	char *s = mx_strnew(size);

	for(int i = 0; i < size; i++) {
		if(i == size - 1) {
			s[i] = symbol;
		}
		else {
			s[i] = str[i];
		}
	}
		
	return s;
}

