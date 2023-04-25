#include "main.h"

/**
 * _putchar - writes the character c to stdout
 * @c: The character to print
 *
 * Return: On success 1.
 */
int _putchar(char c)
{
	(write(1, &c, 1));
	return (1);
}

/**
 * _puts - prints a string with newline
 * @str: the string to print
 *
 * Return: length of string
 */
int _puts(char *str)
{
	char *a = str;

	while (*str)
		_putchar(*str++);
	return (str - a);
}

/**
 * print_char - prints a character
 * @c: the character to print
 *
 * Return: length of character
 */
int print_char(char c)
{
	return (_putchar(c));
}

/**
 * print_string - prints a string
 * @str: the string to print
 *
 * Return: length of string
 */
int print_string(char *str)
{
	return (_puts(str));
}

/**
 * print_percentage - prints a percentage
 *
 * Return: length of character
 */
int print_percentage(void)
{
	return (_putchar('%'));
}
