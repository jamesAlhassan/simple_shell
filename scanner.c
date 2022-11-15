#include "main.h"

struct token_s eof_token = 
{
    .text_len = 0,
};


void add_to_buf(char c)
{
	char *tok_buf = NULL;
	int   tok_bufsize  = 0;
	int   tok_bufindex = -1;

	tok_buf[tok_bufindex++] = c;
	if(tok_bufindex >= tok_bufsize)
    {
        char *tmp = realloc(tok_buf, tok_bufsize*2);

        if(!tmp)
        {
            errno = ENOMEM;
            return;
        }

        tok_buf = tmp;
        tok_bufsize *= 2;
    }
}
