#include "monty.h"

/**
 * nop_func - pushes a node to the stack
 * @stack: stack
 * @line_number: line number of fike
 */
void nop_func(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;

	return;
}

/**
 * swap_func - pushes a node to the stack
 * @stack: stack
 * @line_number: line number of fike
 */
void swap_func(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	int temp;
	(void)line_number;

	if (!isEmpty())
	{
		temp = ptr->n;
		ptr->n = ptr->next->n;
		ptr->next->n = temp;
	}
}

/**
 * add_func - pushes a node to the stack
 * @stack: stack
 * @line_number: line number of fike
 */
void add_func(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	int temp;
	(void)line_number;

	if (!isEmpty())
	{
		temp = ptr->n;
		ptr = ptr->next;
		free(*stack);
		ptr->n += temp;
		*stack = ptr;
	}
}

/**
 * sub_func - pushes a node to the stack
 * @stack: stack
 * @line_number: line number of fike
 */
void sub_func(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	int temp;
	(void)line_number;

	if (!isEmpty())
	{
		temp = ptr->n;
		ptr = ptr->next;
		free(*stack);
		ptr->n -= temp;
		*stack = ptr;
	}
}

/**
 * div_func - pushes a node to the stack
 * @stack: stack
 * @line_number: line number of fike
 */
void div_func(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	int temp;
	(void)line_number;

	if (!isEmpty())
	{
		temp = ptr->n;
		ptr = ptr->next;
		free(*stack);
		ptr->n /= temp;
		*stack = ptr;
	}
}


