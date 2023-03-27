#include "monty.h"

/**
 * div_opcode - divides the second top element of the stack by the
 *	        top element of the stack.
 * @stack: the top node.
 * @op_val: (ignored)
 * @line_number: the line number where the div opcode is.
 */
void div_opcode(stack_t **stack, int op_val, unsigned int line_number)
{
	int a1, a2, result;
	int elements = 0;
	stack_t *to_pop = *stack, *temp = *stack;

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (temp != NULL)
	{
		elements++;
		temp = temp->next;
	}
	if (elements < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	a1 = (*stack)->next->n;
	a2 = (*stack)->n;
	result = a1 / a2;
	(*stack)->next->n = result;

	if ((*stack)->next != NULL)
	{
		(*stack) = (*stack)->next;
		(*stack)->prev = NULL;
	}
	else
		(*stack) = NULL;

	free(to_pop);

	(void)op_val;
}
