#include "monty.h"

/**
 * nop - absolutly nothing will happen
 * @stack: targeted stack, to do nothing
 * @line_number: line where opcode was call
 *
 * Return: void, doesnt return
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}

/**
 * Allocator - allocates memory with malloc
 * @amount: amount of memory to allocate
 *
 * Return: allocated memory, NULL otherwise
 */
char *Allocator(int amount)
{
	char *str;

	str = malloc(amount);
	if (str == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	return (str);
}

/**
 * validInt - verify string for valid ints
 * @str: string to check/edit
 *
 * Return: void, doesnt return
 */
int validInt(char *str)
{
	int i;
	int is_digit = 1;

	if (strcmp(str, "-0") == 0)
		str[0] = '0';

	for (i = 0; str[i] != '\0'; i++)
	{
		if (i == 0 && str[i] == '-')
			continue;
		if (!isdigit(str[i]))
			is_digit = 0;
	}
	if (is_digit)
		return (atoi(str));
	else
		return (0);
}
