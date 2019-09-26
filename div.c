#include "monty.h"

/**
 * div - Divide the second element of the stack by the top element
 * @head: The head of the stack
 * @line_number: The line number
 */
void div(stack_t **head, unsigned int line_number)
{
	stack_t *p;

	if (!(*head && (*head)->next))
	{
		dprintf(STDERR_FILENO,
			"L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else if ((*head)->n == 0)
	{
		dprintf(STDERR_FILENO,
			"L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		(*head)->next->n /= (*head)->n;
		p = *head;
		*head = (*head)->next;
		(*head)->prev = NULL;
		free(p);
	}
}
