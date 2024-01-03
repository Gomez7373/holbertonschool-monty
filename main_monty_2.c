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

stack_t *stack = NULL;
getopcode(argv[1], &stack);

/* Free the stack when done */
free_stack(&stack);

return (EXIT_SUCCESS);
}

/**
* free_stack - Frees a stack (linked list)
* @stack: Pointer to the top of the stack
*/
void free_stack(stack_t **stack)
{
stack_t *current = *stack;
stack_t *next;

while (current != NULL)
{
next = current->next;
free(current);
current = next;
}

*stack = NULL; 
/* Sets the original pointer to NULL to avoid using freed memory*/
}

