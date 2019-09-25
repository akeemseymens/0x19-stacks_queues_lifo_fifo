#include "monty.h"

/**
 * free_stackt - Free a dlistint_t list
 * @head: The head of the list
 */
void free_stackt(stack_t **head)
{
	stack_t *tmp, *p;

	if (!head)
		return;

	tmp = *head;
	while (tmp)
	{
		p = tmp;
		tmp = tmp->next;
		free(p);
	}
}
