#include "monty.h"

/**
 * pall - Prints all values in the stack,
 * starting from the top
 * @stack: Double linked list
 * @line_number: File line execution
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void) line_number;

	if (!temp)
		return;
	while (temp)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}