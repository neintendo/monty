#include "monty.h"
#include <stdio.h>

/**
 * pint_opcode - prints the value at the top of the stack.
 * @stack: the first node.
 * @op_val: (ignored)
 * @line_number: the line number where the pint opcode is.
 */
void pint_opcode(stack_t **stack, int op_val, unsigned int line_number)
{
	stack_t *temp = *stack;

	if (temp == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	fprintf(stdout, "%d\n", temp->n);

	(void)op_val;
}
