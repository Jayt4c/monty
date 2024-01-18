#ifndef _MONTY_H_
#define _MONTY_H_

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

extern char *value;

int main(int argc, char *argv[]);
char *fgets(char *str, int n, FILE *stream);
int isdig(char *s);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_n);
void pint(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_n);
void add(stack_t **top_ptr, unsigned int line_n);
void nop(stack_t **stack, unsigned int line_n);
void exec_op(char *tokens[], stack_t **stack, unsigned int line_number);
void freestack(stack_t *head);

#endif
