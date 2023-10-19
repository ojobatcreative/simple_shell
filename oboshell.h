#ifndef DSHELL_H
#define DSHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
#include <signal.h>

#define MAX_LINE 256
#define PATH_MAX_LENGTH 1024
#define MAX_LEN 1024
#define BUFF_SIZE 1024
/**
 * struct obo - Struct obo
 *
 * @obo: The command
 * @f: The function associated
 */

typedef struct obo
{
	char *obo;
	int (*f)(char **args);
} builtinobo;

extern char **environ;
int (*get_obo_func(char *s))(char **);
int process_obo(char **args);
int process_mode(char **args, char *read);
int execute_obo(char **args);
char *handle_path(char *cmd);


int exit_obo(char **args);
int env_obo(char **args);
int cd_obo(char **args);
char *strcat_obo(char *dest, const char *src);
int strcmp_obo(char *strg1, char *strg2);
int strlen_obo(char *strg);

char *strncat_obo(char *flat, char *source, int number);
char *strdup_obo(char *s);
char *strcpy_obo(char *flat, char *source);


void process_file(char *file);
void interact_mode(void);
char **tokenize_line(char *input, ssize_t read_line);
int atoi_obo(char *str);
int execute_mode(char **args, char *read);
void signal_handle(int sig);
void handle_multiString(char **args, char *argv);

#endif
