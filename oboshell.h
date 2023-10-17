#ifndef OBOSHELL_H
#define OBOSHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

typedef int boolean;
#define true 1
#define false 0

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

typedef struct
{
        const char *obo;
        int (*f)(char **args);
} builtinobo;


char *getline_obo(void);
int check_delim(const char *delim, char c);
char *strtok_obo(char *str, const char *delim);
int atoi_obo(char *str);
int strlen_obo(char *string);
int (*get_obo_func(char *s))(char **);
int exit_obo(char **args);
int env_obo(char **args);
int cd_obo(char **args);
int execute_obo(char **args);
char *handle_path(char *obo);
void interact_mode(void);
char **inputDefiner(char *text_cpy, ssize_t read_len);
int process_obo(char **args);
char *strcat_obo(char *dest, const char *src);

int strcmp_obo(const char *string1, const char *string2);

char *strcpy_obo(char *flat, char *source);
char *strdup_obo(char *s);
int strlen_obo(char *string);
char *strncat_obo(char *flat, char *source, int number);
char **tokenize_line(char *read);

char **tokenize(const char *input);
extern char **environ;

#endif
