#include "monty.h"
#include <stdio.h>
#include <stdlib.h>

/**
* push - pushes an element onto the stack
* @stack: double pointer to the head of the stack
* @line_number: line number in the Monty file
* @value: value to push onto the stack
*
* Return: void
*/
void push(stack_t **stack, unsigned int line_number, int value)
{
(void)line_number; /* Unused parameter for now */

stack_t *new_node = malloc(sizeof(stack_t));

if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
exit(EXIT_FAILURE);
}

new_node->n = value;
new_node->prev = NULL;
new_node->next = *stack;

if (*stack != NULL)
(*stack)->prev = new_node;

*stack = new_node;
}

/**
 * pall - prints all values on the stack
* @stack: pointer to the head of the stack
* @line_number: line number in the Monty file
*
* Return: void
*/
void pall(stack_t *stack, unsigned int line_number)
{
(void)line_number; /* Unused parameter */

while (stack != NULL)
{
printf("%d\n", stack->n);
stack = stack->next;
}
}

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

/* Open the specified file for reading */
FILE *file = fopen(argv[1], "r");
if (file == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
exit(EXIT_FAILURE);
}

/* TODO:
 Read and process Monty bytecodes line by line
Example:
while (fgets(buffer, sizeof(buffer), file) != NULL)
{
process_instruction(buffer);
}
Close the file after processing */
fclose(file);

return (EXIT_SUCCESS);
}

