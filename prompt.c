#include "shell.h"
/**
 * prompt - a function that provides a prompt
 *
 * Return: 0
 */

void prompt(void)
{
	if (isatty(STDIN_FILENO))
	{
		write(1, "$ ", 2);
		fflush(stdout);
	}
}
