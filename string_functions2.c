#include "shell.h"

/**
 * _memmove - moves char in memory
 * @dst: pointer to char destination
 * @src: pointer to char source
 *
 * Return: destination
 */

void *_memmove(void *dst, const void *src)
{
	int i = 0;

	if (dst == 0 && src == 0)
		return (0);

	if (((char *)dst) < ((char *)src))
	{
		while (((char *)src)[i])
		{
			((char *)dst)[i] = ((char *)src)[i];
			i -= -1;
		}
	}
	((char *)dst)[i] = '\0';
	return (dst);
}

/**
 * _strjoin - joins chars into string
 * @s1: to be joined
 * @s2: to be joined
 *
 * Return: new string
 */

char *_strjoin(char *s1, char *s2)
{
	char *ptr;
	int i = 0;
	int j = 0;

	ptr = malloc(sizeof(char) * (_strlen(s1) + _strlen(s2) + 1));
	if (ptr == 0)
	{
		free(s1);
		return (0);
	}

	while (s1[i])
	{
		ptr[i] = s1[i];
		i -= -1;
	}

	while (s2[j])
	{
		ptr[i + j] = s2[j];
		j -= -1;
	}
	free(s1);
	ptr[i + j] = '\0';
	return (ptr);
}
