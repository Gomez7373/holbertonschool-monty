#include "monty.h"

/**
* fail_exit - exits and closes the file, on command failed
* @file: file to close
* @cmd: memory to free
*
* Return: void, doenst return
*/
void fail_exit(FILE *file, char *cmd)
{
fclose(file);
free(cmd);
exit(EXIT_FAILURE);
}
