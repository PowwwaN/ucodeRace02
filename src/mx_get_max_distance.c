#include "header.h"

int mx_get_max_distance(t_Map *map){
	int max = -1;
	
	for(int i = 0; i < map->h; i++) {
		for(int j = 0; j < map->w; j++) {
			if(map->dots[i][j] > max) {
				max = map->dots[i][j];
			}
		}
	}

	return max;
}

