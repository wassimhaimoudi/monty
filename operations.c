#include "monty.h"

/**
 * push - pushes one element to the top of the stack doubly linked list
 * @top: the top of the stack
 * @line_number: the line number of the instruction
 * @value: the instruction containing the element to push
 *
 * Return: teh top of the stack
 */
int push(stack_t **top, unsigned int line_number, char *value)
{
	int num;
	stack_t *new_node = NULL;

	num = atoi(value);
	if (num == 0 && *value != '0')
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = (stack_t *)malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = num;
	new_node->prev = NULL;
	new_node->next = *top;
	if (*top)
		(*top)->prev = new_node;
	*top = new_node;
	return (num);
}
/**
 * pall - prints all the elements of the stack_t doubly linked list
 * @top: the top of the stack_t doubly linked list
 * @line_number: the line number of the instruction
 *
 * Return: void
 */
void pall(stack_t **top, unsigned int line_number)
{
	int counter = 0;
	stack_t *temp;

	(void)line_number;
	temp = *top;
	if ((*top))
	{
		while (temp)
		{
			printf("%d\n", temp->n);
			temp = temp->next;
			counter++;
		}
	}
}
/**
 * pop - removes an element from the
 * @top: the top of the stack_t doubly linked list
 * @line_number: the line number of the instruction
 *
 * Return: void
 */
void pop(stack_t **top, unsigned int line_number)
{
	if (!(*top))
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	(*top) = (*top)->next;
	free((*top)->prev);
	(*top)->prev = NULL;
}
/**
 * pint - prints the value at the stack.
 * @top: the top of the stack.
 * @line_number: the line number of the instruction
 *
 * Return: void
 */
void pint(stack_t **top, unsigned int line_number)
{
	int num;

	(void)line_number;
	if (!(*top))
	{
		fprintf(stderr, "L%d, can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	num = (*top)->n;
	printf("%d\n", num);
}
