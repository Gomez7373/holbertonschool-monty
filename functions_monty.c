#include "monty.h"

/**
* pall - prints all values on the stack
* @stack: pointer to the head of the stack
* @line_number: line number in the Monty file
*
* Return: void
*/
void pall(stack_t **stack, unsigned int line_number)
{
(void)line_number; /* Unused parameter */
stack_t *curr = *stack;

while (curr != NULL)
{
printf("%d\n", curr->n);
curr = curr->next;
}
}

/*-----------------------------------------*/

/**
* push - pushes an element onto the stack
* @stack: double pointer to the head of the stack
* @line_number: line where the command was call
*
* Return: void
*/
void push(stack_t **stack, unsigned int line_number)
{
if (number == EMPTY_PUSH)
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
free_stack(stack);
number = FAIL_VAL;
return;
}
stack_t *new_node = malloc(sizeof(stack_t));

if (new_node == NULL)
{
fprintf(stderr, "Error: malloc failed\n");
free_stack(stack);
return;
}

new_node->n = number;
new_node->prev = NULL;
new_node->next = *stack;

if (*stack != NULL)
(*stack)->prev = new_node;

*stack = new_node;
}

/*-----------------------------------------*/

/**
* getopcode - calls the desired function to execute at the stack
*@filename: target bytecode file
*@stack: targeted stack
*@opcodes: array of intruction_t structs
*
* return: void, doesn't return
*/
void getopcode(char *filename, stack_t **stack, instruction_t *opcodes)
{
	char *cmd = NULL, *number_str = NULL;
	char chunk[16];
	size_t len = 0;
	unsigned int curr_line = 0, found = 0, i;
	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
	fprintf(stderr, "Error: Can't open file %s\n", filename);
	exit(EXIT_FAILURE);
	}
	number_str = Allocator(64);
	while (getline(&cmd, &len, file) != -1)
	{
		number_str[0] = '\0';
		curr_line++;
		found = 0;
		if (sscanf(cmd, "%s %s", chunk, number_str) < 1)
			continue;
		number = atoi(number_str);
		if (number == 0 && number_str[0] != '0')
			number = EMPTY_PUSH;
		for (i = 0; opcodes[i].opcode != NULL; i++)
		{
			if (strcmp(chunk, opcodes[i].opcode) == 0)
			{
				opcodes[i].f(stack, curr_line);
				found = 1;
				if (number == FAIL_VAL)
					fail_exit(file, cmd, stack, number_str, curr_line);
			}
		}
		if (!found)
			NoCmd(stack, file, curr_line, cmd, number_str, chunk);
	}
	free(number_str);
	free(cmd);
	fclose(file);
}

/*-----------------------------------------*/

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
}

/*-----------------------------------------*/

/**
* NoCmd - prints error when no command is found
* @stac: the stack to free
* @f: file to close before exit
* @n: in what line the error happen
* @c: what command was tried
* @s: memory to free
* @l: line of command
*
* Return: void, doenst return
*/
void NoCmd(stack_t **stac, FILE *f, unsigned int n, char *c, char *s, char *l)
{
fprintf(stderr, "L%d: unknown instruction %s\n", n, l);
free_stack(stac);
fclose(f);
free(s);
free(c);
exit(EXIT_FAILURE);
}
