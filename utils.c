#include "monty.h"

/**
 * free_stack - Free the stack
 * @stack: pointer to the top of the stack
 */

void free_stack(stack_t *stack)
{
	stack_t *tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}

/**
 * get_op_func - Searches for the corresponding function pointer
 *                based on the given opcode.
 * @opcode: The opcode to search for.
 *
 * Return: If a match is found, returns the corresponding function pointer.
 *         If no match is found, returns NULL.
 */

void (*get_op_func(char *opcode))(stack_t **, unsigned int)
{
	instruction_t op_funcs[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", div_op},
		{"mul", mul_op},
		{"mod", mod_op},
		{NULL, NULL}
	};

	int i = 0;

	while (op_funcs[i].opcode)
	{
		if (strcmp(op_funcs[i].opcode, opcode) == 0)
			return (op_funcs[i].f);
		i++;
	}

	return (NULL);
}

/**
 * p_err_ext - Prints an error message, frees resources, and exits.
 * @message: The error message to print.
 * @file: File to be closed.
 * @line: Line buffer to be freed.
 * @stack: Stack to be freed.
 *
 * This function prints an error message to stderr, frees allocated memory,
 * and exits with EXIT_FAILURE.
 */

void p_err_ext(const char *message, FILE *file, char *line, stack_t *stack)
{
	fprintf(stderr, "%s", message);
	if (file)
		fclose(file);
	if (line)
		free(line);
	if (stack)
		free_stack(stack);
	exit(EXIT_FAILURE);
}
