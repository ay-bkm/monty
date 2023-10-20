#include "monty.h"
/**
 * free_stack - frees the stack
 * @stack: pointer
 */
void free_stack(stack_t *stack)
{
	stack_t *current;

	while (stack != NULL)
	{
		current = stack;
		stack = stack->next;
		free(current);
	}
}
