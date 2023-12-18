#include "sort.h"

/**
 * insertion_sort_list - Func runs insertion sort algorithm
 * @list: Head of the linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *sorted = NULL;
	listint_t *main = *list;
	listint_t *next;

	if (!list || !*list || !((*list)->next))
		return;

	while (main != NULL)
	{
		next = main->next;

		input_node(&sorted, main);

		main = next;
	}

	*list = sorted;
}

/**
 * input_node - Func inserts a node
 * @head: Head of the sorted list
 * @node: Node inserted
 */
void input_node(listint_t **head, listint_t *node)
{
	listint_t *main;

	if (*head == NULL || (*head)->n >= node->n)
	{
		node->next = *head;
		*head = node;
	}
	else
	{
		main = *head;
		while (main->next != NULL && main->next->n < node->n)
		{
			main = main->next;
		}
		node->next = main->next;
		main->next = node;
	}
}
