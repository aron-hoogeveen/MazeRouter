#ifndef LEE_H_
#define LEE_H_

#define MAX_SIZE 13

/* ----- MAZE ----- */
struct cell
{
    int     v;
    char    name[8];
};
/* ----- END MAZE ----- */


/* ----- COORDINATES ----- */
typedef struct Coordinate_t Coordinate;

struct Coordinate_t
{
    int     row;
    int     column;
};

Coordinate *init_Coordinate (void);
/* ----- END COORDINATES ----- */


/* ----- LEE ----- */
void expand(Coordinate start, Coordinate target);

void reset_maze();

void trace_back(Coordinate start, Coordinate target);

void change_neighbour(Coordinate *c_cell, int value);

Coordinate *find_cell(int value);

Coordinate *find_cell_name(char name[8]);
/* ----- END LEE ----- */




#endif
