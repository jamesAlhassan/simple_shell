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

	while (1)
	{
		print_prompt();
		read = getline(&lineptr, &n, stdin);

		struct source_s src;

		src.buffer = lineptr;
		src.buffsize = strlen(lineptr);
		src.curpos = INIT_SRC_POS;

		free(lineptr);
	}
	return (0);
}

