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
