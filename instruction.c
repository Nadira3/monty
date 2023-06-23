#include "monty.h"

/**
 * isEmpty - chexks if a stack is empty
 * Return: 0 or 1
 */
int isEmpty(void)
{
	if (!stack)
		return (1);
	return (0);
}

/**
 * push_func - pushes a node to the stack
 * @stack: stack
 * @line_number: line number of fike
 */
void push_func(stack_t **stack, unsigned int line_number)
{
	stack_t *node = malloc(sizeof(stack_t));
	(void)line_number;

	if (!node)
	{
		fprintf(stderr, "Error: malloc failed");
		return;
	}
	node->prev = NULL;
	node->next = NULL;
	node->n = n;
	if (!isEmpty())
	{
		node->next = *stack;
		(*stack)->prev = node;
	}
	*stack = node;
}

/**
 * pall_func - pushes a node to the stack
 * @stack: stack
 * @line_number: line number of fike
 */
void pall_func(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	(void)line_number;

	if (!isEmpty())
	{
		while (ptr)
		{
			fprintf(stdout, "%d\n", ptr->n);
			ptr = ptr->next;
		}
	}
}

/**
 * pint_func - pushes a node to the stack
 * @stack: stack
 * @line_number: line number of fike
 */
void pint_func(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	(void)line_number;

	if (!isEmpty())
	{
		fprintf(stdout, "%d\n", ptr->n);
	}
}
