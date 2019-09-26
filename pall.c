#include "monty.h"
/**
 * pall - Prints all the elements of the list.
 * @h: header and list.
 * @line_number: line number of file on which pall was found
 */
void pall(stack_t **h, unsigned int line_number)
{
	stack_t *p = *h;

	(void) line_number;

	while (p)
	{
		printf("%d\n", p->n);
		p = p->next;
	}
}
