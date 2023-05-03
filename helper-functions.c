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
	if (str == NULL)
		return (_puts("(null)"));
	else
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

/**
 * print_number - prints a number
 * @n: the number to print
 *
 * Return: length of character
 */
int print_number(int n)
{
	unsigned int nb;
	int count = 0;

	nb = n;
	if (n < 0)
	{
		count += _putchar('-');
		nb = -nb;
	}
	if (nb <= 9)
	{
		count += _putchar(nb + '0');
		return (count);
	}
	if (nb > 9)
	{
		count += print_number(nb / 10) + 1;
		_putchar(nb % 10 + '0');
		return (count);
	}
	return (0);
}

/**
 * print_binary - prints a binary representation of @n
 * @n: the number
 *
 * Return: length of character
 */
int print_binary(unsigned int n)
{
	int count = 0, binary[64] = {0}, j, i = 0;

	if (n == 0)
	{
		count += _putchar('0');
		return (count);
	}

	while (n > 0)
	{
		binary[i++] = n % 2;
		n /= 2;
	}
	for (j = i - 1; j >= 0; j--)
	{
		count += _putchar(binary[j] + '0');
	}
	return (count);
}

/**
 * print_uint - prints an unsigned number
 * @n: the number
 *
 * Return: length of character
 */
int print_uint(unsigned int n)
{
	int count = 0;

	if (n <= 9)
	{
		count += _putchar(n + '0');
		return (count);
	}
	if (n > 9)
	{
		count += print_uint(n / 10) + 1;
		_putchar(n % 10 + '0');
		return (count);
	}
	return (0);
}

/**
 * print_octal - prints an octal representation of @n
 * @n: the number
 *
 * Return: length of character
 */
int print_octal(unsigned int n)
{
	int count = 0, octal[64] = {0}, j, i = 0;

	if (n == 0)
	{
		count += _putchar('0');
		return (count);
	}

	while (n > 0)
	{
		octal[i++] = n % 8;
		n /= 8;
	}
	for (j = i - 1; j >= 0; j--)
	{
		count += _putchar(octal[j] + '0');
	}
	return (count);
}

/**
 * print_hex - prints hex value of @n
 * @n: the number
 *
 * Return: length of character
 */
int print_hex(unsigned int n, int uppercase)
{
	int count = 0, j, i = 0;
	char hex[100];

	if (n == 0)
	{
		count += _putchar('0');
		return (count);
	}

	while (n > 0)
	{
		unsigned int remainder = n % 16;

		if (remainder < 10)
			hex[i++] = remainder + '0';
		else
			hex[i++] = remainder + (uppercase == TRUE ? '7' : 'W');
		n /= 16;
	}

	for (j = i - 1; j >= 0; j--)
		count += _putchar(hex[j]);

	return (count);
}
