#include "sort.h"

/**
 * cocktail_sort_list - sorts a doubly linked list of integers in ascending
 * order using the Cocktail shaker sort algorithm
 * @list: pointer to the head of the doubly linked list
 */
void cocktail_sort_list(listint_t **list)
{
    listint_t *current;
    int swapped = 1;

    if (list == NULL || *list == NULL || (*list)->next == NULL)
        return;

    current = *list;

    while (swapped)
    {
        swapped = 0;

        /* Traverse the list from left to right */
        while (current->next != NULL)
        {
            /* If the current node is greater than the next node, swap them */
            if (current->n > current->next->n)
            {
                swap_nodes(list, current, current->next);
                swapped = 1;
                print_list(*list);
            }
            else
            {
                /* Move to the next node */
                current = current->next;
            }
        }

        /* If no swaps were made, the list is sorted */
        if (swapped == 0)
            break;

        swapped = 0;

        /* Traverse the list from right to left */
        while (current->prev != NULL)
        {
            /* If the current node is smaller than the previous node, swap them */
            if (current->n < current->prev->n)
            {
                swap_nodes(list, current->prev, current);
                swapped = 1;
                print_list(*list);
            }
            else
            {
                /* Move to the previous node */
                current = current->prev;
            }
        }
    }
}

/**
 * swap_nodes - swaps two adjacent nodes of a doubly linked list
 * @list: pointer to the head of the list
 * @node1: pointer to the first node
 * @node2: pointer to the second node
 */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
    /* Adjust the links of the previous and next nodes */
    if (node1->prev != NULL)
        node1->prev->next = node2;
    else
        *list = node2;

    if (node2->next != NULL)
        node2->next->prev = node1;

    /* Swap the nodes */
    node1->next = node2->next;
    node2->prev = node1->prev;
    node2->next = node1;
    node1->prev = node2;
}
