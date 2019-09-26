#include "monty.h"

/**
 * rotl - Add a new node at the beginning of a dlistint_t list
 * @head: The head of the list
 * @line_number: line number
 */
void rotl(stack_t **head, unsigned int line_number)
{
	stack_t *p;

	(void)line_number;

	if (!head || !*head || !(*head)->next)
		return;

	p = *head;
	while (p->next)
		p = p->next;

	p->next = *head;
	p->next->prev = p;
	*head = p->next->next;
	(*head)->prev = NULL;
}
