#include "header.h"

char *mx_open_file(char *path) {
	int fd = open(path, O_RDWR);

	if(fd < 0) {
		mx_printerr_exit("map does not exist\n");
	}

	char ch;
	int ref;
	char *result = mx_strnew(0);

	while ((ref = read(fd, &ch, 1)) > 0) {
		if (ref < 0) {
			mx_printerr_exit("map does not exist\n");
		}

		if(ch != '#' && ch != '.' && ch != ',' && ch != '\n' && ch != '\r') {
			mx_printerr_exit("map error\n");
		}

		if(ch != '\r') {
			result = mx_str_append(result, ch);
		}
	}
	
	close(fd);
	return result;
}

