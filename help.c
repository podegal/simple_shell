#include "simple_shell.h"

/**
 **mystrcat(char *dest, char *src)- a custom function that concatenates two strings.
 *@dest: Char input
 *@src: Char input
 *
 * Return: 0 Always.
 */

char *mystrcat(char *dest, char *src)
{
	int xy = 0;

	int len = mystrlen(dest);

	while (src[xy] != '\0')
	{
		dest[len] = src[xy];
		len++;
		xy++;
	}
	dest[len] = '\0';
	return (dest);
}

/**
 * mystrcmp - custom function to compare two strings
 * @str1: first string
 * @str2: second string to compare to first string
 *
 * Return: <0 if str1 is less than str2, 0 for equal, >0 if str1 is greater than str2
 */
int mystrcmp(char *str1, char *str2)
{
	while (*str1 == *str2)
	{
	if (*str1 == '\0')
	{
	return (0);
	}
	str1++;
	str2++;
	}
	return (*str1 - *str2);
}

/**
 * char *mystrcpy- Copies a string
 *@dest: The new, coppied string
 *@src: The original string to copy
 *
 * Return: Always 0.
 */
char *mystrcpy(char *dest, char *src)
{
	int len; 
	int ab;

	len = mystrlen(src);

	for (ab = 0; ab < len; ab++)
	{
		dest[ab] = src[ab];
	}
	dest[ab] = '\0';

	return (dest);
}

/**
 * mystrlen(char *s)- a function that returns the length of a string.
 *@s: a character
 *
 * Return: Always 0.
 */

int mystrlen(char *s)
{
	int ab = 0;

	while (s[ab] != '\0')
	{
		ab++;
		}
	return (ab);
}

/**
 * *mystrdup - copies the input string
 * @string: input string
 *
 * Return: *ptr to the copied string or  NULL (if Error)
 */
char *mystrdup(char *string)
{
	char *duplicate;
	unsigned int ab = 0, len = 0;

	if (string == NULL)
		return (NULL);

	while (string[len])
		len++;

	duplicate = malloc(sizeof(char) * (len + 1));

	if (duplicate == NULL)
		return (NULL);

	while ((duplicate[ab] = string[ab]) != '\0')
		ab++;

	return (duplicate);
}
