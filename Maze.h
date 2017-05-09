#ifndef MAZE_H_
#define MAZE_H_

struct cell
{
    int     v;
    char    name[8];
};

cell set_maze(int MAX_SIZE);    /* Better would be a MAX_COLUMNS and a MAX_ROWS to allow non square mazes */

#endif
