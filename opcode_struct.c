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
                {NULL, NULL}
        };

        while (i < 2)
        {
                if (strcmp(op[i].opcode, opcode) == 0)
                {
                        op[i].f(stack, line_number);
                        break;
                }
                i++;
        }
        if (!op[i].opcode)
        {
                fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
		exit(EXIT_FAILURE);
        }
        return (0);
}