#include "monty.h"
/**
 * rotl - rotates the stack to the top
 * @top: the top of the stack
 * @line_number: the line number of the instruction
 *
 * Return: Void
 */
void rotl(stack_t **top, unsigned int line_number)
{
	stack_t *temp1 = NULL;
	stack_t *temp2 = NULL;
	(void)line_number;

	if (*top == NULL)
		return;

	if ((*top)->next == NULL)
		return;

	temp1 = (*top)->next;
	temp2 = *top;
	for (; temp2->next != NULL; temp2 = temp2->next)
	{}
	temp1->prev = NULL;
	temp2->next = *top;
	(*top)->next = NULL;
	(*top)->prev = temp2;
	*top = temp1;
}
/**
 * rotr - reverse the stack
 * @top: head of the linked list
 * @cline: line number of the instruction
 *
 * Return: Void
 */
void rotr(stack_t **top, unsigned int cline)
{
	stack_t *temp = NULL;
	(void)line_number;

	if (*top == NULL)
		return;

	if ((*top)->next == NULL)
		return;

	temp = *top;

	for (; temp->next != NULL; temp = temp->next)
	;

	temp->prev->next = NULL;
	temp->next = *top;
	temp->prev = NULL;
	(*top)->prev = temp;
	*top = temp;
}
/**
 * mod - calculates the rest of the division between the second element
 *	of the the stack and the first elementof the stack
 * @top: the top of the stack_t doubly linked list
 * @line_number: the line number of te instruction
 *
 * Return: void
 */
void mod(stack_t **top, unsigned int line_number)
{
	int result;

	if (!(*top) || !((*top)->next))
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n");
		exit(EXIT_FAILURE);
	}
	if ((*top)->n == 0)
	{
		fprintf(stderr, "L%u: divisionn by 0\n", line_number);
		exit(EXIT_FAILURE);
	}
	result = (*top)->next->n % (*top)->n;
	pop(top, line_number);
	(*top)->n = result;
}
