#include "monty.h"
/**
 * usage_check - checks for program usage error
 * @arg_count: argument count
 * @file: file stream
 * @path: file name including path
 */
void usage_check(int arg_count, FILE *file, char *path)
{
	char *filename = NULL;

	if (arg_count != 2)
		err_and_exit(NULL, NULL, NULL, "s", "USAGE: monty file");
	filename = basename(path);
	if (!file)
		err_and_exit(NULL, NULL, NULL, "ss", "Error: Can't open file ", filename);
}
/**
 * print_char - prints a character
 * @pam: va_list containing the character to print
 */
void print_char(va_list pam)
{
	fprintf(stderr, "%c", va_arg(pam, int));
}
/**
 * print_int - prints an integer
 * @pam: va_list containing the integer to print
 */
void print_int(va_list pam)
{
	fprintf(stderr, "%u", va_arg(pam, int));
}
/**
 * print_string - prints a string
 * @pam: va_list containing the string to print
 */
void print_string(va_list pam)
{
	char *ptr = va_arg(pam, char *);

	fprintf(stderr, "%s", ptr ? ptr : "(nil)");
}

/**
 * err_and_exit - fill later
 * @s: string
 * @tok: array
 * @f: file
 * @format: format
 */
void err_and_exit(char *s, char **tok, FILE *f, const char * const format, ...)
{
	va_list pam;
	int i = 0, j;
	void (*print_func)(va_list);

	form_t forms[] = {
		{"c", print_char},
		{"i", print_int},
		{"s", print_string},
		{NULL, NULL}
	};

	va_start(pam, format);

	while (format && format[i])
	{
		j = 0;
		while (forms[j].format)
		{
			if (*(forms[j].format) == format[i])
			{
				print_func = forms[j].f;
				print_func(pam);
				break;
			}
			j++;
		}
		i++;
		va_end(pam);
	}
	puts("\n");
	if (s)
		free(s);
	if (tok)
		free_buf(tok);
	if (f)
		fclose(f);
	if (stack)
		free_stack(&stack);
	exit(EXIT_FAILURE);
}
