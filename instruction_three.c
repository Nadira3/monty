#include "monty.h"

/**
 * mul_func - pushes a node to the stack
 * @stack: stack
 * @line_number: line number of fike
 */
void mul_func(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	int temp;
	(void)line_number;

	if (!isEmpty())
	{
		temp = ptr->n;
		ptr = ptr->next;
		free(*stack);
		ptr->n *= temp;
		*stack = ptr;
	}
}

/**
 * mod_func - pushes a node to the stack
 * @stack: stack
 * @line_number: line number of fike
 */
void mod_func(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	int temp;
	(void)line_number;

	if (!isEmpty())
	{
		temp = ptr->n;
		ptr = ptr->next;
		free(*stack);
		ptr->n %= temp;
		*stack = ptr;
	}
}

/**
 * pchar_func - pushes a node to the stack
 * @stack: stack
 * @line_number: line number of fike
 */
void pchar_func(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	(void)line_number;

	if (!isEmpty())
	{
		if (ptr->n < 0 || ptr->n > 127)
			return;
		fprintf(stdout, "%c\n", ptr->n);
	}
}

/**
 * pstr_func - pushes a node to the stack
 * @stack: stack
 * @line_number: line number of fike
 */
void pstr_func(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = *stack;
	(void)line_number;

	if (!isEmpty())
	{
		while (ptr)
		{
			if (ptr->n <= 0 || ptr->n > 127)
				break;
			fprintf(stdout, "%c", ptr->n);
			ptr = ptr->next;
		}
		puts("");
	}
}
