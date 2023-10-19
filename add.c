#include "monty.h"

/**
 * add - Adds the top two elements of the stack
 * @stack: pointer to the top of the stack
 * @line_number: line number in the file
 */

void add(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n += (*stack)->n;
	pop(stack, line_number);
}
