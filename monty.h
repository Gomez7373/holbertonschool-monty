#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define EMPTY_PUSH -36941
#define FAIL_VAL -49638

extern int number;

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
 * struct instruction_s - opcode and its function
* @opcode: the opcode
* @f: function to handle the opcode
*
* Description: opcode and its function
* for stack, queues, LIFO, FIFO
*/
typedef struct instruction_s
{
char *opcode;
void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void getopcode(char *filename, stack_t **stack, instruction_t opcode[]);
void free_stack(stack_t **stack);
void NoCmd(stack_t **stac, FILE *f, unsigned int n, char *c, char *s, char *l);
void fail_exit(FILE *f, char *cmd, stack_t **stack, char *str);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
char *Allocator(int amount);
void testingFunc(char *str, char *file);

#endif /* MONTY_H */

