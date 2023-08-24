#ifndef MONTY_H
#define MONTY_H

#define Buffsize 30

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/uio.h>
#include <errno.h>
#include <fcntl.h>
#include <ctype.h>

/**
 * struct stack_s - Doubly linked list representation of a stack (or queue)
 * @n: Integer value of the node
 * @prev: Ptr to the previous node in the queue/stack
 * @next: ptr to the next node in the queue/stack
 *
 * Description: DLL node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - Opcode and its function
 * @opcode: the opcode
 * @f: function that handles the opcode
 *
 * Description: opcode and its functions
 * for stack/queues, LIFO/FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct glob_var - golbal variable that holds prog
 * variables
 * @file: file name (monty file)
 * @buff: the getline buffer
 * @tmp: the getline counter
 * @dict: instruction dict
 * @head: ptr to the head of the dll
 * @line_number: the number of the current line
 * @MODE: indicates stack or queue
 */
typedef struct glob_var
{
	FILE *file;
	char *buff;
	size_t tmp;
	instruction_t *dict;
	stack_t *head;
	unsigned int line_number;
	int MODE;
} vars;


extern vars var;


int start_vars(vars *var);
instruction_t *create_instru();
int call_funct(vars *var, char *opcode);
void free_all(void);
int _isdigit(char *string);
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void sub(stack_t **stack, unsigned int line_number);
void push(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);
void pchar(stack_t **stack, unsigned int line_number);
void pstr(stack_t **stack, unsigned int line_number);
void rotl(stack_t **stack, unsigned int line_number);
void rotr(stack_t **stack, unsigned int line_number);
void divi(stack_t **stack, unsigned int line_number);
void mul(stack_t **stack, unsigned int line_number);
void mod(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void stack(stack_t **stack, unsigned int line_number);
void queue(stack_t **stack, unsigned int line_number);


#endif
