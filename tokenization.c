#include "shell.h"

/**
 * tokenization - a function that parses user input
 * @input: user inputs
 * @tokens: parsing tokens
 *
 * Return: tokens
 */

void tokenization(char *input, char **tokens)
{
	int i = 0;
	char *token;

	token = strtok(input, " \t\n");

	while (token != NULL && i < MAX_TOKENS - 1)
	{
		tokens[i++] = _strdup(token);
		token = strtok(NULL, " \t\n");
	}
	tokens[i] = NULL;
}

