#include "lists.h"
/**
 * print_dlistint - Prints all the elements of the list.
 * @h: header and list.
 * Return: the count.
 **/
size_t pall(const stack_t *h)
{
	size_t count = 0;

	while (h)
	{
		printf("%d\n", h->n);
		count++;
		h = h->next;
	}

	return (count);
}
