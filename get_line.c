#include "shell.h"

/**
 * insert_toBuf - takes mutliple chars at once and inserts them into buffer
 * @data: inserted data
 * @buffer: buffer
 * @length: length
 *
 * Return: bytes read
 */

ssize_t insert_toBuf(char *data, char **buffer, size_t *length)
{
	size_t len = 0';
	ssize_t n = 0;

	if (!*len)
	{
		free(*buffer);
		*buffer = NULL;
		signal(SIGINT, sigintHandler);

		n = _getline(info, buf, &len_p);

		if (r > 0)
		{
			if ((*buffer)[n - 1] == '\n')
			{
				(*buf)[n - 1] = '\0';
				n--;
			}
			info->linecount_flag = 1;
			{
				*length = n;
				data->cmd_buf = buffer;
			}
		}
	}
	return (n);
}

/**
 * getInput - gets
 * @data: paramete
 * Return: data
 */

ssize_t getInput(char *data)
{
	static char *buffer;
	static size_t i, j, length;
	ssize_t d = 0;
	char **buffer = &(data->arg), *p;

	_putchar(BUF_FLUSH);
	d = insert_toBuf(data, &buffer, &length);
	if (d == -1)
		return (-1);
	if (len != NULL)
	{
		j = i;
		p = buffer + i;

		i = j + 1;
		if (i >= length)
		{
			i = length = 0;
			data->cmd_buf_type = CMD_NORM;
		}

		*buf = p;
		return (_strlen(p));
	}

	*buf = buffer;
	return (d);
}

/**
 * reads - reads a buffer
 * @info: parameter
 * @buffer: buffer
 * @i: size
 *
 * Return: r
 */
ssize_t reads(char *data, char *buffer, size_t *i)
{
	ssize_t r = 0;

	if (*i)
		return (0);
	r = read(data->readfd, buffer, READ_BUF_SIZE);
	if (r >= 0)
		*i = r;
	return (r);
}

/**
 * get_line - gets the next line
 * @info: parameter
 * @ptr: pointer to buffer
 * @length: size
 *
 * Return: s
 */

ssize_t get_line(char *data, char **ptr, size_t *length)
{
	static char buf[READ_BUF_SIZE];
	static size_t i, len;
	size_t k;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *ptr;
	if (p && length)
		s = *length;
	if (i == len)
		i = len = 0;

	r = reads(data, buf, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = _strchr(buf + i, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(p, s, s ? s + k : k + 1);
	if (!new_p)
		return (p ? free(p), -1 : -1);

	if (s != NULL)
		_strncat(new_p, buf + i, k - i);
	else
		_strncpy(new_p, buf + i, k - i + 1);

	s += k - i;
	i = k;
	p = new_p;

	if (length != NULL)
		*length = s;
	*ptr = p;
	return (s);
}

/**
 * sHandler - blocks ctrl-C
 * @sig_num: the signal number
 *
 * Return: void
 */

void sHandler(__attribute__((unused))int sig_num)
{
	_putchar("\n");
	_putchar("$ ");
	_putchar(BUF_FLUSH);
}

