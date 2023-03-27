#include "monty.h"
#include <stdio.h>
#include <string.h>
#include <ctype.h>

void FileRead(FILE *fin);
int operand_function(char *string);
void free_stack(stack_t **stack);

/**
 * main - the entry point to the monty file interpreter.
 * @argc: number of arguments.
 * @argv: the arguments.
 *
 * Return: 0 on success.
 */
int main(int argc, char *argv[])
{
	FILE *file;

	if (argc > 2 || argc == 1)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");

	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	FileRead(file);
	fclose(file);

	return (0);
}

/**
 * FileRead - reads a line from a file to process an opcode.
 * @fin: the monty file to be processed.
 */
void FileRead(FILE *fin)
{
	instruction_t opcodes[] = {
	    {"push", push_opcode},
	    {"pall", pall_opcode},
	    {"pint", pint_opcode},
	};

	int line = 0;
	int op_index = 0;
	char *opcode;
	char *buff;
	int operand_value;
	stack_t *stack = NULL;

	buff = malloc(sizeof(char *) * 500);

	while (fgets(buff, 500, fin) != NULL)
	{
		line++;
		operand_value = operand_function(buff);

		opcode = strtok(buff, "\n"
				      "\t"
				      " ");
		if (opcode != NULL)
		{
			while (opcodes[op_index].opcode != NULL)
			{
				if (strcmp(opcode, opcodes[op_index].opcode) == 0)
				{
					opcodes[op_index].f(&stack, operand_value, line);
					break;
				}
				op_index++;
				if (op_index > 2)
				{
					fprintf(stderr, "L%d: unknown instruction %s\n", line, opcode);
					exit(EXIT_FAILURE);
				}
			}
		}
		op_index = 0;
	}
	free(buff);
	free_stack(&stack);
}

/**
 * operand_function - extracts the string integer value after opcode to int.
 * @string: the string to extract the operand from.
 *
 * Return: returns the extracted integer.
 */
int operand_function(char *string)
{
	unsigned int value;
	int number_found = 0;
	char *token = strtok(string, " ");

	while (token != NULL)
	{
		if (isdigit(*token) || (*token == '-' && isdigit(*(token + 1))))
		{
			value = atoi(token);
			number_found = 1;
			break;
		}
		token = strtok(NULL, " ");
	}
	if (number_found == 0)
		return (-1);
	return (value);
}

void free_stack(stack_t **stack)
{
	stack_t *current, *next;
	current = *stack;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}

	*stack = NULL;
}
