#include "holberton.h"
#include <stdlib.h>
#include <stdio.h>


/**
 * _is_digit - Checks if a string contains only digits
 * @s: The string to check
 *
 * Return: 1 if all characters are digits, 0 otherwise
 */
int _is_digit(char *s)
{
	while (*s)
	{
		if (*s < '0' || *s > '9')
			return (0);
		s++;
	}
	return (1);
}


/**
 * _strlen - Returns the length of a string
 * @s: The string to check
 *
 * Return: The length of the string
 */
int _strlen(char *s)
{
	int len = 0;

	while (*s++)
		len++;
	return (len);
}


/**
 * main - Multiplies two positive numbers
 * @argc: Number of arguments
 * @argv: Array of arguments
 *
 * Return: 0 on success, 98 on failure
 */
int main(int argc, char *argv[])
{
	char *num1, *num2;
	int len1, len2, i, j, carry, n1, n2, *result, k;

	if (argc != 3 || !_is_digit(argv[1]) || !_is_digit(argv[2]))
	{
		printf("Error\n");
		exit(98); }
	num1 = argv[1];
	num2 = argv[2];
	len1 = _strlen(num1);
	len2 = _strlen(num2);
	result = calloc(len1 + len2, sizeof(int));
	if (!result)
	{
		printf("Error\n");
		exit(98); }
	for (i = len1 - 1; i >= 0; i--)
	{
		n1 = num1[i] - '0';
		carry = 0;

		for (j = len2 - 1; j >= 0; j--)
		{
			n2 = num2[j] - '0';
			carry += result[i + j + 1] + (n1 * n2);
			result[i + j + 1] = carry % 10;
			carry /= 10; }
		result[i + j + 1] += carry; }
	k = 0;
	while (k < len1 + len2 && result[k] == 0)
		k++;
	if (k == len1 + len2)
		_putchar('0');
	for (; k < len1 + len2; k++)
		_putchar(result[k] + '0');
	_putchar('\n');
	free(result);
	return (0);
}
