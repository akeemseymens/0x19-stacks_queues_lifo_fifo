#include "monty.h"

/**
 * add - Prints the first element of the list.
 * @head: head node.
 * @line_number: line number of file on which add was found
 */
void add(stack_t **head, unsigned int line_number)
{
	stack_t *p;

	if (!head)
		return;

	p = *head;
	if (!p || !p->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	p = p->next;
	p->n += p->prev->n;
	free(p->prev);
	p->prev = NULL;

	*head = p;
}
