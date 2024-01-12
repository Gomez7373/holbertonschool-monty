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
 * testingFunc - just for testing deleting later
 * @str: string to edit
 * @file: file to print
 *
 * Return: void, doesnt return
 */
void testingFunc(char *str, char *file)
{
char buffer[1024];
FILE *openFile = fopen(file, "r");
int curr_line = 0;

while (fgets(buffer, sizeof(buffer), openFile) != NULL)
{
curr_line++;
fprintf(stdout, "OUTPUT, L%d: %s", curr_line, buffer);
fprintf(stderr, "error, L%d: %s", curr_line, buffer);
}
str[0] = '0';
fclose(openFile);
}
