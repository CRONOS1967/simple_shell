#ifndef _MAIN
#define _MAIN

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <sys/wait.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>
#include <signal.h>
#include <limits.h>

char *execute_line(void);
char **to_args(char *cmdstr);
char *getenv(const char *name);
char *locate(const char *name);
char *join_paths(const char sep, const char *path1, const char *path2);
int file_exists(const char *filepaths);
char *strdup(const char *str);

/* env 
int envFunc(config *build);
int setenvFunc(config *build);
int unsetenvFunc(config *build);
int _isalpha(int c);
* built_ins *
_Bool findBuiltIns(config *build);
*/

#endif
