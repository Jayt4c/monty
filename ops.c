#include "monty.h"
char *value = "";
/**
 * push - adds a new value to a stack.
 * @stack: pointer to pointer to the stack.
 * @line_number: the line number of the opcode currently being executed.
 * Return: unnecessary as function returns void.
 */
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *newNode;

	if (isdig(value) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		freestack(*stack);
		exit(EXIT_FAILURE);
	}

	newNode = malloc(sizeof(stack_t));

	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	newNode->n = atoi(value);
	newNode->prev = NULL;
	newNode->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = newNode;

	*stack = newNode;
}
/**
 * pall - prints all int data in the stack.
 * @stack: pointer to pointer to the stack.
 * @line_number: the line number of the opcode currently being executed.
 * Return: unnecessary as function returns void.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;
	(void)line_number;
	if (*stack == NULL)
	{
		return;
	}

	current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
 * pop - removes topmost value from stack.
 * @stack: pointer to pointer to the stack.
 * @line_n: line number of opcode.
 * Return: unnecessary as function returns void.
 */
void pop(stack_t **stack, unsigned int line_n)
{
	stack_t *popped = *stack;

	if (!popped)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_n);
		exit(EXIT_FAILURE);
	}

	*stack = popped->next;
	free(popped);
}
/**
 * pint - prints all ints in stack.
 * @stack: stack to perform operations on.
 * @line_number: line number of opcode in source file.
 * Return: unnecessary as function returns void.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *top = *stack;

	if (!top)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", top->n);
}
/**
 * swap - swaps top and 2nd top elemenet.
 * @stack: the stack to perform operations on.
 * @line_n: the line number of opcode in source file.
 * Return: unnecessary as function returns void.
 */
void swap(stack_t **stack, unsigned int line_n)
{
	stack_t *top = *stack;
	int temp_value = 0;

	if (!top || !top->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_n);
		exit(EXIT_FAILURE);
	}
	temp_value = top->n;
	top->n = top->next->n;
	top->next->n = temp_value;
}
