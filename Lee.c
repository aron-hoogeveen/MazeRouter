#include "Lee.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

struct cell maze[MAX_SIZE][MAX_SIZE];

Coordinate *init_Coordinate (void)
{
    Coordinate *ptr_crd = malloc(sizeof(*ptr_crd));

    if(ptr_crd == NULL)
    {
        fprintf(stderr, "Error: Out of memmory!\n");
        exit(1);
    }

    return ptr_crd;

}

void expand(Coordinate start, Coordinate target)
{
    int i = 1, j, k;
    Coordinate *crd = init_Coordinate();

    /* Mark target cell with value i */
    maze[target.row][target.column].v = i;

    while(maze[start.row][start.column].v == 0)
    {
        /* The following is inefficient but is the easiest way to change all cells right */
        /* Check every cells' value for i */
        for(j = 0; j < MAX_SIZE; j++)
        {
            for(k = 0; k < MAX_SIZE; k++)
            {
                if(maze[j][k].v == i)
                {
                    crd->row = j;
                    crd->column = k;
                    change_neighbour(crd, i);
                }
            }
        }
        i++;
    }
}

void reset_maze()
{
    int i, j;
    /* set every value > 0 to 0 */
    for(i = 0; i < MAX_SIZE; i++)
    {
        for (j = 0; j < MAX_SIZE; j++)
        {
            if(maze[i][j].v > 0)
                maze[i][j].v = 0;
        }
    }
}

void trace_back(Coordinate start, Coordinate target)
{
    int i = maze[start.row][start.column].v;
    Coordinate crd = start;

    /* Print the starting points' name */
    printf("%s ", maze[start.row][start.column].name);

    /* We know that the target cell has value 1 */
    while(maze[crd.row][crd.column].v != 1)
    {
        /* Go to a neighbour with a lower value */
        if(maze[crd.row - 1][crd.column].v == (i - 1)) {
            crd.row -= 1;
            if(strncmp(maze[crd.row][crd.column].name, "e", 1) != 0)
                printf("%s ", maze[crd.row][crd.column].name);      /* only print the crossings */
            i--;
            continue;
        }
        if(maze[crd.row + 1][crd.column].v == (i - 1)) {
            crd.row += 1;
            if(strncmp(maze[crd.row][crd.column].name, "e", 1) != 0)
                printf("%s ", maze[crd.row][crd.column].name);      /* only print the crossings */
            i--;
            continue;
        }
        if(maze[crd.row][crd.column - 1].v == (i - 1)) {
            crd.column -= 1;
            if(strncmp(maze[crd.row][crd.column].name, "e", 1) != 0)
                printf("%s ", maze[crd.row][crd.column].name);      /* only print the crossings */
            i--;
            continue;
        }
        if(maze[crd.row][crd.column + 1].v == (i - 1)) {
            crd.column += 1;
            if(strncmp(maze[crd.row][crd.column].name, "e", 1) != 0)
                printf("%s ", maze[crd.row][crd.column].name);      /* only print the crossings */
            i--;
            continue;
        }

        /* If we reach here that means that we can not reach the target cell */
        fprintf(stderr, "Error: we can not reach the target!\n");
        exit(1);
    }
    /* Reached target cell */
    /*printf("%s ", maze[crd.row][crd.column].name); Do not print this as the target cell will already be printed in the loop above */
    printf("\n");
}

void change_neighbour(Coordinate *c_cell, int value)
{
    if(maze[(c_cell->row) -1][(c_cell->column)].v == 0)
        maze[(c_cell->row) -1][(c_cell->column)].v = value +1;
    if(maze[(c_cell->row) +1][(c_cell->column)].v == 0)
        maze[(c_cell->row) +1][(c_cell->column)].v = value + 1;
    if(maze[(c_cell->row)][(c_cell->column) -1].v == 0)
        maze[(c_cell->row)][(c_cell->column) -1].v = value + 1;
    if(maze[(c_cell->row)][(c_cell->column) +1].v == 0)
        maze[(c_cell->row)][(c_cell->column) +1].v = value + 1;
}

Coordinate *find_cell_value(int value)
{
    int i, j;
    Coordinate *c = init_Coordinate();

    for(i = 0; i < MAX_SIZE; i++)
    {
        for(j = 0; j < MAX_SIZE; j++)
        {
            if(maze[i][j].v == value)
            {
                c->row = i;
                c->column = j;

                return c;
            }
        }
    }

    return NULL;
}

Coordinate *find_cell_name(char name[8])
{
    int i, j;
    Coordinate *c = init_Coordinate();

    for(i = 0; i < MAX_SIZE; i++)
    {
        for(j = 0; j < MAX_SIZE; j++)
        {
            if(strcmp(maze[i][j].name, name) == 0)
            {
                c->row = i;
                c->column = j;

                return c;
            }
        }
    }

    return NULL;
}
