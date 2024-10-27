#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include "palindrome.h"


/**
 * is_palindrome - This function checks whether or not a given unsigned integer
 * is a palindrome.
 * @n: number to be checked
 * Return: 1 if n is a palindrome, and 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	char s[20];
	int len_s, i, j;

	sprintf(s, "%ld", n);
	len_s = strlen(s);
	i = 0;
	j = len_s - 1;
	while (s[i] == s[j] && i < len_s / 2)
	{
		i++;
		j--;
	}
	if (i == len_s / 2)
		return (1);
	else
		return (0);
}
