#include <stdlib.h>
#include <string.h>
#include "substring.h"

/**
 * is_valid_substring - Check if a substring starting at index 'start'
 *                      is a valid concatenation of all words.
 * @s: The string to scan.
 * @start: The starting index of the candidate substring.
 * @words: Array of words.
 * @nb_words: Number of words.
 * @word_len: Length of each word.
 *
 * Return: 1 if the substring is a valid concatenation, 0 otherwise.
 */
int is_valid_substring(char const *s, int start, char const **words,
						int nb_words, int word_len)
{
	int j, k;
	int found;
	int *used;

	/* Allocate an array to keep track of used words */
	used = malloc(nb_words * sizeof(int));
	if (used == NULL)
		return (0);
	for (k = 0; k < nb_words; k++)
		used[k] = 0;
	/* Loop through each segment in the candidate substring */
	for (j = 0; j < nb_words; j++)
	{
		int sub_start = start + j * word_len;

		found = 0;
		/* Compare the segment with each word not used yet */
		for (k = 0; k < nb_words; k++)
		{
			/* Check if the word is not used, the characters match and */
			/* the word ends exactly after word_len characters */
			if (!used[k] && strncmp(s + sub_start, words[k], word_len) == 0 &&
			    words[k][word_len] == '\0')
			{
				used[k] = 1;
				found = 1;
				break;
			}
		}
		/* If no matching word is found, free memory and return 0 */
		if (!found)
		{
			free(used);
			return (0);
		}
	}
	free(used);
	return (1);
}

/**
 * find_substring - Finds all starting indices of substrings in 's' that
 *                  are a concatenation of each word in 'words' exactly once.
 * @s: The string to scan.
 * @words: The array of words.
 * @nb_words: The number of words.
 * @n: Pointer where the number of valid indices found will be stored.
 *
 * Return: A dynamically allocated array of indices. If no solution is found,
 *         NULL may be returned.
 */
int *find_substring(char const *s, char const **words, int nb_words, int *n)
{
	int s_len, word_len, total_len;
	int i, count = 0;
	int *indices;

	/* Initialize number of results to zero */
	*n = 0;
	if (s == NULL || words == NULL || nb_words <= 0)
		return (NULL);
	s_len = strlen(s);
	word_len = strlen(words[0]);
	total_len = nb_words * word_len;

	/* If total length of words is greater than s, no concatenation is possible */
	if (total_len > s_len)
		return (NULL);

	/* Allocate a maximum possible size for indices */
	indices = malloc(s_len * sizeof(int));
	if (indices == NULL)
		return (NULL);

	/* Loop through s to check every candidate starting index */
	for (i = 0; i <= s_len - total_len; i++)
	{
		/* is_valid_substring checks if the substring is exactly a concatenation */
		if (is_valid_substring(s, i, words, nb_words, word_len))
		{
			indices[count] = i;
			count++;
		}
	}
	/* If no valid index is found, free and return NULL */
	if (count == 0)
	{
		free(indices);
		return (NULL);
	}
	*n = count;
	return (indices);
}
