#include "monty.h"

/**
 * monty_push - Pushes an integer onto the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the Monty bytecode file.
 * @value: The integer to be pushed.
 */
void monty_push(stack_t **stack, unsigned int line_number, int value)
{
    stack_t *new_node;

    new_node = malloc(sizeof(stack_t));
    if (!new_node)
    {
        dprintf(STDERR_FILENO, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;
    
    if (*stack)
        (*stack)->prev = new_node;
    
    *stack = new_node;
}

/**
 * monty_pall - Prints all values on the stack.
 * @stack: A pointer to the stack.
 * @line_number: The line number in the Monty bytecode file.
 */
void monty_pall(stack_t **stack, unsigned int line_number)
{
    stack_t *current = *stack;

    (void)line_number;

    while (current)
    {
        printf("%d\n", current->n);
        current = current->next;
    }
}
