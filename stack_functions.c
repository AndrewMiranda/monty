#include "monty.h"

/**
 * new_Node - Create new node.
 * @n: Is a value.
 * Return: New node.
 */
stack_t *new_Node(int n)
{
	stack_t *node = NULL;

	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		dprintf(STDERR_FILENO, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	node->n = n;
	node->next = NULL;
	node->prev = NULL;

	return (node);
}

/**
 * push - This function pushes an element to the stack.
 * @stack: Double pointer to the head of the Stack.
 * @line_number: Number of the line.
 * Return: Nothing.
 */
void push(stack_t **stack, unsigned int line_number/* , char *n */)
{
	char *value = strtok(NULL, DELIMITERS);
	stack_t *new = NULL;
	int i = 0;
	(void)line_number;

	if (!value)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (value[i] != '\0')
	{
		if (!isdigit(value[i]) && value[i] != '-')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		i++;
	}

	new = new_Node(atoi(value));

	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}

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
