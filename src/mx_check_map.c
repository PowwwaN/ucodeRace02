#include "header.h"

char *mx_check_map(t_Map *map, int startX, int startY, int endX, int endY){
	mx_pathfind_rec(&map, startX, startY, 0);
	t_Map *path = NULL;

	if(!mx_get_path(map, &path, endX, endY, 0)) {
		return NULL;
	}

	int max_distance = mx_get_max_distance(map);
	char *result = mx_strnew(0);

	for(int i = 0; i < map->h; i++) {
		for(int j = 0; j < map->w; j++) {
			if(map->dots[i][j] == -2) {
				result = mx_str_append(result, '#');
			}

			else if(map->dots[i][j] == -1) {
				result = mx_str_append(result, '.');
			}

			else {
				if(map->dots[i][j] == max_distance) {
					if(path->dots[i][j] == 1) {
						result = mx_str_append(result, 'X');
					}
					else {
						result = mx_str_append(result, 'D');
					}
				}

				else {
					if(path->dots[i][j] == 1) {
						result = mx_str_append(result, '*');
					}
					else {
						result = mx_str_append(result, '.');
					}
				}	
			}
		}
		result = mx_str_append(result, '\n');
	}

	return result;
}
