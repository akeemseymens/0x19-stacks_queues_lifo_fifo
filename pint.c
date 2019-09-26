#include "monty.h"

/**
 * pint - Prints the first element of the list.
 * @head: head node.
 * @line_number: line number of file on which pint was found
 */
void pint(stack_t **head, unsigned int line_number)
{
	if (!head)
		return;

	if (!*head)
	{
		dprintf(STDERR_FILENO, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}
