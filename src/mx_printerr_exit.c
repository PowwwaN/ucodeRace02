#include "header.h"

void mx_printerr_exit(char *str) {
	write(2, str, mx_strlen(str));
	exit(0);
}

