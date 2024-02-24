#pragma once

#include <stdlib.h>
#include <stdbool.h>
#include <unistd.h>
#include <fcntl.h>
#include <sys/stat.h>

typedef struct s_Map{                                                    
	int w;                                                  
	int h;                                                  
	int **dots;                            
}			   t_Map;

void mx_printchar(char c);
void mx_printerr(char *str);
void mx_printerr_exit(char *str);
void mx_printint(int n);
void mx_printstr(const char *s);
void mx_write_to_file(char *path, char *data);
void mx_pathfind_rec(t_Map **map, int x, int y, int n);

bool mx_get_path(t_Map *source, t_Map **dist, int x, int y, int n);
bool mx_isdigit(char c);
bool mx_isspace(char c);

char **mx_check_text(char *text);
char *mx_str_append(char *str, char symbol);
char *mx_strnew(int size);
char *mx_check_map(t_Map *map, int startX, int startY, int endX, int endY);
char *mx_open_file(char *path);

int mx_strlen(char *s);
int mx_get_max_distance(t_Map *map);
int mx_atoi(const char *str);
int mx_get_avg_distance(t_Map *map, int x, int y);

t_Map *mx_map_new(char **map_string);







