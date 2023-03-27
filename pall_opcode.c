#include "monty.h"
#include <stdio.h>

/**
 * pall_opcode - prints all values on a stack.
 * @stack: the top node.
 * @op_val: (ignored)
 * @line_number: (ignored)
*/
void pall_opcode(stack_t **stack, int op_val, unsigned int line_number)
{
	stack_t *temp = *stack;

	while (temp != NULL)
	{
		fprintf(stdout, "%d\n", temp->n);
		temp = temp->next;
	}

	(void) line_number;
	(void) op_val;
}
