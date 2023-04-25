#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

int _printf(const char *format, ...);
int _putchar(char c);
int _puts(char *str);
int print_char(char c);
int print_string(char *str);
int print_percentage(void);
int print_number(int n);

#endif /* MAIN_H */
