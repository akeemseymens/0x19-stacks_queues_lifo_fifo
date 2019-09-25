#include "lists.h"
/**
 * pall - Prints all the elements of the list.
 * @h: header and list.
 *
 **/
void pall(stack_t **h, unsigned int line_number)
{
	stack_t *p = *h;
	(void) unsigned int line_number;

	while (p)
	{
		printf("%d\n", p->n);
       		p = p->next;
	}

}
