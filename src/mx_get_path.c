#include "header.h"

bool mx_get_path(t_Map *source, t_Map **dist, int x, int y, int n){
	if(*dist == NULL) {
		*dist = malloc(sizeof(t_Map));
		(*dist)->w = source->w;
		(*dist)->h = source->h;
		(*dist)->dots = malloc(sizeof(int*) * source->h);

		for(int i = 0; i < source->h; i++) {
			(*dist)->dots[i] = malloc(sizeof(int) * source->w);

			for(int j = 0; j < source->w; j++) {
				(*dist)->dots[i][j] = 0;
			}
		}

		n = source->dots[y][x];

		if(source->dots[y][x] < 0) {
			return false;
		}

		(*dist)->dots[y][x] = 1;
	}
	
	if(source->dots[y][x] == 0){
		(*dist)->dots[y][x] = 1;
		return true;
	}

	if(x + 1 < source->w && source->dots[y][x + 1] == n - 1) {
		(*dist)->dots[y][x + 1] = 1;
		return mx_get_path(source, dist, x + 1, y, n - 1);
	}
		
	if(x - 1 >= 0 && source->dots[y][x - 1] == n - 1) {
		(*dist)->dots[y][x - 1] = 1;
		return mx_get_path(source, dist, x - 1, y, n - 1);
	}	
		
	if(y + 1 < source->h && source->dots[y + 1][x] == n - 1) {
		(*dist)->dots[y + 1][x] = 1;
		return mx_get_path(source, dist, x, y + 1, n - 1);
	}
		
	if(y - 1 >= 0 && source->dots[y - 1][x] == n - 1) {
		(*dist)->dots[y - 1][x] = 1;
		return mx_get_path(source, dist, x, y - 1, n - 1);
	}

	return false;
}

