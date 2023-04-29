#include "sort.h"
/**
 * insertion_sort_list - function sorts a doubly linked list using
 * the insertion sort algorithm.
 * @list: pointer to the nodes's head
 *
 * Return: None
 *
 * Description: The first two numbers are compared and swapped if needed.
 * if swapped, the second and third are compared in the second loop
 * etc. in sum, for each loop, all the numbers at the left look at each other
 * and swaps happen accordingly. This continues till the last two numbers.
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *c;

	if (list == NULL || (*list) == NULL)
		return;
	current = (*list)->next;
	while (current != NULL)
	{
		c = current->next;
		while (current->prev != NULL && current->prev->n > current->n)
		{
			current->prev->next = current->next;

			if (current->next != NULL)
				current->next->prev = current->prev;
			current->next = current->prev;
			current->prev = current->next->prev;
			current->next->prev = current;

			if (current->prev == NULL)
				*list = current;
			else
				current->prev->next = current;
			print_list(*list);
		}
		current = c;
	}
}
