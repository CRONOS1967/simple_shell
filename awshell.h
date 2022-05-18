#ifndef AWSHELL_H
#define AWSHELL_H

#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>
#include <signal.h>
#include <fcntl.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <errno.h>

/* shortened variables */
#define STDERR STDERR_FILENO
#define STDOUT STDOUT_FILENO
#define STDIN STDIN_FILENO
/* end of shortened */

#define PATH "PATH"
#define BSIZE 512

/* extern call for env var */
extern char **environ;

/**
 * struct builtins - struct with type to find builtins and function to use
 * @name: string to compare
 * @function: printing function associated
 */

typedef struct builtins
{
	char *name;
	int (*function)();
} builtins_t;

/**
 * struct path_list - linked list with the path of executables
 * @str: string
 * @next: pointer
 */

typedef struct path_list
{
	char *str;
	struct path_list *next;
} p_list;

/*print helpers*/
void print_error(char *c_counter, char *argv0, char *shellav);
void print_error2(char *c_counter, char *argv0, char *shellav);
int _putchar(char c);
void _puts(char *str);

/* freeing memory */
void free_double(char **ptr);
void free_single(char *ptr);


/* string manipulation functions */
int _strcmp(char *s1, char *s2);
char *_strdup(const char *str);
char **split_str(char *str, char *delim);
char *_strchr(char *s, char c);
char *_strcat(char *dest, char *src);
int _strlen(char *s);
char *_memcpy(char *dest, char *src, unsigned int n);
int exec(char **argv, unsigned int counter, char *shellav);
char *get_env(char *str);
void ctrap(int signal);
char *_which(char *excname);
char *itos(unsigned int counter);
unsigned int _strspn(char *s, char *accept);
unsigned int _strcspn(char *s, char *accept);
char *_strtok(char *string, char *delim);
char *strtok_h(char *string, char *delim, char **sptr);
int _getline(char **lineptr, size_t *n, FILE *stream);
/*Built-in functions*/

int _env(char **ptr);
int exitshell(char **buff_split, char *buff, int error_code);
int _setenv(char **ptr);
int _unsetenv(char **ptr);
int _setenv(char **ptr);
int _help(char **ptr);
int get_builtins(char *buff, char **buff_split, int error_code);

/* list manipulation functions */
p_list *path_list(void);
void free_list(p_list *head);
p_list *add_list(p_list **head, const char *str);
size_t print_list(const p_list *h);
#endif /* AWSHELL */
