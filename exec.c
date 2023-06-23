#include "monty.h"

/**
 * opcode_check - checks the validity of an instruction
 * @command: opcode instruction
 * Return: function pointer
 */
void (*opcode_check(char *command))(stack_t **stack, unsigned int line_number)
{
	int i = 0;
	instruction_t instruction[] = {
		{"push", push_func},
		{"pall", pall_func},
		{"pint", pint_func},
		{"pop", pop_func},
		{"nop", nop_func},
		{"swap", swap_func},
		{"add", add_func},
		{"sub", sub_func},
		{"div", div_func},
		{"mul", mul_func},
		{"mod", mod_func},
		{"pchar", pchar_func},
		{"pstr", pstr_func},
		{"rotl", rotl_func},
		{"rotr", rotr_func},
		{NULL, NULL}
	};

	if (command)
	{
		while (instruction[i].opcode)
		{
			if (!(strcmp(command, instruction[i].opcode)))
				return (instruction[i].f);
			i++;
		}
	}
	return (instruction[i].f);
}

/**
 * hch - checks if a string is an integer
 * @str: string
 * Return: 0 or 1
 */
int hch(char *str)
{
	int i = 0;

	if (str)
	{
		while (str[i])
		{
			if (i == 0 && str[i] == '-')
			{
				i++;
				continue;
			}
			if (str[i] < '0' || str[i] > '9')
				return (1);
			i++;
		}
	}
	return (0);
}

/**
 * cmp - compares to string to check if they are an exact match
 * @str1: first string
 * @str2: second string
 * Return: 1 if strings match, otherwise 0
 */
int cmp(char *str1, char *str2)
{
	char *ptr1 = str1, *ptr2 = str2;

	if (!str1 || !str2)
		return (0);
	if (ptr1 && ptr2)
	{
		while (*ptr1 || *ptr2)
		{
			if (*ptr2 != *ptr1)
				return (1);
			ptr1++;
			ptr2++;
		}
	}
	return (0);
}

/**
 * stack_check - checks if the stack is empty or has enough
 * parameters for instruction action
 * @s: input
 * @t: argument token
 * @f: file
 * @l: line number
 */
void stack_check(char *s, char **t, FILE *f, size_t l)
{
	char *inst[8] = {"pint", "pop", "add", "swap", "sub", "mul", "div", "mod"};
	char *pt = ": can't ", *err, *len = ", stack too short";
	char *div_err = ": division by zero", *str_err = ", value out of range";
	int i = 0;

	err = strcmp(*t, "pop") ? ", stack empty" : " an empty stack";
	if (!strcmp(*t, "pchar"))
	{
		if (isEmpty())
			err_and_exit(s, t, f, "cisss", 'L', l, pt, *t, err);
		if (!isascii(stack->n))
			err_and_exit(s, t, f, "cisss", 'L', l, pt, *t, str_err);
	}
	while (i < 8)
	{
		if (!strcmp(*t, inst[i]))
		{
			if (i < 2 && isEmpty())
				err_and_exit(s, t, f, "cisss", 'L', l, pt, *t, err);
			else if (i > 1 && stack_len() < 2)
				err_and_exit(s, t, f, "cisss", 'L', l, pt, *t, len);
			if (i > 5 && stack->n == 0)
				err_and_exit(s, t, f, "cis", 'L', l, div_err);
		}
		i++;
	}
}
/**
 * g - executes a command line
 * @t: array of arguments
 * @f: file
 * @l: line number of instruction
 * @s: command line
 * Return: 0 if sucessful, 1 otherwise
 */
void (*g(char *s, char **t, FILE *f, size_t l))(stack_t **st, unsigned int l)
{
	void (*stack_func)(stack_t **stack, unsigned int line) = NULL;
	char *err = ": unknown instruction ";
	char *use = ": usage: push integer";
	char *p = "push";

	stack_func = opcode_check(t[0]);
	if (!stack_func)
		err_and_exit(s, t, f, "ciss", 'L', l, err, t[0]);

	if ((t && *t && !cmp(*t, p) && !t[1]) || (!cmp(*t, p) && t[1] && hch(t[1])))
		err_and_exit(s, t, f, "cis", 'L', l, use);
	if (t)
		stack_check(s, t, f, l);
	return (stack_func);
}
