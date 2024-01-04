/* main_monty_3.c */
#include "monty.h"

/**
* main - Entry point of the program.
* @argc: Arguments count.
* @argv: List of arguments.
* Return: Always 0.
*/

stack_t *head = NULL;  /*Globally defined head*/

int main(int argc, char *argv[])
{
if (argc != 2)
{
fprintf(stderr, "USAGE: monty file\n");
exit(EXIT_FAILURE);
}

FILE *file = open_file(argv[1]); /*Declares and initialize file*/
process_file(file);
/*free_nodes();*/
free_stack(&head);

fclose(file); /* Closes the file after processing*/

return (0);
}
