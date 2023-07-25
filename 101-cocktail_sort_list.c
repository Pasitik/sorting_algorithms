#include "sort.h"
#include <stdlib.h>


void swap_node_next(listint_t **list, listint_t **node1, listint_t **node2);
void swap_node_prev(listint_t **list, listint_t **node1, listint_t **node2);
void node_forward_pass(listint_t **list, int *swapped, listint_t **start);
listint_t *cocktail_shaker_sort(listint_t *list);

/**
 * cocktail_shaker_sort - sorting algorithm for a doubly linked list.
 *
 * @list: head to a doubly linked list
 *
 * Return: Pointer to the first element of the created list. NULL on failure
 */
listint_t *cocktail_shaker_sort(listint_t *list)
{
	listint_t *start = list;
	int swapped = 0;

	if (list == NULL || list->next == NULL)
		return (list);

	do {
		node_forward_pass(&list, &swapped, &start);

		if (!swapped)
			break;

		swapped = 0;

		while (list->prev != NULL)
		{
			if (list->n < list->prev->n)
			{
				swap_node_prev(&list, &(list->next), &(list->prev));
				if (list->prev == NULL)
					start = list;
				print_list(start);
				swapped = 1;
			}
			else
			{
				list = list->prev;
			}
		}
	} while (swapped);

	return (start);
}

/**
 * cocktail_sort_list - sorting algorithm for a doubly linked list.
 *
 * @list: head to a doubly linked list
 *
 * Return: nothing
 */

void  cocktail_sort_list(listint_t **list)
{
	listint_t *sortedList = cocktail_shaker_sort(*list);
	*list = sortedList;
}

/**
 * swap_node_next - swap function for a doubly linked list.
 *
 * @list: head to a doubly linked list
 * @node1: head to first node
 * @node2: head to second node
 *
 * Return: nothing
 */
void swap_node_next(listint_t **list, listint_t **node1, listint_t **node2)
{
	listint_t *tempNext = *node1;
	listint_t *tempPrev = *node2;

	*node1 = tempNext->next;
	if (tempNext->next != NULL)
		tempNext->next->prev = *list;

	tempNext->next = *list;
	*node2 = tempNext;
	(*node2)->prev = tempPrev;

	if (tempPrev != NULL)
		tempPrev->next = tempNext;
}

/**
 * swap_node_prev - swap function for a doubly linked list.
 *
 * @list: head to a doubly linked list
 * @node1: head to first node
 * @node2: head to second node
 *
 * Return: nothing
 */

void swap_node_prev(listint_t **list, listint_t **node1, listint_t **node2)
{
	listint_t *tempNext = *node1;
	listint_t *tempPrev = *node2;

	*node2 = tempPrev->prev;
	if (tempPrev->prev != NULL)
		tempPrev->prev->next = *list;

	tempPrev->prev = *list;
	*node1 = tempPrev;
	(*node1)->next = tempNext;

	if (tempNext != NULL)
		tempNext->prev = tempPrev;
}
/**
 * node_forward_pass - swap function for a doubly linked list.
 *
 * @list: head to a doubly linked list
 * @swapped: check if a swapped occured
 * @start: head to returned list
 *
 * Return: nothing
 */
void node_forward_pass(listint_t **list, int *swapped, listint_t **start)
{
	while ((*list)->next != NULL)
	{
		if ((*list)->n > (*list)->next->n)
		{
			swap_node_next(&(*list), &((*list)->next), &((*list)->prev));
			if ((*list)->prev == NULL)
				*start = (*list);

			print_list(*start);
			*swapped = 1;
		}
		else
		{
			(*list) = (*list)->next;
		}
	}
}

