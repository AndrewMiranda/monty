#include "monty.h"

/**
 * pall - Prints all the values on the stack,
 * starting from the top of the stack.
 * @stack: Double pointer to the head of the Stack.
 * @line_number: Number of the line.
 * Return: Nothing.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *node = *stack;
	(void)line_number;

	while (node != NULL)
	{
		dprintf(STDOUT_FILENO, "%d\n", node->n);
		node = node->next;
	}
}

/**
 * pint - Prints the value at the top of the stack.
 * @stack: Double pointer to the head of the Stack.
 * @line_number: Number of the line.
 * Return: Nothing.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !stack)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	dprintf(STDOUT_FILENO, "%d\n", (*stack)->n);
}
