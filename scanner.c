#include "main.h"

struct token_s eof_token = {
	.text_len = 0,
};


struct source_s src_file = {
	.buffer = NULL,
	.buffsize = 0,
	.curpos = -1,
};

/**
 * add_to_buf - adds a single char to the token buffer
 * @c: char to add
 */
void add_to_buf(char c)
{
	src_file.buffer[src_file.curpos++] = c;
	if (src_file.curpos >= src_file.buffsize)

{
	char *tmp = realloc(src_file.buffer, src_file.buffsize * 2);

	if (!tmp)
	{
		errno = ENOMEM;
		return;
	}

	src_file.buffer = tmp;
	src_file.buffsize *= 2;
}
}

/**
 * create_token - takes a string and converts it to struct
 * @str: string to convert
 * Return: a new struct base of the string
 */
struct token_s *create_token(char *str)
{
	struct token_s *tok = malloc(sizeof(struct token_s));
	char *nstr;

	if (!tok)
		return (NULL);

	memset(tok, 0, sizeof(struct token_s));
	tok->text_len = strlen(str);
	nstr = malloc(tok->text_len + 1);
	if (!nstr)
	{
		free(tok);
		return (NULL);
	}
	strcpy(nstr, str);
	tok->text = nstr;
	return (tok);
}

/**
 * free_token - frees the memory used by a token struct, and token test
 * @tok: token to free
 */
void free_token(struct token_s *tok)
{
	if (tok->text)
		free(tok->text);
	free(tok);
}


/**
 * tokenize - tokenize the source or command
 * @src: source struct
 * Return: struct
 */
struct token_s *tokenize(struct source_s *src)
{
	int  endloop = 0;
	char nc;
	struct token_s *tok;

	if (!src || !src->buffer || !src->buffsize)
	{
	    errno = ENODATA;
		return (&eof_token);
	}
	if (!src_file.buffer)
	{
	    src_file.buffsize = 1024;
		src_file.buffer = malloc(src_file.buffsize);
		if (!src_file.buffer)
		{
			errno = ENOMEM;
			return (&eof_token);
		}
	}

	src_file.curpos     = 0;
	src_file.buffer[0]       = '\0';

	nc = next_char(src);

	if (nc == ERRCHAR || nc == EOF)
	{
		return (&eof_token);
	}

	do {
		switch (nc)
		{
			case ' ':
			case '\t':
				if (src_file.curpos > 0)
				{
					endloop = 1;
				}
				break;
			case '\n':
				if (src_file.curpos > 0)
				{
					unget_char(src);
				}
				else
				{
					add_to_buf(nc);
				}
				endloop = 1;
				break;
			default:
				add_to_buf(nc);
				break;
		}
		if (endloop)
			break;
	} while ((nc = next_char(src)) != EOF);

	if (src_file.curpos == 0)
	{
		return (&eof_token);
	}
	if (src_file.curpos >= src_file.buffsize)
	{
		src_file.curpos--;
	}
	src_file.buffer[src_file.curpos] = '\0';

	tok = create_token(src_file.buffer);
	if (!tok)
	{
		fprintf(stderr, "error: failed to alloc buffer: %s\n", strerror(errno));
		return (&eof_token);
	}

	tok->src = src;
	return (tok);
}
