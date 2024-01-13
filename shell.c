#include "shell.h"

/**
 * main - main function
 *
 * Return: 0
 */

int main()
{
	char *input;
	char **tokens;

	while (1)
	{
		prompt();
		input = get_line();
		tokens = (char **)malloc(sizeof(char *) * MAX_TOKENS);
		if (input == NULL)
		{
			perror("can't read from stdin");
			exit(EXIT_FAILURE);
		}
		if (tokens == NULL)
		{
			perror("malloc failed");
			exit(EXIT_FAILURE);
		}
		tokenization(input, tokens);
		execute_command(tokens, NULL);
		
	}
	return (0);
}

