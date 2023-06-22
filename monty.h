#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <libgen.h>
#include <stddef.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
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
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct global_s - buffer and stack
 * @input: input buffer
 * @input_token: buffer arguments
 * @head: head of stack
 *
 * Description: opcode buffer and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct global_s
{
	char *input;
	char **input_token;
	stack_t *head;
} global_t;

extern global_t var;

void usage_check(int, FILE *, char *);
char *read_input(FILE *file, ssize_t *);
void free_buf(void);
char **parse_input(void);
void (*opcode_check(char *))(stack_t **, unsigned int);
#endif