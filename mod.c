#include "monty.h"

/**
 * mod - Computes the modulus of the second top 
 * element by the top element and pushes the result.
 * @stack: Double linked list
 * @line_number: File line execution
 */
void mod(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n",
			line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n = (*stack)->next->n % (*stack)->n;
	pop(stack, line_number);
}