#include "monty.h"

/**
 * swap - Prints the first element of the list.
 * @head: head node.
 * @line_number: line number of file on which swap was found
 */
void swap(stack_t **head, unsigned int line_number)
{
	stack_t *p;

	if (!head)
		return;

	p = *head;
	if (!p || !p->next)
	{
		dprintf(STDERR_FILENO, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	p = p->next;
	if (p->next)
		p->next->prev = p->prev;
	p->prev->next = p->next;
	p->next = p->prev;
	p->next->prev = p;
	*head = p;
}
