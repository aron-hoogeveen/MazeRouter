#include "HardcodeMaze.h"
#include <stdio.h>

extern struct cell maze[MAX_SIZE][MAX_SIZE];

void print_route(int start_cellx, int start_celly)
{
    int steps = maze[start_cellx][start_celly].v;
    int i, x, y;

    x = start_cellx;
    y = start_celly;

    printf("%s ", maze[x][y].name);
    for(i = 1; i < steps; i++)
    {
        if(maze[(x+1)][y].v ==(steps - i))
        {
            x += 2;
            printf("%s ", maze[x][y].name);
            continue;
        }
        if(maze[(x-1)][y].v == (steps - i))
        {
            x -= 2;
            printf("%s ", maze[x][y].name);
            continue;
        }
        if(maze[x][(y+1)].v == (steps - i))
        {
            y += 2;
            printf("%s ", maze[x][y].name);
            continue;
        }
        if(maze[x][(y-1)].v == (steps - i))
        {
            y -= 2;
            printf("%s ", maze[x][y].name);
            continue;
        }
    }
}

void set_maze()
{
    int x, y;

    /*initialize MAZE to -1*/
    for(x = 0; x < MAX_SIZE; x++)
    {
        for(y = 0; y < MAX_SIZE; y++)\
        {
            maze[x][y].v = -1;
        }
    }

    /*printf("----- DEBUG: Maze after initializing to -1 -----\n");
    print_maze(PRINT_VALUES);
    printf("\t\t\t-------------------------------------\n");*/

    /*Manual v declarations*/
    maze[0][4].v = maze[0][6].v = maze[0][8].v = 0;
    maze[1][4].v = maze[1][6].v = maze[1][8].v = 0;

    maze[11][4].v = maze[11][6].v = maze[11][8].v = 0;
    maze[12][4].v = maze[12][6].v = maze[12][8].v = 0;

    maze[4][0].v = maze[6][0].v = maze[8][0].v = 0;
    maze[4][1].v = maze[6][1].v = maze[8][1].v = 0;

    maze[4][11].v = maze[6][11].v = maze[8][11].v = 0;
    maze[4][12].v = maze[6][12].v = maze[8][12].v = 0;

    /*printf("----- DEBUG: Maze after setting 24 manual 0's -----\n");
    print_maze(PRINT_VALUES);
    printf("\t\t\t-------------------------------------\n");*/


    /* ----- Set maze names my way (which is almost the same lol ----- */
    set_maze_names_alt();

    /*printf("----- DEBUG: Maze after setting the road my way -----\n");
    printf("MAZE_VALUES:\n");
    print_maze(PRINT_VALUES);
    printf("MAZE_NAMES:\n");
    print_maze(PRINT_NAMES);
    printf("\t\t\t-------------------------------------\n");*/


    /* ----- I made one piece of code myself so don't want this -----
    strcpy(maze[0][4].name, "9");
    strcpy(maze[0][6].name, "8");
    strcpy(maze[0][8].name, "7");
    strcpy(maze[12][4].name, "1");
    strcpy(maze[12][6].name, "2");
    strcpy(maze[12][8].name, "3");
    strcpy(maze[4][0].name, "10");
    strcpy(maze[6][0].name, "11");
    strcpy(maze[8][0].name, "12");
    strcpy(maze[4][12].name, "6");
    strcpy(maze[6][12].name, "5");
    strcpy(maze[8][12].name, "4");
    */

    /*build road structure for MAZE*/
    /*
    for(x = 2; x < 11; x++)
    {
        if((x%2) == 0)
        {
            for(y = 2; y < 11; y++)
            {
                maze[x][y].v = 0;
                if((y%2) == 0)
                    sprintf(maze[x][y].name, "c%d%d", (x-2)/2, (y-2)/2);
                else
                    sprintf(maze[x][y].name, "e%d%d%d%d", (x-2)/2, (y-3)/2, (x-2)/2, (y-1)/2);
            }
        }
    }
    for(y = 2; y < 11; y++)
    {
        if((y%2) == 0)
        {
            for(x = 2; x < 11; x++)
            {
                maze[x][y].v = 0;
                if((x%2) != 0)
                    sprintf(maze[x][y].name, "e%d%d%d%d", (x-3)/2, (y-2)/2, (x-1)/2, (y-2)/2);
            }
        }
    }
    */
}

void set_maze_names_alt()
{
    int i, j;
    /* Set all the begin/end point names */
    strcpy(maze[0][4].name, "9");
    strcpy(maze[0][6].name, "8");
    strcpy(maze[0][8].name, "7");

    strcpy(maze[4][0].name, "10");
    strcpy(maze[6][0].name, "11");
    strcpy(maze[8][0].name, "12");

    strcpy(maze[4][12].name, "6");
    strcpy(maze[6][12].name, "5");
    strcpy(maze[8][12].name, "4");

    strcpy(maze[12][4].name, "1");
    strcpy(maze[12][6].name, "2");
    strcpy(maze[12][8].name, "3");

    /* Give the crossings and edges names */
    for(i = 0; i < MAX_SIZE - 4; i++)
    {
        /*
         * Even row && even Column ==> crossing
         * Even row && uneven Column ==> edge
         * Uneven Row && even Column ==> edge
         * Uneven Row && uneven Column ==> NOTHING
         */
        if(i%2 == 0)
        {
            for(j = 0; j < MAX_SIZE - 4; j++)
            {
                if(j%2 == 0)
                {
                    /* Crossing */
                    maze[i + 2][j + 2].v = 0; /* Set as road */
                    sprintf(maze[i + 2][j + 2].name, "c%d%d", i/2, j/2);
                }
                else
                {
                    /* Edge */
                    maze[i + 2][j + 2].v = 0; /* Set as road */
                    sprintf(maze[i + 2][j + 2].name, "e%d%d%d%d", i/2, (j-1)/2, i/2, (j+1)/2);
                }
            }
        }
        else
        {
            for(j = 0; j < MAX_SIZE - 4; j++)
            {
                if(j%2 == 0)
                {
                    /* Edge */
                    maze[i + 2][j + 2].v = 0; /* Set as road */
                    sprintf(maze[i + 2][j + 2].name, "e%d%d%d%d", (i-1)/2, j/2, (i+1)/2, j/2);
                }
            }
        }
    }
}

void print_maze(int print_mode)
{
    int i,j;

    if(print_mode == PRINT_VALUES)
    {
        for(i = 0; i < MAX_SIZE; i++)
        {
            for(j = 0; j < MAX_SIZE; j++)
            {
                printf("%d\t", maze[i][j].v);
            }

            printf("\n\n");
        }
    }
    else if(print_mode == PRINT_NAMES)
    {
        for(i = 0; i < MAX_SIZE; i++)
        {
            for(j = 0; j < MAX_SIZE; j++)
            {
                printf("%s\t", maze[i][j].name);
            }

            printf("\n\n");
        }
    }
}
