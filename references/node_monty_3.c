/* node_monty_3.c */
#include "monty.h"

/**
* create_node - Creates a node.
* @n: Number to go inside the node.
* Return: Upon success, a pointer to the node. Otherwise, NULL.
*/
stack_t *create_node(int n)
{
stack_t *node = malloc(sizeof(stack_t));
if (node == NULL)
exit(EXIT_FAILURE);

node->next = NULL;
node->prev = NULL;
node->n = n;

return (node);
}
