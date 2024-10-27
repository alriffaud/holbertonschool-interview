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
	unsigned long reversed = 0, remainder, original;

	original = n;
	while (n != 0)
	{
		remainder = n % 10;
		reversed = reversed * 10 + remainder;
		n /= 10;
	}
	if (original == reversed)
		return (1);
	return (0);
}
