#include "main.h"

/**
 * _printf - Custom made printf function
 * @format: format.
 * Return: Number of bytes printed
 */
int _printf(const char *format, ...)
{
	int i = 0, j, count = 0;
	char *s;
	va_list args;

	if (!format || (format[0] == '%' && format[1] == '\0'))
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			switch (format[i + 1])
			{
			case 'c':
				count += _writer(va_arg(args, int));
				i += 2;
				break;
			case '%':
				count += _writer('%');
				va_arg(args, int);
				i += 2;
				break;
			case 's':
				s = va_arg(args, char *);
				j = 0;
				while (s[j])
					count += _writer(s[j++]);
				i += 2;
				break;
			default:
				count += _writer(format[i++]);
				break;
			}
		}
		else
			count += _writer(format[i++]);
	}
	va_end(args);
	return (count);
}
