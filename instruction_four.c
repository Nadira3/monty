#include "monty.h"

/**
 * rotr_func - pushes a node to the stack
 * @stack: stack
 * @line_number: line number of fike
 */
void rotr_func(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (!isEmpty())
	{
		while ((*stack)->next)
			*stack = (*stack)->next;	
	}
}
