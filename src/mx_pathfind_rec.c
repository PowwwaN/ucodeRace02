#include "header.h"

void mx_pathfind_rec(t_Map **map, int x, int y, int n) {
	if(x < 0 || x >= (*map)->w || 
	   y < 0 || y >= (*map)->h) {
		return;
	}

	if((*map)->dots[y][x] == -2) {
		return;
	}

	if((*map)->dots[y][x] == -1) {
		(*map)->dots[y][x] = n;
	}
	
	if(y + 1 < (*map)->h && ((*map)->dots[y + 1][x] == -1 || (*map)->dots[y + 1][x] > n + 1)) {
		(*map)->dots[y + 1][x] = n + 1;
	}
		
	if(y - 1 >= 0 && ((*map)->dots[y - 1][x] == -1 || (*map)->dots[y - 1][x] > n + 1)) {
		(*map)->dots[y - 1][x] = n + 1;
	}
		
	if(x + 1 < (*map)->w && ((*map)->dots[y][x + 1] == -1 || (*map)->dots[y][x + 1] > n + 1)) {
		(*map)->dots[y][x + 1] = n + 1;
	}
		
	if(x - 1 >= 0 && ((*map)->dots[y][x - 1] == -1 || (*map)->dots[y][x - 1] > n + 1)) {
		(*map)->dots[y][x - 1] = n + 1;
	}
	
	if(y + 1 < (*map)->h && ((*map)->dots[y + 1][x] >= n + 1)) {
		mx_pathfind_rec(map, x, y + 1, n + 1);
	}

	if(y - 1 >= 0 && ((*map)->dots[y - 1][x] >= n + 1)) {
		mx_pathfind_rec(map, x, y - 1, n + 1);
	}

	if(x + 1 < (*map)->w && ((*map)->dots[y][x + 1] >= n + 1)) {
		mx_pathfind_rec(map, x + 1, y, n + 1);
	}

	if(x - 1 >= 0 && ((*map)->dots[y][x - 1] >= n + 1)) {
		mx_pathfind_rec(map, x - 1, y, n + 1);
	}
}

