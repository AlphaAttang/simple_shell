#include "shell.h"

/**
* _writeline - writes line to buffer
* @buf: pointer to buffer
* @line: line to write
* @i: iterator
*
* Return: pointer to duplicate string
*/

int _writeline(char **buf, char **line, int i)
{
	*line = _strdup(*buf);

	if (*line == NULL)
		return (-1);

	*buf = _memmove(*buf, (_strchr(*buf, '\n') + 1));
	if (**buf == 0 && i == 0)
	{
		free(*buf);
		*buf = NULL;
		return (0);
	}
	return (1);
}

/**
* my_getline - gets line
* @fd: parameter
* @line: pointer to line
*
* Return: pointer to duplicate string
*/

int my_getline(int fd, char **line)
{
	static char *r[FOPEN_MAX];
	char buf[BUFFER_SIZE + 1];
	int i = 1;

	if (fd < 0 || !line || read(fd, buf, 0) < 0)
		return (-1);
	if (!r[fd])
	{
		r[fd] = malloc(sizeof(char));
		if (!r[fd])
			return (-1);
		r[fd][0] = '\0';
	}

	while (i && !_strchr(r[fd], '\n'))
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i < 0)
			return (-1);
		buf[i] = '\0';
		r[fd] = _strjoin(r[fd], buf);
		if (r[fd] == 0)
			return (-1);
	}
	return (_writeline(&r[fd], line, i));
}
