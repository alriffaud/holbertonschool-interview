#include "holberton.h"
#include <stdio.h>


/**
 * wildcmp - compares two strings
 * @s1: string 1
 * @s2: string 2
 * Return: 1 if the strings can be considered identical, otherwise return 0
 */
int wildcmp(char *s1, char *s2)
{
	/* Base case: both strings have reached their end */
	if (*s1 == '\0' && *s2 == '\0')
		return (1);
	/* If the current character in s2 is a wildcard '*' */
	if (*s2 == '*')
	{
		if (*(s2 + 1) == '\0')
			return (1);
		if (*s1 != '\0' && wildcmp(s1 + 1, s2))
			return (1);
		return (wildcmp(s1, s2 + 1));
	}
	/* If the current characters of s1 and s2 match, move to the next */
	/* characters */
	if (*s1 == *s2)
		return (wildcmp(s1 + 1, s2 + 1));
	/* If none of the conditions are met, the strings are not identical */
	return (0);
}
