#ifndef MAIN_H
#define MAIN_H

#include <limits.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>

#define OUTPUT_BUF_SIZE 1024
#define BUF_FLUSH -1

#define NULL_STRING "(null)"
#define PARAMS_INIT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

#define CONVERT_LOWERCASE       1
#define CONVERT_UNSIGNED	2


/**
 * struct parameters - struct of parameter
 * @unsign: flag if unsigned value
 * @z_f: on if _flag specified
 * @minus_f: on if _flag specified
 * @s_f: on if hashtag_flag specified
 * @hash_f: on if _flag specified
 * @h_modifier: on if h_modifier is specified
 * @l_modifier: on if l_modifier is specified
 * @width: field width specified
 * @precision: field precision specified
 *
 */
typedef struct parameters
{
    unsigned int unsign			: 1;

    unsigned int p_f		: 1;
    unsigned int s_f		: 1;
    unsigned int hash_f	: 1;
    unsigned int z_f		: 1;
    unsigned int minus_f		: 1;

    unsigned int width;
    unsigned int precision;

    unsigned int h_modifier		: 1;
    unsigned int l_modifier		: 1;
} flags_t;

/**
 * struct specifier - token of stuct
 *
 * @specifier: token of format
 * @f: The function associated
 */
typedef struct specifier
{
    char *specifier;
    int (*f)(va_list, flags_t *);

} specifier_t;

int _put(char *st);
int put_char(int c);

int _char(va_list l, flags_t *z);
int _int(va_list l, flags_t *z);
int _string(va_list l, flags_t *z);
int _percent(va_list l, flags_t *z);
int _S(va_list l, flags_t *z);

char *convert(long int num, int b, int f, flags_t *z);
int _unsigned(va_list l, flags_t *z);
int _address(va_list l, flags_t *z);

int (*_specifier(char *s))(va_list l, flags_t *z);
int _pfunc(char *s, va_list l, flags_t *z);
int _flag(char *s,  flags_t *z);
int _modify(char *s,  flags_t *z);
char *_width(char *s, va_list l, flags_t *z);

int _hex(va_list l, flags_t *z);
int _HEX(va_list l, flags_t *z);
int _binary(va_list l, flags_t *z);
int _octal(va_list l, flags_t *z);

int print_char(va_list l, flags_t *z);
int print_integer(va_list l, flags_t *z);
int print_rev(va_list l, flags_t *z);
int print_percent(va_list l, flags_t *z);
int print_S(va_list l, flags_t *z);

int simple_printers(char *stt, char *stp, char *exc);
int _rev(va_list l, flags_t *z);
int _rot13(va_list l, flags_t *z);

int _isdigit(int c);
int _strlen(char *s);
int _number(char *str, flags_t *z);
int number_rightshift(char *str, flags_t *z);
int number_leftshift(char *str, flags_t *z);

void init_z(flags_t *z, va_list l);


int print_from_to(char *stt, char *stp, char *exc);
int print_rot13(va_list l, flags_t *z);

char *_precision(char *n, va_list l, flags_t *z);


int _printf(const char *format, ...);

#endif
