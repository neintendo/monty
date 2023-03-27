#include "monty.h"

/**
 * add_opcode - adds the top two elements of the stack.
 * @stack: the top node.
 * @op_val: (ignored)
 * @line_number: the line number where the add opcode is.
 */
void add_opcode(stack_t **stack, int op_val, unsigned int line_number)
{
	int a1, a2, sum;
	int elements = 0;
	stack_t *to_pop = *stack;
	stack_t *temp = *stack;

	if ((*stack) == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (temp != NULL)
	{
		elements++;
		temp = temp->next;
	}
	if (elements < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	a1 = (*stack)->next->n;
	a2 = (*stack)->n;
	sum = a1 + a2;

	(*stack)->next->n = sum;

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
