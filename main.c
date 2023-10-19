#include "monty.h"

/**
 * main - Entry point for the Monty bytecode interpreter.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line argument strings.
 *
 * Return: On success, returns EXIT_SUCCESS. On failure, returns EXIT_FAILURE.
 *
 * Description:
 * 1. Reads Monty bytecode from a file specified in the command-line arguments.
 * 2. Parses each line of bytecode and executes the corresponding operation.
 * 3. Handles errors, such as invalid instructions or file access issues.
 * 4. Frees allocated memory and resources before exiting.
 */

int main(int argc, char *argv[])
{
	FILE *file;
	char *line = NULL;
	size_t len = 0;
	ssize_t read;
	unsigned int line_number = 0;
	char *opcode;
	stack_t *stack = NULL;
	void (*op_func)(stack_t **stack, unsigned int line_number);

	if (argc != 2)
		p_err_ext("USAGE: monty file\n", NULL, NULL, NULL);

	file = fopen(argv[1], "r");
	if (!file)
		p_err_ext("Error: Can't open file %s\n", NULL, NULL, NULL);

	while ((read = getline(&line, &len, file)) != -1)
	{
		line_number++;
		opcode = strtok(line, " \t\n");

		if (opcode && opcode[0] != '#')
		{
			op_func = get_op_func(opcode);
			if (op_func)
				op_func(&stack, line_number);
			else
			{
				fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
				p_err_ext("", file, line, stack);
			}
		}
	}

	free(line);
	fclose(file);
	free_stack(stack);

	return (EXIT_SUCCESS);
}
