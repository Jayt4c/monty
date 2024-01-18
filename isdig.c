#include "monty.h"
/**
 * isdig - checks if argument is a digit
 * @s: the character to be checked
 * Return: 1 if c is digit and 0 otherwise
 */
int isdig(char *s)
{
	char *str = "";
	int i = 0;

	if (!s)
		return (0);
	str = s;

	if (str[i] == 45)
		i++;
	while (str[i])
	{
		if (!(str[i] >= 48 && str[i] <= 57))
			return (0);
		i++;
	}
	return (1);
}
