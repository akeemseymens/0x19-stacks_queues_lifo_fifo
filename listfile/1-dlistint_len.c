#include "lists.h"
/**
 * dlistint_len - Prints all the elements of the list.
 * @h: pointer linked list.
 * Return: the count.
 **/
size_t dlistint_len(const dlistint_t *h)
{
	size_t count = 0;

	while (h)
	{
		count++;
		h = h->next;
	}

	return (count);
}
