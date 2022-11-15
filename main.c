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
	}
	free(lineptr);
	return (0);
}

