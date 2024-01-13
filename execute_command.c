#include "shell.h"

/**
 * execute_command - a function that executes commands
 * @command: command to be executed
 * @envp: the environmen
 *
 * Return: 0
 */

int execute_command(char **command, char *envp[])
{
	pid_t pid, wpid;
	int status;

	if (command[0] == NULL)
	{
		perror("Empty command");
			return (1);
	}
	if (_strcmp(command[0], "exit") == 0)
		exit_shell();
	else if (_strcmp(command[0], "cd") == 0)
		cd(command);
	else
	{
		pid = fork();
		if (pid == -1)
		{
			perror("fork");
			return (1);
		}
		else if (pid == 0)
		{
			if (execve(command[0], command, envp) == -1)
			{
				perror("Error:");
				_exit(EXIT_FAILURE);
			}
		}
		else
		{
			do
			{
				wpid = waitpid(pid, &status, WUNTRACED);
				(void)wpid;
			}
			while (!WIFEXITED(status) && !WIFSIGNALED(status));
		}
	}
	return (1);
}
