#include "monty.h"

/**
 * push_opcode - pushes an element to the stack.
 * @stack: pointer to the top node of the stack.
 * @op_val: the value to push to the stack.
 * @line_number: current line number of the opcode being processed.
 */
void push_opcode(stack_t **stack, int op_val, unsigned int line_number)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		free(new_node);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	if (op_val == -1)
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	new_node->n = op_val;
	new_node->next = *stack;

	if ((*stack) != NULL)
		(*stack)->prev = new_node;

	new_node->prev = NULL;
	*stack = new_node;
}
