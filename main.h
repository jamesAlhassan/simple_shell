#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>



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
void unget_char(struct source_s *src);
char next_char(struct source_s *src);
char peek_char(struct source_s *src);
void skip_white_spaces(struct source_s *src);
void add_to_buf(char c);
struct token_s *create_token(char *str);
void free_token(struct token_s *tok);
struct token_s *tokenize(struct source_s *src);

#endif
