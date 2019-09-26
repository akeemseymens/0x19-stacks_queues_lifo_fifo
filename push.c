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

	i = 0;
	if (!global.value || global.value[0] == '\0')
	{
		dprintf(STDERR_FILENO, "L%u usage: push integer\n", n);
		exit(EXIT_FAILURE);
	}
	else if (global.value[0] == '-' && global.value[1] != '\0')
		i++;
	for (; global.value[i] != '\0'; i++)
		if (!isdigit(global.value[i]))
		{
			dprintf(STDERR_FILENO, "L%u usage: push integer\n", n);
			exit(EXIT_FAILURE);
		}

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = atoi(global.value);
	new->next = *head;
	new->prev = NULL;
	if (*head)
		(*head)->prev = new;
	*head = new;
}
