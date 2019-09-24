#include "lists.h"

/**
 * stack_t - Add a new node at the beginning of a dlistint_t list
 * @head: The head of the list
 * @n: The value of the new node
 *
 * Return: The address of the new node, or NULL if new node failed.
 */

stack_t *push(stack_t **head, const int n)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
		return (NULL);
	new->n = n;
	new->next = *head;
	new->prev = NULL;
	if (*head)
		(*head)->prev = new;
	*head = new;

	return (new);
}
