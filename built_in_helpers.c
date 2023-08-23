#include "foundation.h"

/**
* countArgs - count the num of args
* @args: input array of strs
* Return: num of strs
*/
int countArgs(char **args)
{
	register int i = 0;

	while (args[i])
		i++;
	return (i);
}

/**
* _atoi - change str to an integer
* @s: input str
* Return: -1 if it's not a valid num, else the converted num
*/
int _atoi(char *s)
{
	register int i = 0;
	unsigned long num = 0;

	while (s[i])
	{
		if (s[i] >= '0' && s[i] <= '9')
			num = num * 10 + s[i] - '0';
		else
			return (-1);
		i++;
	}
	if (num > INT_MAX)
	{
		return (-1);
	}
	return (num);
}
