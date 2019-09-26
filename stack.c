#include "monty.h"

/**
 * stack - deletes the first nodes
 * @head: a node in a dlistint list
 * @line_number: line number passed file.
 *
 */

void stack(stack_t **head, unsigned int line_number)
{
	(void) head;
	(void) line_number;

	if (!global.stack_mode)
		reverse(head);

	global.stack_mode = 1;
}
