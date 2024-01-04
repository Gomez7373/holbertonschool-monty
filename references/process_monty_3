#include "monty.h"
#include <stdio.h>
/**
 * process_file - Processes commands from a file.
 * @file: File pointer.
 */
void process_file(FILE *file)
{
char *line = NULL;
size_t len = 0;
ssize_t read;

while ((read = getline(&line, &len, file)) != -1)
{
/* Print the currently read line for indication */
/*printf("Processing command: %s", line);*/

/* will Implement logic here... */
execute_monty_command(line);

/* will  add more logic based on command execution needs... */
}

free(line);
}
