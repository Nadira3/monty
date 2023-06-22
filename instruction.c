#include "monty.h"

int isEmpty()
{
	if (!(globv->top))
		return (1);
	return (0);
}

void push_func(stack_t **stack, unsigned int line_number)
{
	stack_t *node = malloc(sizeof(stack_t));
	(void)stack;
	(void)line_number;

	if (!node)
	{
		fprintf(stderr, "Error: malloc failed");
		return;
	}
	node->prev = NULL;
	node->next = NULL;
	node->n = globv->n;
	if (!isEmpty())
	{
		node->next = globv->top;
		(globv->top)->prev = node;
	}
	globv->top = node;
}
void pall_func(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr = globv->top;
	(void)stack;
	(void)line_number;

	if (!isEmpty())
	{
		while (ptr)
		{
			printf("%d\n", ptr->n);
			ptr = ptr->next;
		}
	}
}
