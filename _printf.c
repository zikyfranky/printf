#include "main.h"

/**
 * _printf - Custom made printf function
 * @format: format.
 * Return: Number of bytes printed
 */
int _printf(const char *format, ...)
{
	int i = 0, count = 0;
	va_list args;

	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	va_start(args, format);
	while (format[i])
	{
		if (format[i] == '%')
		{
			switch (format[i + 1])
			{
			case 'c':
				count += print_char(va_arg(args, int));
				i += 2;
				break;
			case '%':
				count += print_percentage();
				i += 2;
				break;
			case 's':
				count += print_string(va_arg(args, char *));
				i += 2;
				break;
			default:
				count += print_char(format[i++]);
				break;
			}
		}
		else
			count += print_char(format[i++]);
	}
	va_end(args);
	return (count);
}
