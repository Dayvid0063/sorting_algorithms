#include "sort.h"
/**
 * swap_nodes - swap nodes in place
 * @list: list of nodes
 * @node1: first node
 * @node2: second node
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
	listint_t *temp;

	if (!node1 || !node2)
		return;

	/* Adjust next pointers */
	if (node1->next != node2)
	{
		node1->next->prev = node2;
		node2->next->prev = node1;
		temp = node1->next;
		node1->next = node2->next;
		node2->next = temp;
	}
	else
	{
		node1->next = node2->next;
		if (node1->next)
			node1->next->prev = node1;
	}

	/* Adjust prev pointers */
	if (node2->prev != node1)
	{
		node2->prev->next = node1;
		node1->prev->next = node2;
		temp = node1->prev;
		node1->prev = node2->prev;
		node2->prev = temp;
	}
	else
	{
		node2->prev = node1->prev;
		if (node2->prev)
			node2->prev->next = node2;
	}

	/* Adjust head of the list if necessary */
	if (*list == node1)
		*list = node2;
	else if (*list == node2)
		*list = node1;
}

/**
 * cocktail_sort_list - Sorts a double linked list of integers
 * in ascending order using the Cocktail shaker sort algorithm
 * @list: list to be printed each time you swap two elements
 */
void cocktail_sort_list(listint_t **list)
{
	int swapped;
	listint_t *start = *list;
	listint_t *end = NULL;

	do
	{
		swapped = 0;

		while (start && start->next != end)
		{
			if (start->n > start->next->n)
			{
				swap_nodes(list, start, start->next);
				print_list(*list);
				swapped = 1;
			}
			start = start->next;
		}
		if (!swapped)
			break;
		swapped = 0;
		end = start;

		while (start && start->prev != end)
		{
			if (start->prev && start->n < start->prev->n)
			{
				swap_nodes(list, start->prev, start);
				print_list(*list);
				swapped = 1;
			}
			start = start->prev;
		}
		start = *list;
	} while (swapped);
}
