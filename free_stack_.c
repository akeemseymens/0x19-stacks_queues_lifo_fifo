#include "lists.h"

/**
 * free_stackt - Free a dlistint_t list
 * @head: The head of the list
 */

void free_stackt(stack_t *head)
{
	stack_t *tmp;

	while (head)
	{
		tmp = head;
		head = head->next;
		free(tmp);
	}
}
