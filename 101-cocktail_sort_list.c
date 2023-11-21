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
 *@list: list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *node;
	int swapped = 1;

	if (list == '\0' || (*list) == '\0' || (*list)->next == '\0')
		return;
	node = *list;
	while (swapped == 1)
	{
		swapped = 0;
		while (node->next)
		{
			if (node->n > node->next->n)
			{
				node = swapped(node->next, list);
				swapped = 1;
				print_list(*list);
			}
			node = node->next;
		}
		if (swapped == 0)
			break;
		swapped = 0;
		while (node->prev)
		{
			if (node->n < node->prev->n)
			{
				node = swapped(node, list);
				swapped = 1;
				print_list(*list);
			}
			else
				node = node->prev;
		}
	}
}
