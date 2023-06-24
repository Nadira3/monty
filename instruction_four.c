#include "monty.h"

/**
 * rotr_func - pushes a node to the stack
 * @stack: stack
 * @line_number: line number of fike
 */
void rotr_func(stack_t **stack, unsigned int line_number)
{
	int temp = 0;
	stack_t *ptr = *stack, *node = NULL;
	(void)line_number;

	node = malloc(sizeof(stack_t));
	if (!node)
	{
		fprintf(stderr, "Error: malloc failed");
		return;
	}
	if (!isEmpty())
	{
		if (stack_len() < 2)
			return;
		while (ptr->next)
			ptr = ptr->next;
		temp = ptr->n;
		if (ptr->prev)
			ptr->prev->next = NULL;
		free(ptr);
		node->n = temp;
		node->prev = (*stack)->prev;
		node->next = *stack;
		(*stack)->prev = node;
		*stack = node;
	}
}
