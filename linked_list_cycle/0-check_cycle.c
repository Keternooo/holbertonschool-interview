#include "lists.h"

int check_cycle(listint_t *list)
{
	listint_t *temp, *check = list;

	if (!list)
		return (0);

	temp = list->next;

	while(temp)
	{
		if(list->next == temp)
			temp = list->next->next;
		else
			temp = list->next;

		if(check->next == temp)
			return (1);
	}

	return (0);
}
