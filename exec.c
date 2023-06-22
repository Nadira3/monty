#include "monty.h"

global_t *make_node(void)
{
	global_t *global_node = malloc(sizeof(global_t));
	if (!global_node)
		err_and_exit(NULL, NULL, NULL, "s", "Error: malloc failed");
	global_node->n = 0;
	global_node->top = NULL;
	global_node->tail = NULL;
	return (global_node);
}
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
                /*{"pop", pop_func},
                {"pint", pint_func},
                {"nop", nop_func},
                {"swap", swap_func},*/
                {NULL, NULL}
        };

        if (command)
        {
                while(instruction[i].opcode)
                {
                        if (!(strcmp(command, instruction[i].opcode)))
                                return (instruction[i].f);
                        i++;
                }
        }
        return (instruction[i].f);
}

int hasch(char *str)
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
 * execute - executes a command line
 * @input_token: array of arguments
 * @line_number: line number of instruction
 * @input: command line
 * Return: 0 if sucessful, 1 otherwise
 */
void (*get_func(char *s, char **tok, FILE *f, size_t line))(stack_t **stack, unsigned int line)
{
        void (*stack_func)(stack_t **stack, unsigned int line) = NULL;
	char *err = ": unknown instruction ";
	char *use = ": usage: push integer";

        stack_func = opcode_check(tok[0]);
        if (!stack_func)
		err_and_exit(s, tok, f, "ciss", 'L', line, err, tok[0]);


	if ((tok && tok[0] && !strcmp(tok[0], "push") && !tok[1]) || (tok && tok[1] && hasch(tok[1])))
		err_and_exit(s, tok, f, "cis", 'L', line, use);
		
        return (stack_func);
}
