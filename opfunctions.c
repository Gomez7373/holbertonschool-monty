#include "monty.h"

/**
* fail_exit - exits and closes the file, on command failed
* @file: file to close
* @cmd: memory to free
* @stack: stack where fail happend
* @str: memory to free
*
* Return: void, doenst return
*/
void fail_exit(FILE *file, char *cmd, stack_t **stack, char *str)
{
printf("Exiting Because of the command: %s\n", cmd);
fclose(file);
free(str);
free(cmd);
free_stack(stack);
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
		number = FAIL_VAL;
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
		number = FAIL_VAL;
		return;
	}
}

/**
 * swap - swaps the top two elements
 * @stack: targeted stack
 * @line_number: line where the opcode was call
 *
 * Return: void, doesnt return
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;
	unsigned int len = 0;

	for (; curr != NULL; curr = curr->next)
	{
		len++;
	}
	if (len >= 2)
	{
		curr = *stack;
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		curr->prev = *stack;
		curr->next = (*stack)->next;
		if ((*stack)->next != NULL)
			(*stack)->next->prev = curr;
		(*stack)->next = curr;
	}
	else
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		number = FAIL_VAL;
		free_stack(stack);
		return;
	}
}

/**
 * add - adds the top two elements of the stack
 * @stack: targeted stack
 * @line_number: line where opcode was call
 *
 * Return: void, doesnt return
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *curr = *stack;
	int total = 0;
	unsigned int len = 0;

	for (; curr != NULL; curr = curr->next)
	{
		len++;
	}
	if (len >= 2)
	{
		curr = *stack;
		total += (*stack)->n + (*stack)->next->n;
		*stack = (*stack)->next;
		free(curr);
		(*stack)->n = total;
	}
	else
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		number = FAIL_VAL;
		free_stack(stack);
		return;
	}
}
