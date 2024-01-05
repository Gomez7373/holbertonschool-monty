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

/* Define the opcode array for Monty instructions */
instruction_t opcodes[] = {
{"push", push},
{"pall", pall},
{"pint", pint},
{NULL, NULL}};

stack_t *stack = NULL;  /* Initialize the stack pointer */

/* Call the Monty interpreter to process the bytecode file */
getopcode(argv[1], &stack, opcodes);

/* Free the allocated memory for the stack */
free_stack(&stack);

return (EXIT_SUCCESS);
}
