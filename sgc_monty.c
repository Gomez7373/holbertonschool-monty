/*
 * monty.c - A simple stack manipulation program using Monty bytecode instructions.
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "monty.h"
#define STACK_SIZE 100

int stack[STACK_SIZE];  /* Stack to hold integers*/
int top = -1;           /* Top of the stack*/

/**
* push - Pushes a value onto the stack.
* @value: The integer value to be pushed.
*
* If the stack is full, a stack overflow error is displayed and the program exits.
*/
void push(int value)
{
if (top == STACK_SIZE - 1)
{
fprintf(stderr, "Stack overflow\n");
exit(EXIT_FAILURE);
}
stack[++top] = value;
}

/**
* pop - Pops a value from the stack.
* @return: The popped integer value.
*
* If the stack is empty, a stack underflow error is displayed and the program exits.
 */
int pop()
{
if (top == -1)
{
fprintf(stderr, "Stack underflow\n");
exit(EXIT_FAILURE);
}
return (stack[top--]);
}

/**
* pall - Prints all values in the stack.
*
* Prints each value in the stack from top to bottom.
*/
void pall()
{
for (int i = top; i >= 0; --i)
{
printf("%d\n", stack[i]);
}
}

/**
* main - Entry point of the program.
 * Reads Monty bytecode instructions from a file and performs corresponding operations on the stack.
*
* Returns: 0 on successful execution.
 */
int main()
{
FILE *file = fopen("bytecodes/00.m", "r");
if (!file) {
fprintf(stderr, "Error opening file\n");
exit(EXIT_FAILURE);
}

char instruction[50];
int value;

while (fscanf(file, "%s", instruction) != EOF)
{
if (strcmp(instruction, "push") == 0)
{
fscanf(file, "%d", &value);
push(value);
} else if (strcmp(instruction, "pall") == 0)
{
pall();
} /*migth add more instructions as needed*/
}

fclose(file);

return (0);
}

