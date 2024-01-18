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
	stack_t *newNode = malloc(sizeof(stack_t));

	if (newNode == NULL)
	{
		fprintf(stderr, "Error: malloc failed at line %d\n", line_number);
		exit(EXIT_FAILURE);
	}

	if (isdig(value) == 0)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
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
		printf("Stack is empty\n");
		return;
	}

	current = *stack;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
void pop(stack_t **stack, unsigned int line_n)
{
	stack_t *popped = *stack;
	if (!popped)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_n);
		freestack(*stack);
		exit(EXIT_FAILURE);
	}
	popped = *stack;
	if (popped->prev != NULL)
	{
		popped->prev->next = NULL;
		*stack = popped->prev;
	}
	else
		*stack = NULL;
	free(popped);
}
/**
 * exec_op - executes a program from an array of programs.
 * @tokens: array containing tokenized opcode segments.
 * @stack: the stack to perform operations on.
 * @line_number: the line number of opcode in source file.
 * Return: unnecessary as function returns void.
 */
void exec_op(char *tokens[], stack_t **stack, unsigned int line_number)
{
	int i, length;
	instruction_t op_ar[] = {{"push", push}, {"pall", pall}, {"pop", pop}};

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
