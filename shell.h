#ifndef SHELL_H
#define SHELL_H

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <time.h>
#include <stdbool.h>
# include <limits.h>
# ifndef BUFFER_SIZE
#  define BUFFER_SIZE	32
# endif

/* environment variables */
extern char **environ;
extern __sighandler_t signal(int __sig, __sighandler_t __handler);

/* handle built ins */
int checker(char **cmd, char *buf);
void prompt_user(void);
void handle_signal(int m);
char **tokenizer(char *line);
char *test_path(char **path, char *command);
char *append_path(char *path, char *command);
int handle_builtin(char **command, char *line);
void exit_cmd(char **command, char *line);

void print_env(void);

/* string handlers */
int _strcmp(char *s1, char *s2);
int _strlen(char *s);
int _strncmp(char *s1, char *s2, int n);
char *_strdup(char *s);
char *_strchr(char *s, char c);
char *_strjoin(char *s1, char *s2);
void execution(char *cp, char **cmd);
char *find_path(void);

/* helper function for efficient free */
void free_buffers(char **buf);

/**
 * struct builtin - built ins
 * @env: parameter
 * @exit: parameter
 */

struct builtin
{
	char *env;
	char *exit;
} builtin;


/**
 * struct info - information
 * @final_exit: parameter
 * @ln_count: parameter
 */
struct info
{
	int final_exit;
	int ln_count;
} info;


/**
 * struct flags - flags
 * @interactive: parameter
 */
struct flags
{
	bool interactive;
} flags;


/* to get line*/
int my_getline(int fd, char **line);
int _writeline(char **buff, char **line, int i);
void *_memmove(void *dst, const void *src);

/* string tokenizer */
char **_strtok(char *str, char *delim);
int checkers(char c, char *chars);

#endif /* SHELL_H */
