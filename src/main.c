#include "header.h"

int main(int argc, char *argv[]) {
  if (argc != 6) {
    mx_printerr_exit("usage: ./way_home [file_name] [x1] [y1] [x2] [y2]\n");
  }

  int x1 = mx_atoi(argv[2]);
  int y1 = mx_atoi(argv[3]);
  int x2 = mx_atoi(argv[4]);
  int y2 = mx_atoi(argv[5]);

  char *map_string = mx_open_file(argv[1]);
  char **p = mx_check_text(map_string);
  t_Map *map = mx_map_new(p);

  if (x1 < 0 || x1 >= map->w || x2 < 0 || x2 >= map->w || y1 < 0 ||
      y1 >= map->h || y2 < 0 || y2 >= map->h) {
    mx_printerr_exit("points are out of map range\n");
  }

  if (map->dots[y1][x1] == -2) {
    mx_printerr_exit("entry point cannot be an obstacle\n");
  }

  if (map->dots[y2][x2] == -2) {
    mx_printerr_exit("exit point cannot be an obstacle\n");
  }

  char *result = mx_check_map(map, x1, y1, x2, y2);

  if (result == NULL) {
    mx_printerr_exit("route not found\n");
  }

  mx_printstr("dist=");
  mx_printint(mx_get_max_distance(map));
  mx_printchar('\n');

  mx_printstr("exit=");
  mx_printint(mx_get_avg_distance(map, x2, y2));
  mx_printchar('\n');

  mx_write_to_file("path.txt", result);

  return 0;
}
