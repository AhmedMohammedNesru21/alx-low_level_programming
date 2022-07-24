#include "main.h"
#include <stdio.h>
#include <stdlib.h>

/**
 * number - function to calculate number of words
 * @str: string being passed to check for words
 *
 * Return: number of words
 */
int number(char *str)
{
	int a;
	int num = 0;

	for (a = 0; str[a] != '\0'; a++)
	{
		if (*str == ' ')
			str++;
		else
		{
			for (; str[a] != ' ' && str[a] != '\0'; a++)
				str++;
			num++;
		}
	}
	return (num);
}
/**
 * free_everything - frees the memory
 * @string: pointer values being passed for freeing
 * @i: counter
 */
void free_everything(char **string, int i)
{
	for (; i > 0;)
		free(string[--i]);
	free(string);
}

/**
 * strtow - function that splits string into words
 * @str: string being passed
 * Return: null if string is empty or null or function fails
 */
char **strtow(char *str, char delim)
{
	int i, j, k, h, c, len;
	char **words;
	if (str == NULL || str[0] == '\0')
		return (NULL);
	c = count_words(str, delim);
	if (c == 0)
		return (NULL);
	words = malloc(sizeof(char *) * (c + 1));
	if (words == NULL)
		return (NULL);
	i = 0; /* counts through entire string */
	j = 0; /* counts through each word in string */
	while (str[i] != '\0')
	{
		while (str[i] == delim && str[i] != '\0')
			i++;
		if (str[i] == '\0')
		{
			words[j] = NULL;
			return (words);
		}
		words[j] = malloc(sizeof(char) * _wrdlen(str + i, delim) + 1);
		if (words[j] == NULL)
		{
			for (k = j - 1; k >= 0; k--)
				free(words[k]);
			free(words);
			return (NULL);
		}
		len = _wrdlen(str + i, delim);
		for (h = 0; h < len && str[i] != '\0'; h++, i++)
			words[j][h] = str[i];
		words[j][h] = '\0';
		j++;
	}
	words[j] = NULL;
	return (words);
}
