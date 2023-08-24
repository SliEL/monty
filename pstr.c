#include "monty.h"

/**
 * pstr - Prints the string starting 
 * from the top of the stack.
 * @stack: Double linked list
 * @line_number: File line execution
 */
void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;
	(void) line_number;

	if (!stack || !*stack)
	{
		putchar('\n');
		return;
	}
	while (temp)
	{
		if (temp->n == 0)
			break;
		if (!isascii((temp)->n))
			break;
		putchar(temp->n);
		temp = temp->next;
	}
	putchar('\n');
}
