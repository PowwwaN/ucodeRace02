#include "header.h"

t_Map *mx_map_new(char **map_string){
	t_Map *map = malloc(sizeof(t_Map));

	map->w = 0;
	map->h = 0;

	for(char **i = map_string; *i != NULL; i++){
		if(map->w == 0) {
			map->w = mx_strlen(*i);
		}

		else if(map->w != mx_strlen(*i)) {
			mx_printerr_exit("map error\n");
		}

		map->h++;
	}

	map->dots = malloc(sizeof(int*) * map->h);

	for(int i = 0; i < map->h; i++){

		map->dots[i] = malloc(sizeof(int) * map->w);

		for(int j = 0; j < map->w; j++) {
			if(map_string[i][j] == '#') {
				map->dots[i][j] = -2;
			}

			if(map_string[i][j] == '.') {
				map->dots[i][j] = -1;
			}
		}
	}

	return map;
}

