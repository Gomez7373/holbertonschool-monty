#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>

/**
* struct stack_s - Doubly linked list representation of a stack (or queue)
* @n: Integer value stored in the node
* @prev: Pointer to the previous element in the stack (or queue)
* @next: Pointer to the next element in the stack (or queue)
*/
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
} stack_t;

/**
* push - Adds a new node at the beginning of a stack (or queue)
* @stack: Pointer to the pointer to the stack (or queue)
* @line_number: Line number of the opcode being executed
* @value: Integer value to be added to the stack (or queue)
*/
void push(stack_t **stack, unsigned int line_number, int value);

/**
* pall - Prints all the values on a stack (or queue)
* @stack: Pointer to the stack (or queue)
* @line_number: Line number of the opcode being executed
*/
void pall(stack_t *stack, unsigned int line_number);

#endif /* MONTY_H */

