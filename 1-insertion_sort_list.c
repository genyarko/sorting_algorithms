#include "sort.h"

/**
 * insertion_sort_list - sorts doubly linked list of ints using Insertion sort
 * @list: lst to sort
 */

void insertion_sort_list(listint_t **list)
{
	listint_t *sorted, *current, *next;

	current = *list;
	sorted = NULL;

	while (current)
	{
		next = current->next;
		current->prev = current->next = NULL;
		sortedInsert(&sorted, &current);
		current = next;

		print_list(sorted);
	}
	*list = sorted;
}

/**
 * sortedInsert - function for inserting nodes in sorted order
 * @head_ref: reference to stating noe for comparison
 * @newNode: pointer to next node to compare
 */

void sortedInsert(listint_t  **head_ref, listint_t  **newNode)
{
	listint_t *current;

	if (*head_ref == NULL)
		*head_ref = *newNode;
	else if ((*head_ref)->n >= (*newNode)->n)
	{
		(*newNode)->next = *head_ref;
		(*newNode)->next->prev = *newNode;
		*head_ref = *newNode;
	}
	else
	{
		current = *head_ref;

		while (current->next && current->next->n < (*newNode)->n)
			current = current->next;

		(*newNode)->next = current->next;

		if (current->next != NULL)
			(*newNode)->next->prev = *newNode;
		current->next = *newNode;
		(*newNode)->prev = current;
	}
}
