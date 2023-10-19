#include "monty.h"

stack_t *top = NULL;

/**
 * main - main entry point
 * @ac: the number of command line arguments
 * @av: the array of the command line arguments
 *
 * Return: Always 0
 */
int main(int ac, char **av)
{
#include "init"

	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(av[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file <%s>\n", av[1]);
		exit(EXIT_FAILURE);
	}
	line_number = 0;
	while (fgets(line, sizeof(line), file))
	{
		line_number++;
		opcode = strtok(line, "\t\n\r");
		/* printf("%s\n", opcode); */
		if (opcode == NULL)
			continue;
		validInst_len = sizeof(validInst) / sizeof(validInst[0]);
		valid = 0;
		for (i = 0; i < validInst_len; i++)
		{
			if (!(strncmp(opcode, validInst[i], 3)))
			{
				valid = 1;
				break;
			}
		}
		if (valid)
		{
			/* continue with getting op functions and executing instructions here */
			if (strncmp(opcode, "push", 4) == 0)
				push(&top, (unsigned int)line_number, revstr(opcode));
			else
			{
				get_op_func(opcode)(&top, (unsigned int)line_number);
			}
		}
		else
		{
			fprintf(stderr, "L%d: unknown instruction %s\n", line_number, opcode);
			fclose(file);
			exit(EXIT_FAILURE);
		}
	}
	free_stack(&top);
	fclose(file);
	return (0);
}
