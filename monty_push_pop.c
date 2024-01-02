#include "monty.h"
/**
* struct stack_s - doubly linked list representation of a stack
* @n: integer
* @prev: points to the previous element of the stack
* @next: points to the next element of the stack
*
* Description: doubly linked list node structure for stack
*/
typedef struct stack_s
{
int n;                  /* Integer data */
struct stack_s *prev;   /* Points to the previous element of the stack */
struct stack_s *next;   /* Points to the next element of the stack */
} stack_t;

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
* main - entry point of the program
*
* Return: 0 on success
*/
int main(void)
{
stack_t *stack = NULL; /* Initialize an empty stack */

/* Example Monty bytecode: push 1, push 2, push 3, pall */
push(&stack, 1, 1);
push(&stack, 2, 2);
push(&stack, 3, 3);
pall(stack, 0);

return 0;
}

