#include "sort.h"

/**
 * swap_nodes - Swap two nodes in a listint_t doubly-linked list.
 * @start: A pointer to the head of the doubly-linked list.
 * @first_node: A pointer to the first node to swap.
 * @second_node: The second node to swap.
 */
void swap_nodes(listint_t **start, listint_t **first_node,
		listint_t *second_node)
{
	(*first_node)->next = second_node->next;
	if (second_node->next != NULL)
		second_node->next->prev = *first_node;
	second_node->prev = (*first_node)->prev;
	second_node->next = *first_node;
	if ((*first_node)->prev != NULL)
		(*first_node)->prev->next = second_node;
	else
		*start = second_node;
	(*first_node)->prev = second_node;
	*first_node = second_node->prev;
}

/**
 * insertion_sort_list - Sorts a doubly linked list of integers
 *                       using the insertion sort algorithm.
 * @head: A pointer to the head of a doubly-linked list of integers.
 *
 * Description: Prints the list after each swap.
 */
void insertion_sort_list(listint_t **head)
{
	listint_t *iter, *insert, *tmp;

	if (head == NULL || *head == NULL || (*head)->next == NULL)
		return;

	for (iter = (*head)->next; iter != NULL; iter = tmp)
	{
		tmp = iter->next;
		insert = iter->prev;
		while (insert != NULL && iter->n < insert->n)
		{
			swap_nodes(head, &insert, iter);
			print_list((const listint_t *)*head);
		}
	}
}
