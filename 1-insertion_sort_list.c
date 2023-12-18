#include "sort.h"

/**
 * insertion_sort_list - Func runs insertion sort algorithm
 * @list: Head of the doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *main = (*list)->next;
	listint_t *rev = main->prev;

	if (!list || !*list || !(*list)->next)
		return;

	while (main)
	{

		while (rev && rev->n > main->n)
		{
			if (rev->prev)
				rev->prev->next = main;
			if (main->next)
				main->next->prev = rev;

			rev->next = main->next;
			main->prev = rev->prev;

			main->next = rev;
			rev->prev = main;

			if (!main->prev)
				*list = main;

			print_list(*list);

			rev = main->prev;
		}
		main = main->next;
	}
}
