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
	(void) line_n;
	if ((*stack) == NULL)
	{
		exit(EXIT_FAILURE);
	}
	if (*stack)
	{
		*stack = (*stack)->next;
	}
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
	if (!(*stack))
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
	}
	else
	{
		printf("%d\n", (*stack)->n);
	}
}

/**
 * exec_op - executes a program from an array of programs.
 * @tokens: array containing tokenized opcode segments.
 * @stack: the stack to perform operations on.
 * @line_number: the line number of opcode in source file.
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

void exec_op(char *tokens[], stack_t **stack, unsigned int line_number)
{
	int i, length;
	instruction_t op_ar[] = {{"push", push}, {"pall", pall}, {"pint", pint}, {"pop", pop}, {"swap", swap}};

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
