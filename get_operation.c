#include "monty.h"

/**
 * get_op_func - function entry point
 * @s: a pointer to the string containing the operator
 *
 * Return: a pointer to the function that corresponds
 * to operator given as parameter.
 */
void (*get_op_func(char *s))(stack_t **, unsigned int)
{
	instruction_t op[] = {{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"nop", nop},
		{"swap", swap},
		{NULL, NULL}};
	int i;

	i = 0;
	while (i < 5)
	{
		if (strncmp(s, op[i].opcode, 3) == 0)
		{
			return (op[i].f);
		}
		i++;
	}
	return (NULL);
}
