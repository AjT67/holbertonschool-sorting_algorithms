#include "sort.h"

/**
 * swap_nodes - swaps two adjacent nodes in a doubly linked list,
 * moving y to be before x
 * @list: pointer to the head of the list
 * @x: the node originally before y
 * @y: the node originally after x
 */
void swap_nodes(listint_t **list, listint_t *x, listint_t *y)
{
	if (x->prev != NULL)
		x->prev->next = y;
	else
		*list = y;

	y->prev = x->prev;
	x->next = y->next;

	if (y->next != NULL)
		y->next->prev = x;

	y->next = x;
	x->prev = y;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers in
 * ascending order using the Insertion sort algorithm
 * @list: pointer to a pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *next, *tmp;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current != NULL)
	{
		next = current->next;
		tmp = current->prev;

		while (tmp != NULL && tmp->n > current->n)
		{
			swap_nodes(list, tmp, current);
			print_list(*list);
			tmp = current->prev;
		}

		current = next;
	}
}
