#include "monty.h"

/**
 * swap_opcode - swaps the top two elements of the stack.
 * @stack: the top node.
 * @op_val: (ignored)
 * @line_number: the line number where the pop opcode is.
 */
void swap_opcode(stack_t **stack, int op_val, unsigned int line_number)
{
	int elements = 0;
	int n1, n2;

	stack_t *temp = (*stack);

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	while (temp != NULL)
	{
		elements++;
		temp = temp->next;
	}

	if (elements < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	n1 = (*stack)->next->n;
	n2 = (*stack)->n;

	(*stack)->n = n1;
	(*stack)->next->n = n2;

	(void)op_val;
}
