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
		/*{"pop", pop_func},*/
		  /*{"nop", nop_func},*/
		 /* {"swap", swap_func},*/
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
	char *ptr = str;

	if (ptr)
	{
		while (*ptr)
		{
			if (*ptr < '0' || *ptr > '9')
				return (1);
			ptr++;
		}
	}
	return (0);
}

/**
 * g - executes a command line
 * @t: array of arguments
 * @f: file
 * @l: line number of instruction
 * @s: command line
 * Return: 0 if sucessful, 1 otherwise
 */
void (*g(char *s, char **t, FILE * f, size_t l))(stack_t **st, unsigned int l)
{
	void (*stack_func)(stack_t **stack, unsigned int line) = NULL;
	char *err = ": unknown instruction ";
	char *use = ": usage: push integer";
	char *p = "push";

	stack_func = opcode_check(t[0]);
	if (!stack_func)
		err_and_exit(s, t, f, "ciss", 'L', l, err, t[0]);

	if ((t && t[0] && !strcmp(t[0], p) && !t[1]) || (t && t[1] && hch(t[1])))
		err_and_exit(s, t, f, "cis", 'L', l, use);

	return (stack_func);
}
