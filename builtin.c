#include "shell.h"
/**
 * exit_shell - a function to exit the shell
 *
 * Return: 0
 */

void exit_shell(void)
{
	exit(EXIT_SUCCESS);
}

/**
 * ls - a function that list files in a director
 *
 * Return: 0
 */

void ls(void)
{
	char *list[2];
	pid_t pid = fork();

	if (pid == 0)
	{
		list[0] = "ls";
		list[1] = NULL;
		execve("/bin/ls", list, NULL);
		perror("ls");
		exit(EXIT_FAILURE);
	}
	else if (pid < 0)
	{
		perror("fork");
	}
	else
	{
		waitpid(pid, NULL, 0);
	}
}

/**
 * cd - a function to change directory
 * @args: argument
 *
 * Return: 0
 */
void cd(char **args)
{
	char *previous_dir;
	char cwd[MAX_INPUT];

	if (_strcmp(args[0], "cd") == 0)
	{
		if (args[1] == NULL || _strcmp(args[1], "~") == 0)
		{
			chdir(getenv("HOME"));
		}
		else if (_strcmp(args[1], "-") == 0)
		{
			previous_dir = getenv("OLDPWD");
			if (previous_dir)
			{
				chdir(previous_dir);
			}
		}
		else
		{
			if (chdir(args[1]) == -1)
			{
				perror("cd");
			}
		}

		getcwd(cwd, sizeof(cwd));
		setenv("PWD", cwd, 1);
	}
}
