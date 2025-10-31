#include "slide_line.h"

int slide_line(int *line, size_t size, int direction)
{
    int *place_here = line;
    int *i;

    if (direction == SLIDE_LEFT)
    {
        for (i = line; i < line + size; i++)
        {
            if (*i == 0)
                continue;

            // Si place_here n'est pas i, on "glisse" le nombre
            if (place_here != i)
            {
                *place_here = *i;
                *i = 0;
            }

            // Fusion possible
            if ((place_here + 1) < (line + size) && *place_here == *(place_here + 1))
            {
                *place_here *= 2;
                *(place_here + 1) = 0;
            }

            place_here++;
        }
    }
    return (1);
}
