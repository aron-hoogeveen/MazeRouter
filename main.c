/* An Example Input
 *   2 e2030 e2324
 *   10 12
 *
 * An Example Output
 *   10 c10 c20 c21 c31 c30 12
 *   10 c10 c11 c21 c31 c30 12
 */


#include <stdio.h>
#include <stdlib.h>
#include "Lee.h"
#include "HardcodeMaze.h"

extern struct cell maze[MAX_SIZE][MAX_SIZE];

int main()
{
    Coordinate *crd_s, *crd_1, *crd_2, *crd_3, *crd_e;
    char edge[8], start[8], checkpoint1[8], checkpoint2[8], checkpoint3[8];
    int i, num, route_length_s1, route_length_s2, route_length_s3, route_length_12, route_length_13, route_length_21, route_length_23, route_length_31, route_length_32;


    /* Set the coordinates from which to expand */
    /*crd_s->row = 4;
    crd_s->column = 0;
    crd_t->row = 8;
    crd_t->column = 12;*/

    set_maze();

    /* Check if everything went well */
    print_maze(PRINT_NAMES);

    /* # of edges to block */
    scanf("%d", &num);

    for(i = 0; i < num; i++)
    {
        /* Get edge */
        scanf("%s", edge);

        if((crd_e = find_cell_name(edge)) == NULL)
        {
            fprintf(stderr, "Error: this edge does not exist!\n");
            exit(1);
        }

        /* Make the edges' value -1 */
        maze[crd_e->row][crd_e->column].v = -1;
    }



    /* Get the start and the 3 checkpoints */
    scanf("%s %s %s %s", start, checkpoint1, checkpoint2, checkpoint3);

    if((crd_s = find_cell_name(start)) == NULL)
    {
        fprintf(stderr, "Error: this start point does not exist!\n");
        exit(1);
    }
    if ((crd_1 = find_cell_name(checkpoint1)) == NULL)
    {
        fprintf(stderr, "Error: checkpoint 1 does not exist!\n");
        exit(1);
    }
     if ((crd_2 = find_cell_name(checkpoint2)) == NULL)
    {
        fprintf(stderr, "Error: checkpoint 2 does not exist!\n");
        exit(1);
    }
    if ((crd_3 = find_cell_name(checkpoint3)) == NULL)
    {
        fprintf(stderr, "Error: checkpoint 3 does not exist!\n");
        exit(1);
    }


    /* We want to take the shortest path, so calculate the three possible paths (start -> 1, start -> 2, start -> 3) */
    /*Calculate length from start -> 1*/
    expand(*crd_s, *crd_1);
    route_length_s1 = maze[crd_s->row][crd_s->column].v;

    reset_maze();

    /*Calculate length from start -> 2*/
    expand(*crd_s, *crd_2);
    route_length_s2 = maze[crd_s->row][crd_s->column].v;

    reset_maze();


    /*Calculate length from start -> 3*/
    expand(*crd_s, *crd_3);
    route_length_s3 = maze[crd_s->row][crd_s->column].v;


    /*Check which road is smaller*/
    if (route_length_s1 <= route_length_s2 && route_length_s1 <= route_length_s3)
    {
        reset_maze();

        expand(*crd_s, *crd_1);
        trace_back(*crd_s, *crd_1);


        /*calculate length from 1 -> 2*/
        reset_maze();

        expand(*crd_1, *crd_2);
        route_length_12 = maze[crd_1->row][crd_1->column].v;

        /*calculate length from 1 -> 3*/
        reset_maze();

        expand(*crd_1, *crd_3);
        route_length_13 = maze[crd_1->row][crd_1->column].v;

            if (route_length_12 < route_length_13)
            {
                reset_maze();

                expand(*crd_1, *crd_2);
                trace_back(*crd_1, *crd_2);

                reset_maze();

                expand(*crd_2, *crd_3);
                trace_back(*crd_2, *crd_3);
            }
            else
            {
                reset_maze();

                expand(*crd_1, *crd_3);
                trace_back(*crd_1, *crd_3);

                reset_maze();

                expand(*crd_3, *crd_2);
                trace_back(*crd_3, *crd_2);
            }
    }

    else if (route_length_s2 <= route_length_s1 && route_length_s2 <= route_length_s3)
    {
        reset_maze();

        expand(*crd_s, *crd_2);
        trace_back(*crd_s, *crd_2);

        /*calculate length from 2 -> 1*/
        reset_maze();

        expand(*crd_2, *crd_1);
        route_length_21 = maze[crd_2->row][crd_2->column].v;

        /*calculate length from 2 -> 3*/
        reset_maze();

        expand(*crd_2, *crd_3);
        route_length_23 = maze[crd_2->row][crd_2->column].v;

            if (route_length_21 < route_length_23)
            {
                reset_maze();

                expand(*crd_2, *crd_1);
                trace_back(*crd_2, *crd_1);

                reset_maze();

                expand(*crd_1, *crd_3);
                trace_back(*crd_1, *crd_3);
            }
            else
            {
                reset_maze();

                expand(*crd_2, *crd_3);
                trace_back(*crd_2, *crd_3);

                reset_maze();

                expand(*crd_3, *crd_1);
                trace_back(*crd_3, *crd_1);
            }
    }

    else if (route_length_s3 <= route_length_s1 && route_length_s3 <= route_length_s2)
    {
        reset_maze();

        expand(*crd_s, *crd_3);
        trace_back(*crd_s, *crd_3);



        /*calculate length from 3 -> 1*/
        reset_maze();

        expand(*crd_3, *crd_1);
        route_length_31 = maze[crd_3->row][crd_3->column].v;

        /*calculate length from 3 -> 2*/
        reset_maze();

        expand(*crd_3, *crd_2);
        route_length_32 = maze[crd_3->row][crd_3->column].v;

            if (route_length_31 < route_length_32)
            {
                reset_maze();

                expand(*crd_3, *crd_1);
                trace_back(*crd_3, *crd_1);

                reset_maze();

                expand(*crd_1, *crd_2);
                trace_back(*crd_1, *crd_2);
            }
            else
            {
                reset_maze();

                expand(*crd_3, *crd_2);
                trace_back(*crd_3, *crd_2);

                reset_maze();

                expand(*crd_2, *crd_1);
                trace_back(*crd_2, *crd_1);
            }

    }

    return 0;
}
