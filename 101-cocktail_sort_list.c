#include "sort.h"

/**
 * swap_nodes_front - Swap a node in a listint_t list
 * @list: pointer to the head of list.
 * @tail: pointer to the tail of list.
 * @s: pointer to the current swapping node.
 */
void swap_nodes_front(listint_t **list, listint_t **tail, listint_t **s);
void swap_nodes_front(listint_t **list, listint_t **tail, listint_t **s)
{
	listint_t *tmp = (*s)->next;

	if ((*s)->prev != NULL)
		(*s)->prev->next = tmp;
	else
		*list = tmp;
	tmp->prev = (*s)->prev;
	(*s)->next = tmp->next;
	if (tmp->next != NULL)
		tmp->next->prev = *s;
	else
		*tail = *s;
	(*s)->prev = tmp;
	tmp->next = *s;
	*s = tmp;
}

/**
 * swap_nodes_back - Function to swap a node in a listint_t list
 * @list: pointer to the head of list.
 * @tail: pointer to the tail of list.
 * @s: pointer to the current swapping node.
 */
void swap_nodes_back(listint_t **list, listint_t **tail, listint_t **s);
void swap_nodes_back(listint_t **list, listint_t **tail, listint_t **s)
{
	listint_t *tmp = (*s)->prev;

	if ((*s)->next != NULL)
		(*s)->next->prev = tmp;
	else
		*tail = tmp;
	tmp->next = (*s)->next;
	(*s)->prev = tmp->prev;
	if (tmp->prev != NULL)
		tmp->prev->next = *s;
	else
		*list = *s;
	(*s)->next = tmp;
	tmp->prev = *s;
	*s = tmp;
}

/**
 * cocktail_sort_list - function to sort a listint_t doubly-linked list.
 * @list: pointer to the head of list.
 */
void cocktail_sort_list(listint_t **list);
void cocktail_sort_list(listint_t **list)
{
	listint_t *tail, *s;
	bool n = false;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	for (tail = *list; tail->next != NULL;)
		tail = tail->next;

	while (n == false)
	{
		n = true;
		for (s = *list; s != tail; s = s->next)
		{
			if (s->n > s->next->n)
			{
				swap_nodes_front(list, &tail, &s);
				print_list((const listint_t *)*list);
				n = false;
			}
		}
		for (s = s->prev; s != *list;
				s = s->prev)
		{
			if (s->n < s->prev->n)
			{
				swap_nodes_back(list, &tail, &s);
				print_list((const listint_t *)*list);
				n = false;
			}
		}
	}
}
