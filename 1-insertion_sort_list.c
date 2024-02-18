#include "sort.h"

/**
 * swap_nodes - swaps two adjacent nodes in a doubly linked list
 * @left: pointer to the left node
 * @right: pointer to the right node
 * @head: pointer to the head of the list
 */
void swap_nodes(listint_t *left, listint_t *right, listint_t **head)
{
	listint_t *tmp;

	tmp = left->prev;
	if (tmp)
		tmp->next = right;
	left->prev = right;
	left->next = right->next;
	right->prev = tmp;
	right->next = left;
	if (left->next)
		left->next->prev = left;
	if (*head == left)
		*head = right;
}

/**
 * insertion_sort_list - sorts a doubly linked list of integers
 * @list: pointer to the head of the list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *prev;

	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return;

	current = (*list)->next;
	while (current)
	{
		prev = current->prev;
		while (prev && prev->n > current->n)
		{
			swap_nodes(prev, current, list);
			print_list(*list);
			prev = current->prev;
		}
		current = current->next;
	}
}
