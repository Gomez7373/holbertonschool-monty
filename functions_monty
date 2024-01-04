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

/**
* push - pushes an element onto the stack
* @stack: double pointer to the head of the stack
* @value: value to push onto the stack
*
* Return: void
*/
void push(stack_t **stack, int value)
{

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
* getopcode - calls the desired function to execute at the stack
*@filename: target bytecode file
*@stack: targeted stack
*
* return: void, doesn't return
*/
void getopcode(char *filename, stack_t **stack)
{
	char *cmd = NULL;
	char chunk[16], number_str[32];
	size_t len = 0;
	ssize_t end_of_file;
	int curr_line = 0, number;
	FILE *file = fopen(filename, "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while ((end_of_file = getline(&cmd, &len, file)) != -1)
	{
		number_str[0] = '\0';
		curr_line++;
		if (sscanf(cmd, "%s %s", chunk, number_str) < 1)
			continue;
		strtok(chunk, " \t\n");
		if (strcmp(chunk, "push") == 0)
		{
			number = atoi(number_str);
			if (number_str[0] == '\0' && (number == 0 || number_str[0] != '0'))
			{
				fprintf(stderr, "L%d: usage: push integer\n", curr_line);
				free(cmd);
				fclose(file);
				exit(EXIT_FAILURE);
			}
			push(stack, number);
		}
		else if (strcmp(chunk, "pall") == 0)
		{
			pall(stack, 0);
		}
	}
	free(cmd);
	fclose(file);
}
