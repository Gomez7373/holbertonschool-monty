#include "monty.h"

/**
 * nop - absolutly nothing will happen
 * @stack: targeted stack, to do nothing
 * @line_number: line where opcode was call
 *
 * Return: void, doesnt return
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
