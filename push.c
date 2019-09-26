#include "monty.h"
#include <ctype.h>

/**
 * push - Add a new node at the beginning of a dlistint_t list
 * @head: The head of the list
 * @n: line number
 *
 * Return: The address of the new node, or NULL if new node failed.
 */
void push(stack_t **head, unsigned int n)
{
	stack_t *new;
	unsigned int i;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		perror("Error: malloc failed");
		exit(EXIT_FAILURE);
	}

	for (i = 0; global.value[i] != '\0'; i++)
		if (!isdigit(global.value[i]))
		{
			dprintf(STDERR_FILENO, "L%u usage: push integer\n", n);
			exit(EXIT_FAILURE);
		}
	new->n = atoi(global.value);
	new->next = *head;
	new->prev = NULL;
	if (*head)
		(*head)->prev = new;
	*head = new;
}
