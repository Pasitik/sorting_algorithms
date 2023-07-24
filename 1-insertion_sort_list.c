#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * create_listint - Creates a doubly linked list from an array of integers
 *
 * @array: Array to convert to a doubly linked list
 * @size: Size of the array
 *
 * Return: Pointer to the first element of the created list. NULL on failure
 */

listint_t *create_listint(const int *array, size_t size)
{
	listint_t *list;
	listint_t *node;
	int *tmp;

	list = NULL;
	while (size--)
	{
		node = malloc(sizeof(*node));
		if (!node)
			return (NULL);
		tmp = (int *)&node->n;
		*tmp = array[size];
		node->next = list;
		node->prev = NULL;
		list = node;
		if (list->next)
			list->next->prev = list;
	}
	return (list);
}

/**
 * insertion_sort_list - sorts a doubly
 * linked list from an array of integers
 *
 * @list: Array to convert to a doubly linked list
 *
 * Return: nothing
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current = (*list)->next, *sorted_ptr, *temp_next;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;
	while (current != NULL)
	{
		sorted_ptr = current->prev;
		temp_next = current->next;

		if (sorted_ptr != NULL)
			sorted_ptr->next = current->next;
		else
			(*list) = current->next;
		if (current->next != NULL)
			current->next->prev = current->prev;
		while (sorted_ptr != NULL && sorted_ptr->n > current->n)
			sorted_ptr = sorted_ptr->prev;

		if (sorted_ptr == NULL)
		{
			current->prev = NULL;
			current->next = *list;

			if (*list != NULL)
				(*list)->prev = current;
			(*list) = current;
		}
		else
		{
			current->prev = sorted_ptr;
			current->next = sorted_ptr->next;

			if (sorted_ptr->next != NULL)
				sorted_ptr->next->prev = current;
			sorted_ptr->next = current;
		}
		current = temp_next;
		print_list(*list);
	}
}
