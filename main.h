#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

struct source_s
{
	char *buffer;
	long buffsize;
	long curpos;
};

void print_prompt(void);
int _strlen(char *s);
char *_strcpy(char *dest, char *src);

#endif
