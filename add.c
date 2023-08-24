#include "monty.h"

/**
 * add - Adds the top two elements and 
 * pushes the result onto the stack.
 * @stack: Double linked list
 * @line_number: File line execution
 */

void add(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n",
			line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n + (*stack)->n;
	pop(stack, line_number);
}