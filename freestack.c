#include "monty.h"
/**
 * freestack - frees memory allocated for the stack.
 * @head: head of stack whose memory should be freed.
 * Return: unnecessary as function returns void.
 */
void freestack(stack_t *head)
{
	stack_t *temp;

	while (head != NULL)
	{
		temp = head;
		head = head->next;
		free(temp);
	}
}
