#define MONTY_H
#ifdef MONTY_H

/*posible library, any library not used will be deleated*/
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>
#include <ctype.h>
#include <stdbool.h>
#include <stdarg.h>
#include <limits.h>
#include <fcntl.h>

/*The prototypes header file*/
void push(stack_t **stack, unsigned int line_number, int value);
void pall(stack_t *stack, unsigned int line_number);
int main(void);
#endif /*MONTY_H*/
