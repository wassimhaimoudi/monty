#include "monty.h"

/**
 * revstr - reverses a string
 * @s: the string to be reversed
 *
 * Return: a pointer to the reversed string.
 */
char *revstr(char *s)
{
	int i, s_len;
	char temp;

	s_len = strlen(s);
	for (i = 0; i < s_len / 2; i++)
	{
		temp = s[i];
		s[i] = s[s_len - i - 1];
		s[s_len - i - 1] = temp;
	}
	return (s);
}
/**
 * free_stack - frees a stack list
 * @top: The top of the linked list
 *
 * Return: Void
 */
void free_stack(stack_t **top)
{
	stack_t *temp;

	while ((*top))
	{
		temp = (*top)->next;
		free((*top));
		(*top) = temp;
	}
}
