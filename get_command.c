#include "monty.h"

/**
 * get_command - get function associated with an opcode
 * @op: code that may be associated with a function
 *
 * Return: function associated with the opcode
 */
void (*get_command(char *op))(stack_t **, unsigned int)
{
	instruction_t instructions[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", NULL},
		{"div", NULL},
		{"mul", mul},
		{"mod", NULL},
		{"pchar", NULL},
		{"pstr", NULL},
		{"rotl", rotl},
		{"rotr", rotr},
		{"stack", stack},
		{"queue", queue},
		{NULL, NULL}
	};
	size_t i = 0;

	if (!op)
		return (NULL);

	for (i = 0; instructions[i].opcode; i++)
		if (strcmp(instructions[i].opcode, op) == 0)
			return (instructions[i].f);

	return (NULL);
}
