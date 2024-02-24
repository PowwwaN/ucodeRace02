#include "header.h"

void mx_write_to_file(char *path, char *data) {
	int fd = open(path, O_CREAT | O_EXCL | O_WRONLY, S_IRUSR | S_IWUSR);
	write(fd, data, mx_strlen(data));

    close(fd);
}

