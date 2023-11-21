#include "sort.h"
#include <stdio.h>
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
/**
 *cocktail_sort_list - this is a cocktail sort implementation
 *working on a double linked lists
 *@list: list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *nodes;
	int swap_done = 1;

	if (list == NULL || (*list) == NULL || (*list)->next == NULL)
		return;
	nodes = *list;
	while (swap_done == 1)
	{
		swap_done = 0;
		while (nodes->next)
		{
			if (nodes->n > nodes->next->n)
			{
				nodes = swap_node(nodes->next, list);
				swap_done = 1;
				print_list(*list);
			}
			nodes = nodes->next;
		}
		if (swap_done == 0)
			break;
		swap_done = 0;
		while (nodes->prev)
		{
			if (nodes->n < nodes->prev->n)
			{
				nodes = swap_node(nodes, list);
				swap_done = 1;
				print_list(*list);
			}
			else
				nodes = nodes->prev;
		}
	}
}
