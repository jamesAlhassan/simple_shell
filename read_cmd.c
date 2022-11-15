#include "main.h"

/**
 * read_cmd - read user input in 1024-byte count and store in a buffer
 * Return: a malloced string
 */
char *read_cmd(void)
{
	char buf[1024];
	char *ptr = NULL;
	char ptrlen = 0;

	while (fgets(buf, 1024, stdin))
	{
		int buflen = strlen(buf);

		if (!ptr)
			ptr = malloc(buflen + 1);
		else
		{
			char *ptr2 = realloc(ptr, ptrlen + buflen + 1);

			if (ptr2)
				ptr = ptr2;
			else
			{
				free(ptr);
				ptr = NULL;
			}
		}
		if (!ptr)
		{
			fprintf(stderr, "error: failed to alloc buffer: %s\n", strerror(errno));
			return (NULL);
		}
		strcpy(ptr + ptrlen, buf);

		ptrlen += buflen;
	}
	return (ptr);
}
