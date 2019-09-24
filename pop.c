#include "lists.h"

/**
 * pop_at_index - inset a new node at a given position
 * @head: a node in a dlistint list
 * @idx: index in dlistint list at which to insert new node
 *
 * Return: 1 (SUCCESS) of deletion, else -1
 */

stack_t *pop_at_index(stack_t **head, unsigned int idx)
{

	stack_t *p, *last = NULL;
	unsigned int i = idx;

	if (!head)
		return (-1);

	p = *head;
	while (p && p->prev)
		p = p->prev;

	while (p && idx)
	{
		last = p;
		p = p->next;
		idx--;
	}

	if (idx != 0 || !p)
		return (-1);

	if (last)
		last->next = p->next;
	if (p->next)
		p->next->prev = last;

	if (i == 0)
		*head = p->next;
	return (p);
}
