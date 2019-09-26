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

	if (global.stack_mode)
	{
		while (p)
		{
			printf("%d\n", p->n);
			p = p->next;
		}
	}
	else
	{
		while (p && p->next)
			p = p->next;
		while (p)
		{
			printf("%d\n", p->n);
			p = p->prev;
		}
	}
}
