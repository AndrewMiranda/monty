#include "monty.h"

/**
 * add - This function adds the top two elements of the stack.
 * @stack: Double pointer to the head of the Stack.
 * @line_number: Number of the line.
 * Return: Nothing.
 */
void _add(stack_t **stack, unsigned int line_number)
{
	stack_t *node = NULL;
	int sum = 0;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	node = *stack;
	sum += node->n + node->next->n;
	node->next->n = sum;
	pop(stack, line_number);
}
