#include "monty.h"

#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


global_t global = { 0, NULL, NULL, NULL, 1 };

/**
 * bye - destructor
 */
void bye(void) __attribute__((destructor));
void bye(void)
{
	if (global.stack)
		free_stackt(&global.stack);
	if (global.line)
		free(global.line);
	if (global.file)
		fclose(global.file);
}

/**
 * init - validate inputs and open file
 * @argc: number of arguments
 * @argv: arguments
 */
void init(int argc, char *argv[])
{
	if (argc != 2)
	{
		dprintf(STDERR_FILENO, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	global.file = fopen(argv[1], "r");
	if (!global.file)
	{
		dprintf(STDERR_FILENO, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
}

/**
 * main - entry point for program
 * @argc: number of arguments provided to the program (should be 2)
 * @argv: arguments provided to the program
 *
 * Return: EXIT_SUCCESS
 */
int main(int argc, char *argv[])
{
	char *command;
	size_t line_size = 0, i;
	unsigned int ln = 0;
	void (*command_func)(stack_t **, unsigned int);

	init(argc, argv);
	while (1)
	{
		ln++;
		global.line = NULL;
		line_size = 0;
		if (getline(&global.line, &line_size, global.file) == -1)
			break;

		for (i = 0; global.line[i]; i++)
			if (global.line[i] == '\t')
				global.line[i] = ' ';
		command = strtok(global.line, " ");
		if (!command)
		{
			free(global.line);
			continue;
		}
		if (strcmp(command, "push") == 0)
			global.value = strtok(strtok(NULL, " "), "\n");

		command = strtok(command, "\n");
		if (!command)
		{
			free(global.line);
			continue;
		}

		command_func = get_command(command);
		if (!command_func)
		{
			dprintf(STDERR_FILENO, "L%u: unknown instruction %s\n", ln, command);
			exit(EXIT_FAILURE);
		}
		command_func(&global.stack, ln);

		free(global.line);
	}

	return (EXIT_SUCCESS);
}
