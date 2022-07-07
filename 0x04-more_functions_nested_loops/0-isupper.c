#include "main.h"

/**
 * _isupper - function that checks for uppercase character.
 * @c: input value to check
 * Return: int.
 */

int _isupper(int c)
{
	if (c >= 65 && c <=90)
	{
		return (1);
	}
	else
		return (0);
}
