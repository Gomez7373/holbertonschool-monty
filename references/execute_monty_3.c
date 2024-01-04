#include "monty.h"

/**
* execute_monty_command - Executes a Monty command.
* @command: The Monty command to execute.
*
* Return: 0 on success, -1 on failure.
*/
int execute_monty_command(char *command)
{
char *token;
int value;

/* Tokenizes the command to get the instruction and the optional value */
token = strtok(command, " \t\n");
if (token == NULL)
{
/* Empty line, skip */
return (0);
}
if (strcmp(token, "push") == 0)
{
/* Gets the next token as the value */
token = strtok(NULL, " \t\n");
if (token == NULL)
{
fprintf(stderr, "Error: push requires an argument\n");
return (-1);
}
/* Converts the token to an integer */
value = atoi(token);
/* Calls the push function here with the value */
/* Example: push(value); */
printf("Pushing value: %d\n", value);
}
else if (strcmp(token, "pall") == 0)
{
/* Calls your pall function here to print the stack */
/* Example: pall(); */
printf("Printing stack...\n");
}
else
{
/* Unknown command */
fprintf(stderr, "Error: Unknown command - %s\n", token);
return (-1);
}
return (0); /* Success */
}
