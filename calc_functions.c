#include "monty.h"

/**
 * _add - This function adds the top two elements of the stack.
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

/**
 * sub - Subtracts the top element of the stack
 * from the second top element of the stack.
 * @stack: Double pointer to the head of the Stack.
 * @line_number: Number of the line.
 * Return: Nothing.
 */
void _sub(stack_t **stack, unsigned int line_number)
{
	stack_t *node = NULL;
	int sub = 0;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	node = *stack;
	sub = node->next->n - node->n;
	node->next->n = sub;
	pop(stack, line_number);
}

void _div(stack_t **stack, unsigned int line_number)
{
	stack_t *node = NULL;
	int div = 0;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	node = *stack;
	div = node->next->n / node->n;
	node->next->n = div;
	pop(stack, line_number);
}
