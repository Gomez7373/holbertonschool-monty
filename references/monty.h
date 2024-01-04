#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
* struct stack_s - Doubly linked list representation of a stack (or queue)
* @n: Integer (node data)
* @prev: Points to the previous element of the stack (or queue)
* @next: Points to the next element of the stack (or queue)
*/
typedef struct stack_s
{
int n;
struct stack_s *prev;
struct stack_s *next;
}
stack_t;

extern stack_t *head;

/* Function prototypes */
void free_nodes(void);
stack_t *create_node(int n);
void add_to_queue(stack_t **new_node);
void free_stack(stack_t **stack);
int execute_monty_command(char *command);
void process_file(FILE *file);
FILE *open_file(const char *filename);

/* Inline function definition */
/**
* free_stack - Frees a stack (linked list)
* @stack: Pointer to the top of the stack
*/
void free_stack(stack_t **stack);

#endif /* MONTY_H */
