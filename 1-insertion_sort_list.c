#include "sort.h"

/**
* insertion_sort_list - This function sorts a doubly linked list  using
* insertion sort.
*
* @list: Double linked list we are to sort
*
*/

void insertion_sort_list(listint_t **list)
{
	listint_t *node;

	if (list == NULL || (*list)->next == NULL)
		return;
	node = (*list)->next;
	while (node)
	{
		while ((node->prev) && (node->prev->n > node->n))
		{
			node = swap_node(node, list);
			print_list(*list);
		}
		node = node->next;
	}
}

/**
* swap_node - This function will snap a node and it's previous one
* @node: this is the node's we will be swapping
* @list: node list
*
* Return: returns a pointer to the node
*/

listint_t *swap_node(listint_t *node, listint_t **list)
{
	listint_t *go_back = node->prev, *current = node;

	go_back->next = current->next;
	if (current->next)
		current->next->prev = go_back;
	current->next = go_back;
	current->prev = go_back->prev;
	go_back->prev = current;

	if (current->prev)
		current->prev->next = current;
	else
		*list = current;
	return (current);
}
