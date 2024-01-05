#include "monty.h"

/**
* main - Entry point of the Monty interpreter
* @argc: Number of command-line arguments
* @argv: Array of command-line arguments
*
* Return: EXIT_SUCCESS on success, EXIT_FAILURE on failure
*/
int main(int argc, char *argv[])
{
/* Check if the correct number of command-line arguments is provided */
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}
instruction_t opcodes[] = {
	{"push", push},
	{"pall", pall},
	{"pint", pint},
	{"pop", pop},
	{"swap", swap},
	{NULL, NULL}
};
stack_t *stack = NULL;

getopcode(argv[1], &stack, opcodes);
free_stack(&stack);

return (0);
}
