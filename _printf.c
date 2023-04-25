#include "main.h"

/**
 * _printf - Custom made printf function
 * @format: format.
 * Return: Number of bytes printed
 */
int _printf(const char *format, ...)
{
	int i, j, count = 0;
	char *s;
	va_list args;

	va_start(args, format);
	i = 0;
	if (format)
		while (format[i])
		{
			if (format[i] == '%')
			{
				i++;
				switch (format[i])
				{
				case 'c':
					count += _writer(va_arg(args, int));
					break;
				case '%':
					count += _writer('%');
					va_arg(args, int);
					break;
				case 's':
					s = va_arg(args, char *);
					j = 0;
					while (s[j])
						count += _writer(s[j++]);
					break;
				default:
					i++;
					va_arg(args, int);
					continue;
				}
			}
			else
				count += _writer(format[i]);
			i++;
		}
	va_end(args);
	return (count);
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
