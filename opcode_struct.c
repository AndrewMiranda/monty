#include "monty.h"
/**
 * opcode_struct - Function for select parameter op.
 * @opcode: Entry parameter.
 * @stack: Double pointer to the head of the Stack.
 * @line_number: Number of the line.
 * Return: Nothing.
 */
int opcode_struct(char *opcode, stack_t **stack, unsigned int line_number)
{
	unsigned int i = 0;

	instruction_t op[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"nop", nop},
		{"pop", pop},
		{"swap", swap},
		{"add", _add},
		{"sub", _sub},
		{"div", _div},
		{NULL, NULL}
	};

	while (i < 9)
	{
		if (strcmp(op[i].opcode, opcode) == 0)
		{
			op[i].f(stack, line_number);
			return (EXIT_SUCCESS);
		}
		i++;
	}
	if (!op[i].opcode)
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
