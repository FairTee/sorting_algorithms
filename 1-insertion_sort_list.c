#include "sort.h"
/**
 * insertion_sort_list - function that sorts a doubly linked list
 * of integers in ascending order using the Insertion sort algorithm
 * @list: Dobule linked list to sort
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *nodes;

	if (list == NULL || (*list)->next == NULL)
		return;
	nodes = (*list)->next;
	while (nodes)
	{
		while ((nodes->prev) && (nodes->prev->n > nodes->n))
		{
			nodes = swap_node(nodes, list);
			print_list(*list);
		}
		nodes = nodes->next;
	}
}
/**
 *swap_node - swap a node for his previous one
 *@node: node
 *@list: node list
 *Return: return a pointer to a node which was enter it
 */
listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *b = node->prev, *curr = node;

	b->next = curr->next;
	if (curr->next)
		curr->next->prev = b;
	curr->next = b;
	curr->prev = b->prev;
	b->prev = curr;
	if (curr->prev)
		curr->prev->next = curr;
	else
		*list = curr;
	return (curr);
}
