#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define TRUE 0
#define FALSE 1

int _printf(const char *format, ...);
int _putchar(char c);
int _puts(char *str);
int print_char(char c);
int print_string(char *str);
int print_percentage(void);
int print_number(int n);
int print_binary(unsigned int n);
int print_uint(unsigned int n);
int print_octal(unsigned int n);
int print_hex(unsigned int n, int uppercase);

#endif /* MAIN_H */
