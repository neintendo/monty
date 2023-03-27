#include "monty.h"

/**
 * nop_opcode - doesn't do anything.
 * @stack: (ignored)
 * @op_val: (ignored)
 * @line_number: (ignored)
 */
void nop_opcode(stack_t **stack, int op_val, unsigned int line_number)
{
	(void)stack;
	(void)op_val;
	(void)line_number;
}
