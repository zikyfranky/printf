#include "main.h"

/**
 * _printf - Custom made printf function
 * @format: format.
 * Return: Number of bytes printed
 */
int _printf(const char *format, ...)
{
	int i, j, count = 0, flag;
	char *s;
	va_list args;

	va_start(args, format);

	i = 0;
	if (format)
	{
		while (format[i])
		{
			if (format[i] == '%')
			{
				i++;
				switch (format[i])
				{
				case 'c':
					flag = _putchar(va_arg(args, int));
					if (flag >= 0)
					{
						count += flag;
					}
					break;
				case '%':
					flag = _putchar('%');
					if (flag >= 0)
					{
						count += flag;
					}
					va_arg(args, int);
					break;
				case 's':
					s = va_arg(args, char *);
					j = 0;
					while (s[j])
					{
						flag = _putchar(s[j++]);
						if (flag >= 0)
						{
							count += flag;
						}
					}
					break;
				default:
					i++;
					va_arg(args, int);
					continue;
				}
			}
			else
			{
				flag = _putchar(format[i]);
				if (flag >= 0)
				{
					count += flag;
				}
			}
			i++;
		}
	}
	va_end(args);
	return (count);
}
