#include "monty.h"

/**
 * create_instru - functions instruction 
 * Return: Dictionary pointer
 */
instruction_t *create_instru()
{
	instruction_t *p = malloc(sizeof(instruction_t) * 18);

	if (!p)
	{
		fprintf(stderr, "Error: malloc failed\n");
		return (NULL);
	}
	p[0].opcode = "push", p[0].f = push;
	p[1].opcode = "pall", p[1].f = pall;
	p[2].opcode = "pint", p[2].f = pint;
	p[3].opcode = "swap", p[3].f = swap;
	p[4].opcode = "pop", p[4].f = pop;
	p[5].opcode = "add", p[5].f = add;
	p[6].opcode = "nop", p[6].f = NULL;
	p[7].opcode = "div", p[7].f = divi;
	p[8].opcode = "sub", p[8].f = sub;
	p[9].opcode = "mul", p[9].f = mul;
	p[10].opcode = "mod", p[10].f = mod;
	p[11].opcode = "pchar", p[11].f = pchar;
	p[12].opcode = "pstr", p[12].f = pstr;
	p[13].opcode = "queue", p[13].f = queue;
	p[14].opcode = "stack", p[14].f = stack;
	p[15].opcode = NULL, p[15].f = NULL;

	return (p);
}

/**
 * call_funct - trigger functions after reading the line
 * @var: interpreter global vars
 * @opcode: func to execute
 * Return: Nothing
 */
int call_funct(vars *var, char *opcode)
{
	int index;

	for (index = 0; var->dict[index].opcode; index++)
		if (strcmp(opcode, var->dict[index].opcode) == 0)
		{
			if (!var->dict[index].f)
				return (EXIT_SUCCESS);
			var->dict[index].f(&var->head, var->line_number);
			return (EXIT_SUCCESS);
		}
	if (strlen(opcode) != 0 && opcode[0] != '#')
	{
		fprintf(stderr, "L%d: unknown instruction %s\n",
			var->line_number, opcode);
		return (EXIT_FAILURE);
	}

	return (EXIT_SUCCESS);
}


/**
 * free_all - free all program mallocs
 * Return: None
 */
void free_all(void)
{
	if (var.buff != NULL)
		free(var.buff);

	if (var.file != NULL)
		fclose(var.file);
	/*free the dictionary */
	free(var.dict);

	if (var.head != NULL)
	{
		while (var.head->next != NULL)
		{
			var.head = var.head->next;
			free(var.head->prev);
		}
		free(var.head);
	}
}

/**
 * _isdigit - check if str is a digit
 * @string: Num to validate
 * Return: 0 Success, 1 Failed
 */
int _isdigit(char *string)
{
	int index;

	for (index = 0; string[index]; index++)
	{
		if (string[index] < 48 || string[index] > 57)
			return (1);
	}
	return (0);
}
