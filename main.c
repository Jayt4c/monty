#include "monty.h"
/**
 * main - entry point of the program..
 * @argc: the number of arguments passed to program.
 * @argv: 1D array of arguments passed to program.
 * Return: always 0 (success).
 */
int main(int argc, char *argv[])
{
	char buf[1024];
	unsigned int line_number;
	FILE *file;
	char *tokens[2];
	stack_t *stack = NULL;
	int i = 0;
	const char *delim = " \n\t";

	if (argc == 1 || argc > 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	line_number = 0;

	while (fgets(buf, sizeof(buf), file) != NULL)
	{
		line_number++;
		tokens[i] = strtok(buf, delim);
		while (i < 1)
		{
			i++;
			tokens[i] = strtok(NULL, delim);
		}
		exec_op(tokens, &stack, line_number);
		i = 0;
	}
	freestack(stack);
	fclose(file);

	return (0);
}
