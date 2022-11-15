#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

#define EOF				(-1)
#define ERRCHAR			(0)
#define INIT_SRC_POS	(-2)

struct source_s
{
	char *buffer;
	long buffsize;
	long curpos;
};

struct token_s
{
	struct source_s *src;
	int text_len;
	char *text;
};

void print_prompt(void);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);

#endif
