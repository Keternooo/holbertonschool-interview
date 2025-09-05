#include "lists.h"
#include <stdio.h>
#include <stdlib.h>

/**
  * is_palindrome - Function to check if the simply linked list is a palindrome
  * @**head: pointer to pointer of first node of listint_t list
  * Return: 0 if not palindrome else 1 
  */


int is_palindrome(listint_t **head)
{
     int len = 0, i , *arr;
     listint_t *temp;
     
     if (*head == NULL)
        return (1);

     temp = *head;
     while(temp != NULL)
     {
          len++;
          temp = temp->next;
     }

     arr = malloc(sizeof(int) * len);
     if (arr == NULL)
          return (0);

     temp = *head;
     for(i = 0; i < len; i++)
     {
          arr[i] = temp->n;
          temp = temp->next;
     }

     for(i = 0; i < len; i++)
     {
          if(arr[i] != arr[len - i - 1])
               return (0);
     }
     return (1);
}


