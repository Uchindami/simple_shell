#include "foundation.h"

/**
 * checkPath - Searches $PATH for the directory of the command.
 * @build: Input build.
 * Return: 1 if found, 0 if not.
 */
int checkPath(config *build)
{
	register int len;
	static char buffer[BUFSIZE];
	struct stat st;
	char *tok, *copy, *delim = ":", *tmp;
	int inLoop = false;

	if (checkEdgeCases(build))
		return (true);
	copy = _strdup(build->path);
	tok = _strtok(copy, delim);
	while (tok)
	{
		tmp = inLoop ? tok - 2 : tok;
		if (*tmp == 0 && stat(build->args[0], &st) == 0)
		{
			build->fullPath = build->args[0];
			free(copy);
			return (true);
		}
		len = _strlen(tok) + _strlen(build->args[0]) + 2;
		_strcat(buffer, tok);
		_strcat(buffer, "/");
		_strcat(buffer, build->args[0]);
		insertNullByte(buffer, len - 1);
		if (stat(buffer, &st) == 0)
		{
			free(copy);
			build->fullPath = buffer;
			return (true);
		}
		insertNullByte(buffer, 0);
		tok = _strtok(NULL, delim);
		inLoop = true;
	}
	build->fullPath = build->args[0];
	free(copy);
	return (false);
}

/**
 * checkEdgeCases - Helper function for checkPath to check edge cases.
 * @build: Input build.
 * Return: 1 if found, 0 if not.
 */
int checkEdgeCases(config *build)
{
	char *copy;
	struct stat st;

	copy = _strdup(build->path);
	if (!copy)
	{
		build->fullPath = build->args[0];
		free(copy);
		return (true);
	}
	if (*copy == ':' && stat(build->args[0], &st) == 0)
	{
		build->fullPath = build->args[0];
		free(copy);
		return (true);
	}
	free(copy);
	return (false);
}
