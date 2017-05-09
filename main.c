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
    Coordinate *crd_s, *crd_m, *crd_t, *crd_e;
    char edge[8], start[8], mid[8], end[8];
    int i, num, ro_1, ro_2;


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



    /* Get the start, intermediate and target/end point */
    scanf("%s %s %s", start, mid, end);

    if((crd_s = find_cell_name(start)) == NULL)
    {
        fprintf(stderr, "Error: this start point does not exist!\n");
        exit(1);
    }
    if ((crd_m = find_cell_name(mid)) == NULL)
    {
        fprintf(stderr, "Error: this intermediate point does not exist!\n");
        exit(1);
    }
    if((crd_t = find_cell_name(end)) == NULL)
    {
        fprintf(stderr, "Error: this end point does not exist!\n");
        exit(1);
    }


    /* We want to take the shortest path, so calculate the three possible paths (A-B, A-C, B-C) */
    /*A to B*/
    expand(*crd_s, *crd_m);
    ro_1 = maze[crd_s->row][crd_s->column].v;

    reset_maze();

    /*A to C*/
    expand(*crd_s, *crd_t);
    ro_2 = maze[crd_s->row][crd_s->column].v;
    /* Check which road is smaller */
    if (ro_2 < ro_1)
    {
        trace_back(*crd_s, *crd_t);

        reset_maze();

        expand(*crd_t, *crd_m);
        trace_back(*crd_t, *crd_m);
    }
    else
    {
        reset_maze();

        expand(*crd_s, *crd_m);
        trace_back(*crd_s, *crd_m);

        reset_maze();

        expand(*crd_m, *crd_t);
        trace_back(*crd_m, *crd_t);
    }


    /* Fill in the matrix with path values */
    /* A to B
    expand(*crd_s, *crd_m);
    trace_back(*crd_s, *crd_m);

    reset_maze();
    */
    /* B to C
    expand(*crd_m, *crd_t);
    trace_back(*crd_m, *crd_t);
    */





    return 0;
}
