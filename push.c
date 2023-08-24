#include "monty.h"
/**
 * push - Pushes an integer onto the stack.
 * @stack: Double linked list
 * @line_number: num of the line 
 */

void push(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = NULL, *tm = *stack;
	char *num;

	num = strtok(NULL, " \r\t\n");
	if (num == NULL || (_isdigit(num) != 0 && num[0] != '-'))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_all();
		exit(EXIT_FAILURE);
	}
	temp = malloc(sizeof(stack_t));
	if (!temp)
	{
		fprintf(stderr, "Error: malloc failed\n");
		free_all();
		exit(EXIT_FAILURE);
	}
	temp->n = atoi(num);
	if (var.MODE == 0 || !*stack)
	{
		temp->next = *stack;
		temp->prev = NULL;
		if (*stack)
			(*stack)->prev = temp;
		*stack = temp;
	}
	else
	{
		while (tm->next)
			tm = tm->next;
		tm->next = temp;
		temp->prev = tm;
		temp->next = NULL;
	}
}