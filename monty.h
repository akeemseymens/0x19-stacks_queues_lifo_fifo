#ifndef _MONTY_H
#define _MONTY_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO Holberton project
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_s - globals needed by the program
 * @value: value used in push
 * @stack: head node of the stack
 * @line: line read from file
 * @file: file to read lines from
 * @stack_mode: is the structure a stack or a queue
 */
typedef struct global_s
{
	char *value;
	stack_t *stack;
	char *line;
	FILE *file;
	int stack_mode;
} global_t;

extern global_t global;

void push(stack_t **head, unsigned int line_number);
void pall(stack_t **head, unsigned int line_number);
void pop(stack_t **head, unsigned int line_number);
void nop(stack_t **head, unsigned int line_number);
void rotl(stack_t **head, unsigned int line_number);
void rotr(stack_t **head, unsigned int line_number);
void stack(stack_t **head, unsigned int line_number);
void queue(stack_t **head, unsigned int line_number);
void pint(stack_t **head, unsigned int line_number);
void add(stack_t **head, unsigned int line_number);
void swap(stack_t **head, unsigned int line_number);
void mul(stack_t **head, unsigned int line_number);
void _div(stack_t **head, unsigned int line_number);
void free_stackt(stack_t **head);
void (*get_command(char *op))(stack_t **, unsigned int);
stack_t *reverse(stack_t **head);

#endif
