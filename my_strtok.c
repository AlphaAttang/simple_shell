#include "shell.h"

/**
 * checkers - checks whether character is in string
 * @c: parameter
 * @chars: parameter
 *
 * Return: 0
 */

int checkers(char c, char *chars)
{
	int i = 0;

	for (; i < _strlen(chars); i++)
	{
		if (chars[i] == c)
			return (1);
	}
	return (0);
}

/**
 * _strtok - tokinizes string
 * @str: sting to tokkinize
 * @delim: delimeter
 *
 * Return: string
 */

char **_strtok(char *str, char *delim)
{
	char **toks;
	int len = _strlen(str), j = 0, k = 0;
	int delemiter = 0, i = 0;

	toks = (char **)malloc(len * sizeof(char));
	*toks = (char *)malloc(len * sizeof(char));

	for (; i < len; i++)
	{
		if (checkers(str[i], delim))
		{
			if (!delemiter)
			{
				(*(toks + k))[++j] = '\0';
				k++;
			}
			*(toks + k) = (char *)malloc(len * sizeof(char));
			delemiter = 1;
			j = 0;
		}

		else
		{
			(*(toks + k))[j++] = str[i];
			delemiter = 0;
		}
	}
	return (toks);
}

