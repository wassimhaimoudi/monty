#include "monty.h"

/**
 * nop - doesn't do anything
 * @top: the top of the stack
 * @line_number: the line number of the instruction
 */
void nop(stack_t **top, unsigned int line_number)
{
	(void)top;
	(void)line_number;
}

/**
 * swap - swaps top two elements of the stack
 * @top: the top of the stack
 * @line_number: the number line of the instruction
 *
 */
void swap(stack_t **top, unsigned int line_number)
{
	stack_t *top1, *top2;

	if (*top == NULL || (*top)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top1 = *top;
	top2 = top1->next;

	top1->next = top2->next;
	if (top2->next)
		top2->next->prev = top1;
	top2->prev = NULL;
	top2->next = top1;
	top1->prev = top2;

	(*top) = top2;
}
/**
 * add - add the two top elements of the stack_t doubly linked list
 * @top: the top of the linked list
 * @line_number: the line number of te instruction
 *
 * Return: void
 */
void add(stack_t **top, unsigned int line_number)
{
	int result;

	if (!(*top) || !((*top)->next))
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = (*top)->n + (*top)->next->n;
	pop(top, line_number);
	(*top)->n = result;
}
/**
 * sub - subtracts the top element from the second top element
 * @top: the top of the stack_t doubly linked list
 * @line_number: the line number of the instrux
 *
 * Return: void
 */
void sub(stack_t **top, unsigned int line_number)
{
	int result;

	if (!(*top) || !((*top)->next))
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = (*top)->n + (*top)->next->n;
	pop(top, line_number);
	(*top)->n = result;
}
/**
 * mul - multiplies the two top elements of the stack
 * @top: the top element of the stack_t doubly linked list
 * @line_number: the line number of the instrux
 *
 * Return: void
 */
void mul(stack_t **top, unsigned int line_number)
{
	int result;

	if (!(*top) || (!(*top)->next))
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = (*top)->n * (*top)->next->n;
	pop(top, line_number);
	(*top)->n = result;
}
