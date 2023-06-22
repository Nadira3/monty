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
                {"add", add_func},
                /*{"push", push_func},
                {"pop", pop_func},
                {"pint", pint_func},
                {"pall", pall_func},
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

        stack_func = opcode_check(tok[0]);
        if (!stack_func)
		err_and_exit(s, tok, f, "ciss", 'L', line, err, tok[0]);
        return (stack_func);
}
