#include "monty.h"

/**
 * mul_op - Multiplies the second top element of the stack with the top element.
 * @stack: Pointer to the top of the stack.
 * @line_number: Line number in the file.
 */

void mul_op(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*stack)->next->n *= (*stack)->n;
	pop(stack, line_number);
}
