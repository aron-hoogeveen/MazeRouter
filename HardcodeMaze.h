#ifndef HARDCODEMAZE_H_
#define HARDCODEMAZE_H_

#include <string.h>
#include "Lee.h"

#define PRINT_NAMES 0
#define PRINT_VALUES 1

void print_route(int start_cellx, int start_celly); /* Should update "int start_cellx, int start_celly" to "Coordinate crd_s" (or "Coordinate *crd_s") */

void set_maze();

void set_maze_names_alt();

void print_maze(int print_mode);

#endif
