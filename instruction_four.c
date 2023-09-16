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

	if (stack_len() < 2)
		return;
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
		node->prev = (*stack)->prev;
		node->next = *stack;
		(*stack)->prev = node;
		*stack = node;
	}
}

/**
 * push_queue - pushes a node to the stack in FIFO
 * @stack: stack
 * @line_number: line number of file
 */
void push_queue(stack_t **stack, unsigned int line_number)
{
	stack_t *node = malloc(sizeof(stack_t));
	stack_t *ptr = NULL;
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
		ptr = *stack;
		while (ptr->next)
			ptr = ptr->next;

		ptr->next = node;
		node->prev = ptr;
	}
	else
		stack = node;
}
