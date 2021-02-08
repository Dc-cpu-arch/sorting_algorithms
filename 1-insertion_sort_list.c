#include "sort.h"

/**
 * change - switch elements, setting the largest to the right
 *
 * @larger: node with largest value in the left side
 * @small: node with lowest value in the right side
 * @list: double pointer to cross the list
 *
 * Return: location to the largest value node
 */
listint_t *change(listint_t *larger, listint_t *small, listint_t **list)
{
	if (larger->prev)
		(larger->prev)->next = small;
	else
		*list = small, small->prev = NULL;
	if (small->next)
		(small->next)->prev = larger;

	small->prev = larger->prev;
	larger->prev = small;
	larger->next = small->next;
	small->next = larger;
	return (larger);
}

/**
 * insertion_sort_list - use Insertion Sort Algorith to sort a DLL
 * of integers in ascending order
 *
 * @list: double pointer to cross the list
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *lrg, *current, *sml;

	if (!list)
		return;

	current = (*list)->next;
	while (current)
	{
		lrg = current->prev;
		sml = current;
		while (sml->prev && sml->n < lrg->n)
		{
			current = change(lrg, sml, list);
			print_list(*list);
			if (!sml->prev)
				break;
			lrg = sml->prev;
		}
		current = current->next;
		lrg = lrg->next;
	}
}
