#include "main.h"

int parse_and_execute(struct source_s *src)
{
	skip_white_spaces(src);
	struct token_s *tok = tokenize(src);

	if (tok == &eof_token)
		return (0);
	while (tok && tok != &eof_token)
	{
		struct node_s *cmd = parse_simple_command(tok);

		if (!cmd)
			break;

		do_simple_command(cmd);
		tok = tokenize(src);
	}

	return (1);
}
