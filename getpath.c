#include "simple_shell.h"

/**
 * getpath - accepts PATH string, splits it to tokens, then concats
 * with "/" & cmd
 *@command: command passed from getline in main
 *
 * Return: new_path for use in cmd_read
 */
char *getpath(char *command)
{
	char *path = mystrdup(mygetenv("PATH"));
	int ab = 0, xy = 0;
	char *path_tokens = strtok(path, ":");
	char *path_array[100];
	char *s2 = command;
	char *new_path = NULL;
	struct stat buf;

	new_path = malloc(sizeof(char) * 100);
	if (mygetenv("PATH")[0] == ':')
		if (stat(command, &buf) == 0)
			return (mystrdup(command));
	while (path_tokens != NULL)
	{
		path_array[ab++] = path_tokens;
		path_tokens = strtok(NULL, ":");
	}
	path_array[ab] = NULL;
	for (xy = 0; path_array[xy]; xy++)
	{
		mystrcpy(new_path, path_array[xy]);
		mystrcat(new_path, "/");
		mystrcat(new_path, s2);
		mystrcat(new_path, "\0");

		if (stat(new_path, &buf) == 0)
		{
			free(path);
			return (new_path);
		}
		else
			new_path[0] = 0;
	}
	free(path);
	free(new_path);

/* This is for after PATH checked and cmd is there locally */
	if (stat(command, &buf) == 0)
		return (mystrdup(command));
	return (NULL);
}
