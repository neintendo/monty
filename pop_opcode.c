#include "monty.h"
#include <stdio.h>

/**
 * pop_opcode - pops the element at the top of the stack.
 * @stack: the top node.
 * @op_val: (ignored)
 * @line_number: the line number where the pop opcode is.
 */
void pop_opcode(stack_t **stack, int op_val, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (((*stack)) == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->next != NULL)
	{
		(*stack) = (*stack)->next;
		(*stack)->prev = NULL;
	}
	else
		(*stack) = NULL;

	free (temp);
	
	(void)op_val;
}
