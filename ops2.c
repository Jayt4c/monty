#include "monty.h"
/**
 * add - adds top 2 elements of stack.
 * @stack: stack to perform operation on.
 * @line_n: line number of opcode.
 * Return: unnecessary as function returns void.
 */
void add(stack_t **stack, unsigned int line_n)
{
	stack_t *top = *stack;

	if (!top || !top->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}

	top->next->n += top->n;
	pop(stack, line_n);
}
/**
 * nop - does nothing.
 * @stack: stack to perform operation on.
 * @line_n: line number of opcode.
 * Return: nothing.
 */
void nop(stack_t **stack, unsigned int line_n)
{
	*stack = *stack;
	line_n = line_n;
}
/**
 * sub - subtracts top element from 2nd top.
 * @stack: stack to perform operation on.
 * @line_n: line number of opcode.
 * Return: nothing.
 */
void sub(stack_t **stack, unsigned int line_n)
{
	stack_t *top = *stack;

	if (!top || !top->next)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}

	top->next->n -= top->n;
	pop(stack, line_n);
}
/**
 * mul - multiplies 2nd top element with top element.
 * @stack: stack to perform operation on.
 * @line_n: line number of opcode.
 * Return: nothing.
 */
void mul(stack_t **stack, unsigned int line_n)
{
	stack_t *top = *stack;

	if (!top || !top->next)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}

	top->next->n *= top->n;
	pop(stack, line_n);
}
/**
 * exec_op - performs operation based on input.
 * @tokens: array containing tokenized opcode.
 * @stack: stack to perform operation on.
 * @line_number: line number of opcode.
 * Return: nothing.
 */
void exec_op(char *tokens[], stack_t **stack, unsigned int line_number)
{
	int i, length;
	instruction_t op_ar[] = {{"push", push}, {"pall", pall},
		{"pint", pint}, {"pop", pop}, {"swap", swap}, {"add", add},
		{"nop", nop}, {"sub", sub}, {"mul", mul}};

	length = sizeof(op_ar) / sizeof(op_ar[0]);

	value = tokens[1];

	for (i = 0; i < length; i++)
	{
		if (strcmp(tokens[0], op_ar[i].opcode) == 0)
		{
			op_ar[i].f(stack, line_number);
			break;
		}
	}

	if (i == length)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, tokens[0]);
		exit(EXIT_FAILURE);
	}
}
