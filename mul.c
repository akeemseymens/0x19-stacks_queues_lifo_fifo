#include "monty.h"

/**
 * mul - Multiply the second element of the stack by the top element
 * @head: The head node in stack
 * @line_number: The line number
 */
void mul(stack_t **head, unsigned int line_number)
{
	stack_t *p;

	if (!(*head && (*head)->next))
	{
		dprintf(STDERR_FILENO,
			"L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		(*head)->next->n *= (*head)->n;
		p = *head;
		*head = (*head)->next;
		(*head)->prev = NULL;
		free(p);
	}
}
