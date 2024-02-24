#include "header.h"

char *mx_strnew(int size) {
	char *res = malloc(sizeof(char) * (size + 1));

	for(int i = 0; i < size + 1; i++) {
		res[i] = '\0';
	}

	return res;
}

