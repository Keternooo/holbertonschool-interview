#include "lists.h"
#include <stdlib.h>

listint_t *insert_node(listint_t **head, int number)
{
    listint_t *newNode, *current;

    if(!head) return NULL;

    newNode = malloc(sizeof(listint_t));
    if(!newNode) return NULL;

    newNode->n = number;
    newNode->next = NULL;

    current = *head;


    while(current->next && current->next->n < number)
    {
        current = current->next;
    }
    newNode->next = current->next;
    current->next = newNode;


    return newNode;
}

