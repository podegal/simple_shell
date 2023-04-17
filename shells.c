#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>
#include <unistd.h>

/* Declare the environ variable */
extern char **environ;

#define BUFFER_SIZE 1024

/**
* read_line - gets input
*
* Return: string of characters inputed
*/
char *read_line()
{
int bufsize = BUFFER_SIZE;
int position = 0;
char *buffer = (char *) malloc(sizeof(char) * bufsize);
int c;
if (!buffer)
{
fprintf(stderr, "allocation error\n");
exit(EXIT_FAILURE);
}
while (1)
{
c = getchar();
if (c == EOF || c == '\n')
{
buffer[position] = '\0';
return (buffer);
}
else
{
buffer[position] = c;
}
position++;
if (position >= bufsize)
{
bufsize += BUFFER_SIZE;
buffer = (char *) realloc (buffer, bufsize);
if (!buffer)
{
fprintf(stderr, "allocation error\n");
exit(EXIT_FAILURE);
}
}
}
}
/**
* split_line - the function name
* @line: parameter of type char *.
* Return: char **.
*/
char **split_line(char *line)
{
	int bufsize = 64, position = 0;
	char **tokens = (char **) malloc(bufsize *sizeof(char *));
	char *token;

	if (!tokens)
	{
		fprintf(stderr, "allocation error\n");
		exit(EXIT_FAILURE);
	}
	token = strtok(line, " \t\n\r\a");
	while (token != NULL)
	{
		tokens[position] = token;
		position++;
		if (position >= bufsize)
		{
			bufsize += 64;
			tokens = (char **) realloc (tokens, bufsize *sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "allocation error\n");
				exit(EXIT_FAILURE);
			}
		}
		token = strtok(NULL, " \t\n\r\a");
	}
	tokens[position] = NULL;
	return (tokens);
}
/**
* main - The entry point of the program
*
* Return: 0 (success)
*/
int main(void)
{
	char *line;
	char **argv;
	int status;

	pid_t pid;

	while (1)
	{
		printf("$ ");
		line = read_line();
		argv = split_line(line);
		if (argv[0] == NULL)
		{
			free(line);
			free(argv);
			continue;
		}
		if (strcmp(argv[0], "exit") == 0)
		{
			free(line);
			free(argv);
			exit(EXIT_SUCCESS);
		}
/* Add env command */
		if (strcmp(argv[0], "env") == 0)
		{
			char **env = environ;

			while (*env)
			{
				printf("%s\n", *env);
				env++;
			}
			free(line);
			free(argv);
			continue;
		}
		pid = fork();
		if (pid == 0)
		{
			char *path = getenv("PATH");
			char *path_copy = strdup(path);
			char *dir = strtok(path_copy, ":");

			while (dir != NULL)
			{
				char *cmd = (char *) malloc(strlen(dir) + strlen(argv[0]) + 2);

				sprintf(cmd, "%s/%s", dir, argv[0]);
				execve(cmd, argv, NULL);
				free(cmd);
				dir = strtok(NULL, ":");
			}
			fprintf(stderr, "command not found: %s\n", argv[0]);
			free(path_copy);
			exit(EXIT_FAILURE);
		}
		else if (pid < 0)
		{
			perror("error");
		}
		else
		{
			waitpid(pid, &status, 0);
		}
		free(line);
		free(argv);
	}
	return (0);
}
