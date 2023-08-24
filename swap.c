#include "monty.h"

/**
 * swap - Swaps the top two elements on the stack.
 * @stack: Double linked list
 * @line_number: File line execution
 */
void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (!*stack || !(*stack)->next)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n",
			line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
}