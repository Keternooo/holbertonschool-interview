#include "lists.h"

/**
 * check_cycle - Function to check if the list has a cycle
 * @list: the list to analyse
 * Return: 1 if a cycle is in it and 0 if no cycle
 */

int check_cycle(listint_t *list)
{
	listint_t *temp, *check = list;

	if (!list)
		return (0);

	temp = list->next;

	while(temp)
	{
		if(temp->next)
			temp = temp->next->next;
		else
			temp = temp->next;

		check = check->next;
		if(check == temp)
			return (1);
	}

	return (0);
}
