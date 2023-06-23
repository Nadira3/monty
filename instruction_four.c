#include "monty.h"

/**
 * rotr_func - pushes a node to the stack
 * @stack: stack
 * @line_number: line number of fike
 */
void rotr_func(stack_t **stack, unsigned int line_number)
{
	stack_t *temp, *ptr = *stack;
	(void)line_number;

	if (!isEmpty())
	{
		while ((*stack)->next)
			*stack = (*stack)->next;
		ptr = *stack;
		while (ptr)
		{
			temp = ptr->next;
			ptr->next = ptr->prev;
			ptr->prev = temp;
			ptr = ptr->next;
		}
	}
}
