#include "monty.h"

/**
 * pop - deletes the first nodes
 * @head: a node in a dlistint list
 * @line_number: line number passed file.
 *
 */

void pop(stack_t **head, unsigned int line_number)
{

	stack_t *p;

	if (!head || !*head)
		dprintf(STDERR_FILENO, "L%ud: can't pop an empty stack.", line_number);

	p = *head;
	while (p && p->prev)
		p = p->prev;

	if (p->next)
		p->next->prev = NULL;

	*head = p->next;
	free(p);
}
