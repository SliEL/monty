#include "monty.h"

/**
 * sub - Subtracts the top element from the
 * second top element and pushes the result.
 * @stack: Double linked list
 * @line_number: Line counter
 */
void sub(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n",
			line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n - (*stack)->n;
	pop(stack, line_number);
}