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
		while (ptr->next)
			ptr = ptr->next;
		temp = ptr->n;
		ptr->prev->next = NULL;
		free(ptr);
		node->n = temp;
		node->prev = NULL;
		node->next = *stack;
		*stack = node;
	}
}
