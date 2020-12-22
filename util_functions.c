#include "monty.h"

/**
 * free_stack - Free a stack.
 * @stack: Head node.
 * Return: Nothing.
 */
void free_stack(stack_t *stack)
{
	stack_t *current = stack;

	if (current != NULL)
	{
		free_stack(current->next);
		free(current);
	}
}
