#include "slide_line.h"

int slide_line(int *line, size_t size, int direction)
{
	int *place_here = NULL;
	int *left = NULL;
	int *right = NULL;

	if (direction == SLIDE_LEFT)
	{
		place_here = line;
		left = line;

		while (left < line + size)
		{
			// skip zeros
			if (*left == 0)
			{
				left++;
				continue;
			}

			right = left + 1;
			while (right < line + size && *right == 0)
				right++;

			if (right < line + size && *right == *left)
			{
				*place_here = *left * 2;
				*left = 0;
				*right = 0;
				place_here++;
				left = right + 1;
			}
			else
			{
				if (place_here != left)
				{
					*place_here = *left;
					*left = 0;
				}
				place_here++;
				left++;
			}
		}
	}
	return (1);
}
