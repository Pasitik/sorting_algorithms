#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * insertion_sort_list - Creates a doubly linked list from an array of integers
 *
 * @list: list to sort
 *
 * Return: Pointer to the first element of the created list. NULL on failure
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = *list;
	listint_t *prev, *temp;

	while (current != NULL)
	{
		prev = current->prev;
		temp = current;

		while (prev != NULL && prev->n > temp->n)
		{
			prev->next = temp->next;
			if (temp->next != NULL)
			{
				temp->next->prev = prev;
			}
			temp->next = prev;
			temp->prev = prev->prev;
			prev->prev = temp;
			if (temp->prev != NULL)
			{
				temp->prev->next = temp;
			}
			else
			{
				*list = temp;
			}
			prev = temp->prev;
			print_list(*list);
		}

		current = current->next;
	}
}

