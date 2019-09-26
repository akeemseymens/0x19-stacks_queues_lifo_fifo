#include "monty.h"

/**
 * reverse - reverse nodes in a linked list
 * @head: original head node of the list
 *
 * Return: The new head node
 */
stack_t *reverse(stack_t **head)
{
	stack_t *p, *previous;

	if (!head || !*head)
		return (NULL);

	p = *head;
	while (p)
	{
		previous = p;
		p = p->next;
		previous->next = previous->prev;
		previous->prev = p;
	}
	*head = previous;

	return (*head);
}
