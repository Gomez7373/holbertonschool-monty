#include "monty.h"

/**
* fail_exit - exits and closes the file, on command failed
* @file: file to close
* @cmd: memory to free
*
* Return: void, doenst return
*/
void fail_exit(FILE *file, char *cmd)
{
fclose(file);
free(cmd);
exit(EXIT_FAILURE);
}

/**
 * pint - prints the value at the top of the stack
 * @stack: targeted stack
 * @line_number: line where the command was executed
 *
 * Return: void, doesnt return
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack != NULL && *stack != NULL)
	{
		printf("%d\n", (*stack)->n);
	}
	else
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		free_stack(stack);
		return;
	}
}

/**
 * pop - removes the top element of the stack
 * @stack: targeted stack
 * @line_number: Line where command was executed
 *
 * Return: void doesnt return
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;

	if (stack != NULL && *stack != NULL)
	{
		*stack = (*stack)->next;
		if (*stack != NULL)
			(*stack)->prev = NULL;
		free(curr);
	}
	else
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_stack(stack);
		return;
	}
}
