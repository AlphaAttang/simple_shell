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
	char **buf = &(data->arg), *p;

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
 * @data: parameter
 * @buffer: buffer
 * @i: size
 *
 * Return: d
 */

ssize_t reads(char *data, char *buffer, size_t *i)
{
	ssize_t d = 0;

	if (*i)
		return (0);
	data = read(data->readfd, buffer, READ_BUF_SIZE);
	if (d >= 0)
		*i = d;
	return (d);
}

/**
 * get_line - gets the next line
 * @data: parameter
 * @pointer: address of pointer to buffer, preallocated or NULL
 * @length: size of preallocated ptr buffer if not NULL
 *
 * Return: s
 */

ssize_t get_line(char *data, char **pointer, size_t *length)
{
	static char buffer[READ_BUF_SIZE];
	static size_t i, len;
	size_t k;
	ssize_t r = 0, s = 0;
	char *p = NULL, *new_p = NULL, *c;

	p = *pointer;
	if (p && length)
		s = *length;
	if (i == len)
		i = len = 0;

	r = read_buf(info, buf, &len);
	if (r == -1 || (r == 0 && len == 0))
		return (-1);

	c = _strchr(buf + i, '\n');
	k = c ? 1 + (unsigned int)(c - buf) : len;
	new_p = _realloc(p, s, s ? s + k : k + 1);
	if (!new_p)
		return (p ? free(p), -1 : -1);

	if (s)
		_strncat(new_p, buf + i, k - i);
	else
		_strncpy(new_p, buf + i, k - i + 1);

	s += k - i;
	i = k;
	p = new_p;

	if (length)
		*length = s;
	*pointer = p;
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

