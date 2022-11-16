#include "main.h"

/**
 * main - entry point of program
 * Return: 0
 */
int main(void)
{
	 char *lineptr;
	 size_t n;
	 int read;
struct source_s src;

	while (1)
	{
		print_prompt();
		read = getline(&lineptr, &n, stdin);

		src.buffer = lineptr;
		src.buffsize = strlen(lineptr);
		src.curpos = INIT_SRC_POS;
		parse_and_execute(&src);
	}
	free(lineptr);
	return (0);
}

