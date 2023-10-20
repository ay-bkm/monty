#include "monty.h"

/**
 * monty_push - pushes an element to the stack
 * @stack: double pointer to the top of the stack
 * @line_number: value of the new element
 * Return: nothing
 */
void monty_push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = line_number;
	new->prev = NULL;
	new->next = *stack;
	if (*stack != NULL)
		(*stack)->prev = new;
	*stack = new;
}

/**
 * monty_pall - prints all values on the stack starting from top of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number
 * Return: nothing
 */
void monty_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current;

	(void) line_number;

	if (*stack == NULL)
		return;

	current = *stack;
	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
/**
 * monty_pint - prints the value at the top of the stack
 * @stack: double pointer to the top of the stack
 * @line_number: line number
 * Return: nothing
 */
void monty_pint(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
/**
 * main - Entry point
 * Return: void
 */

int main(void)
{
	stack_t *stack = NULL;

	monty_push(&stack, 1);
	monty_push(&stack, 2);
	monty_push(&stack, 3);

	monty_pall(&stack, 0);

	monty_pint(&stack, 0);

	return (EXIT_SUCCESS);
}
