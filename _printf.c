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
			if (format[i + 1] == '\0')
				return (-1);
			i++;
			switch (format[i])
			{
			case 'd':
			case 'i':
				count += print_number(va_arg(args, int));
				break;
			case 'c':
				count += print_char(va_arg(args, int));
				break;
			case '%':
				count += print_percentage();
				break;
			case 's':
				count += print_string(va_arg(args, char *));
				break;
			default:
				count += print_char(format[--i]);
				break;
			}
		}
		else
			count += print_char(format[i]);
		i++;
	}
	va_end(args);
	return (count);
}
