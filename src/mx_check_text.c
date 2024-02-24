#include "header.h"

char **mx_check_text(char *text){
	int h = 0;
	for(char *i = text; *i != '\0'; i++) {
		if(*i == '\n') {
			h++;
		}
	}

	char **result = malloc(sizeof(char*) * (h + 1));
	char *temp = mx_strnew(0);
	int result_index = 0;

	for(char *i = text; *i != '\0'; i++) {	
		if(*i == '\n') {
			result[result_index++] = temp; 
			temp = mx_strnew(0);
		}
		
		else if(*i == '#' || *i == '.') {
			temp = mx_str_append(temp, *i);
		}
	}

	result[result_index] = NULL;
	return result;
}

