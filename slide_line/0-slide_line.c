#include "slide_line.h"

/**
 * slide_line - slides and merges an array of integers like 2048
 * @line: array of integers
 * @size: number of elements in the array
 * @direction: SLIDE_LEFT or SLIDE_RIGHT
 *
 * Return: 1 on success, 0 on failure
 */
int slide_line(int *line, size_t size, int direction)
{
    size_t i, j;

    if (!line || (direction != SLIDE_LEFT && direction != SLIDE_RIGHT))
        return (0);

    if (direction == SLIDE_LEFT)
    {
        /* Slide left */
        for (i = 0; i < size; i++)
        {
            if (line[i] == 0)
                continue;

            /* Move current number as far left as possible */
            j = i;
            while (j > 0 && line[j - 1] == 0)
            {
                line[j - 1] = line[j];
                line[j] = 0;
                j--;
            }

            /* Merge with next number if equal */
            if (j > 0 && line[j - 1] == line[j])
            {
                line[j - 1] *= 2;
                line[j] = 0;
            }
        }
    }
    else if (direction == SLIDE_RIGHT)
    {
        /* Slide right */
        for (i = size; i-- > 0;)
        {
            if (line[i] == 0)
                continue;

            /* Move current number as far right as possible */
            j = i;
            while (j < size - 1 && line[j + 1] == 0)
            {
                line[j + 1] = line[j];
                line[j] = 0;
                j++;
            }

            /* Merge with previous number if equal */
            if (j < size - 1 && line[j + 1] == line[j])
            {
                line[j + 1] *= 2;
                line[j] = 0;
            }
        }
    }

    return (1);
}
