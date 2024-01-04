#include "monty.h"

/**
* open_file - Opens a file and returns a FILE pointer.
* @filename: The name of the file to be opened.
*
* Return: A FILE pointer on success, exits with EXIT_FAILURE on failure.
*/
FILE *open_file(const char *filename)
{
FILE *file = fopen(filename, "r");

if (file == NULL)
{
fprintf(stderr, "Error opening file: %s\n", filename);
exit(EXIT_FAILURE);
}

return (file);
}
