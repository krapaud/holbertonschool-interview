#include "palindrome.h"

/**
 * is_palindrome - Checks if an unsigned integer is a palindrome
 * @n: The number to check
 *
 * Return: 1 if palindrome, 0 otherwise
 */
int is_palindrome(unsigned long n)
{
	unsigned long original;
	unsigned long reversed;

	original = n;
	reversed = 0;

	while (n > 0)
	{
		reversed = reversed * 10 + n % 10;
		n /= 10;
	}
	if (original == reversed)
		return (1);
	return (0);
}
