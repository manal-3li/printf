#ifndef _PRINTF_H
#define _PRINTF_H

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define NULL_STRING "(null)"
#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED	2

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

/**
 * struct parameters - struct of parameters
 *
 * @unsign: flag if unsigned value
 *
 * @zero_flag: on if _flag specified
 * @minus_flag: on if _flag specified
 * @space_flag: on if hashtag_flag specified
 *
 * @hashtag_flag: on if _flag specified
 *
 * @h_modifier: on if h_modifier is specified
 * @l_modifier: on if l_modifier is specified
 *
 * @width: field width specified
 * @precision: field precision specified
 *
 */
typedef struct parameters
{
	unsigned int unsign			: 1;

	unsigned int plus_flag		: 1;
	unsigned int space_flag		: 1;
	unsigned int hashtag_flag	: 1;
	unsigned int zero_flag		: 1;
	unsigned int minus_flag		: 1;

	unsigned int width;
	unsigned int precision;

	unsigned int h_modifier		: 1;
	unsigned int l_modifier		: 1;
} flags_t;

/**
 * struct specifier - token of stuct
 *
 * @f: The function associated
 * @specifier: token of format
 */
typedef struct specifier
{
             int (*f)(va_list, flags_t*);
	char *specifier;
} specifier_t;

char *convert(long int num, int b, int f, flags_t *z);
int print_unsigned(va_list l, flags_t *z);
int print_address(va_list l, flags_t *z);

int (*get_specifier(char *s))(va_list l, flags_t *z);
int get_pfunc(char *s, va_list l, flags_t *z);
int get_flag(char *s,  flags_t *z);
int get_modifier(char *s,  flags_t *z);
char *get_width(char *s, va_list l, flags_t *z);

int _puts(char *st);
int _putchar(int c);

int print_char(va_list l, flags_t *z);
int print_integer(va_list l, flags_t *z);
int print_string(va_list l, flags_t *z);
int print_percent(va_list l, flags_t *z);
int print_S(va_list l, flags_t *z);

int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, flags_t *z);
int print_number_right_shift(char *str, flags_t *z);
int print_number_left_shift(char *str, flags_t *z);

int print_hex(va_list l, flags_t *z);
int print_HEX(va_list l, flags_t *z);
int print_binary(va_list l, flags_t *z);
int print_octal(va_list l, flags_t *z);

int print_from_to(char *stt, char *stp, char *exc);
int print_rev(va_list l, flags_t *z);
int print_rot13(va_list l, flags_t *z);

int _printf(const char *format, ...);

void init_params(va_list l, flags_t *z);

char *get_precision(char *n, va_list l, flags_t *z);

#endif
