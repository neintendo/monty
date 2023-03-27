#ifndef MONTY_H
#define MONTY_H

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include <stddef.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, int op_val, unsigned int line_number);
} instruction_t;

void push_opcode(stack_t **stack, int op_val, unsigned int line_number);
void pall_opcode(stack_t **stack, int op_val, unsigned int line_number);
void pint_opcode(stack_t **stack, int op_val, unsigned int line_number);
void pop_opcode(stack_t **stack, int op_val, unsigned int line_number);
void swap_opcode(stack_t **stack, int op_val, unsigned int line_number);
void add_opcode(stack_t **stack, int op_val, unsigned int line_number);
void nop_opcode(stack_t **stack, int op_val, unsigned int line_number);
void sub_opcode(stack_t **stack, int op_val, unsigned int line_number);
void div_opcode(stack_t **stack, int op_val, unsigned int line_number);
void mul_opcode(stack_t **stack, int op_val, unsigned int line_number);
void mod_opcode(stack_t **stack, int op_val, unsigned int line_number);

#endif
