#include "monty.h"

/**
 * main - main function of monty program
 * @argc: number of arguments
 * @argv: pointer to array of strings of arguments
 * Return: 0 on success, -1 on failure
 */
int main(int argc, char *argv[])
{
	FILE *fd = NULL;
	stack_t *stack = NULL;
	char *argument = NULL, *line = NULL;
	size_t lineSize = 0;
	unsigned int line_number = 0; 

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}
	fd = fopen(argv[1], "r");
	if (fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (getline(&line, &lineSize, fd) != EOF)
	{
		line_number++;
		argument = strtok(line, DELIMITERS);
		if (argument == NULL)
		{
			free(argument);
			continue;
		}
		else if (*argument == '#')
		{
			continue;
		}
		opcode_struct(argument, &stack, line_number);
	}
	if (line)
		free(line);
	fclose(fd);
	
	return (0);
}
