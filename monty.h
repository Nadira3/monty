#ifndef MONTY_H
#define MONTY_H
#define _GNU_SOURCE

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <libgen.h>
#include <stddef.h>
#include <stdarg.h>

/**
 * struct op - has two elements
 * @format: op format
 * @f: function pointer
 */
typedef struct op
{
	char *format;
	void (*f)(va_list pam);
} form_t;

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

int n;
stack_t *stack;
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

void add_func(stack_t **stack, unsigned int line_number);

stack_t *make_node(void);
void usage_check(int, FILE *, char *);
char *read_input(FILE *, ssize_t *);
void free_buf(char **);
void free_stack(stack_t **);
char **parse_input(char *, FILE *);
int num_words(char *str);
void err_and_exit(char *, char **, FILE *, const char * const, ...);
void (*g(char *, char **, FILE *, size_t))(stack_t **, unsigned int);
void push_func(stack_t **stack, unsigned int line_number);
void pall_func(stack_t **stack, unsigned int line_number);
void pint_func(stack_t **stack, unsigned int line_number);
void pop_func(stack_t **stack, unsigned int line_number);
#endif
