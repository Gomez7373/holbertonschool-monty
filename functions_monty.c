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
if (number == -3694)
{
fprintf(stderr, "L%d: usage: push integer\n", line_number);
free_stack(stack);
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
char *cmd = NULL;
char chunk[16], number_str[32];
size_t len = 0;
unsigned int curr_line = 0, found = 0, i;
FILE *file = fopen(filename, "r");

if (file == NULL)
{
fprintf(stderr, "Error: Can't open file %s\n", filename);
exit(EXIT_FAILURE);
}
while (getline(&cmd, &len, file) != -1)
{
number_str[0] = '\0';
curr_line++;
found = 0;
if (sscanf(cmd, "%s %s", chunk, number_str) < 1)
continue;
strtok(cmd, "\n");
strtok(chunk, " \t\n");
strtok(number_str, " \t\n");
number = atoi(number_str);
if (number == 0 && number_str[0] != '0')
number = -3694;
/*-------------------------------------------*/
printf("Line %d: Opcode: %s\n", curr_line, chunk);

for (i = 0; opcodes[i].opcode != NULL; i++)
{
    if (strcmp(chunk, opcodes[i].opcode) == 0)
    {
        opcodes[i].f(stack, curr_line);
        found = 1;
        if (*stack == NULL && strcmp(opcodes[i].opcode, "pall") != 0)
            fail_exit(file, cmd);
    }
}

if (!found)
    invalidCommand(stack, file, curr_line, cmd);

/*----------------------------------------------------*/
}
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
* invalidCommand - prints error when no command is found
* @stack: the stack to free
* @file: file to close before exit
* @line: in what line the error happen
* @cmd: what command was tried
*
* Return: void, doenst return
*/
void invalidCommand(stack_t **stack, FILE *file, unsigned int line, char *cmd)
{
fprintf(stderr, "L%d: unknown instruction %s\n", line, cmd);
free_stack(stack);
fclose(file);
free(cmd);
exit(EXIT_FAILURE);
}
/*--------------------------------------------*/


/**
* pint - prints the value at the top of the stack
* @stack: pointer to the head of the stack
* @line_number: line number in the Monty file
*
* Return: void
*/

void pint(stack_t **stack, unsigned int line_number)
{
printf("Debug: Inside pint function, stack size: %zu\n", stack_size(*stack));

if (*stack == NULL)
{
fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
free_stack(stack);
exit(EXIT_FAILURE);
}

printf("%d\n", (*stack)->n);
}


/*-------------------------------------------------*/

size_t stack_size(stack_t *stack)
{
    size_t size = 0;
    stack_t *current = stack;

    while (current != NULL)
    {
        size++;
        current = current->next;
    }

    return size;
}

