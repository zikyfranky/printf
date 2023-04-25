#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _writer - Helper function to easily get bytes written
 * Makes use of the _putchar() function
 * @c: Character to wite to stdout
 * Return: the number of bytes written
 */
int _writer(char c)
{
	int flag = _putchar(c);

	return (flag >= 0 ? flag : 0);
}
