#include "foundation.h"

/**
 * _strlen - returns the length of a str
 * @s: str s
 * Return: length of str
 */
int _strlen(char *s)
{
	char *p = s;

	while (*s)
		s++;
	return (s - p);
}

/**
 * _strcat - concatenates two strs
 * @dest: copy destination
 * @src: copy source
 * Return: concatenated str
 */
char *_strcat(char *dest, char *src)
{
	char *ptr = dest + _strlen(dest);

	while (*src)
		*ptr++ = *src++;
	*ptr = 0;
	return (dest);
}

/**
 * _strcmp - compares two strs
 * @s1: str 1
 * @s2: str 2
 * Return: 1 if true, 0 if false
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1)
	{
		if (*s1 != *s2)
			break;
		s1++;
		s2++;
	}

	return (*(unsigned char *)s1 - *(unsigned char *)s2);
}

/**
 * _strdup - returns a pointer to a newly allocated space in memory,
 * which contains a copy of the str given as a parameter.
 * @str: str to be copied
 * Return: copied str
 */
char *_strdup(char *str)
{
	int i, len;
	char *copy;

	if (!str)
		return (NULL);
	len = _strlen(str);
	copy = malloc(sizeof(char) * len + 1);
	if (!copy)
	{
		perror("Malloc failed\n");
		exit(errno);
	}
	for (i = 0; i < len; i++)
		copy[i] = str[i];
	copy[i] = 0;
	return (copy);
}

/**
 * *_strcpy - copies the str pointed to by src,
 * including the terminating null byte
 * @dest: copied str
 * @src: str to be copied
 * Return: pointer to new copied str
 */
char *_strcpy(char *dest, char *src)
{
	char *ptr = dest;

	while (*src)
		*dest++ = *src++;
	*dest = 0;
	return (ptr);
}
