#include "main.h"

/**
 * print_number_left_shift - prints a number with options
 * @str: the base number as a string
 * @z: the parameter struct
 *
 * Return: chars printed
 */
int print_number_left_shift(char *str, flags_t *z)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (z->zero_flag && !z->minus_flag)
		pad_char = '0';
	neg = neg2 = (!z->unsign && *str == '-');
	if (neg && i < z->width && pad_char == '0' && !z->minus_flag)
		str++;
	else
		neg = 0;

	if (z->plus_flag && !neg2 && !z->unsign)
		n += _putchar('+'), i++;
	else if (z->space_flag && !neg2 && !z->unsign)
		n += _putchar(' '), i++;
	n += _puts(str);
	while (i++ < z->width)
		n += _putchar(pad_char);
	return (n);
}

/**
 * _isdigit - checks if character is digit
 * @c: the character to check
 *
 * Return: for digit 1, otherwise 0
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - returns the length of a string
 * @s: string
 * Return: integer length of string
 *
 */
int _strlen(char *s)
{
	int j = 0;

	while (*s++)
		j++;
	return (j);
}

/**
 * print_number_right_shift - prints a number
 * @str: the base number as a string
 * @z: the parameter struct
 *
 * Return: chars printed
 */
int print_number_right_shift(char *str, flags_t *z)
{
	unsigned int n = 0, neg, neg2, i = _strlen(str);
	char pad_char = ' ';

	if (z->zero_flag && !z->minus_flag)
		pad_char = '0';
	neg = neg2 = (!z->unsign && *str == '-');
	if (neg && i < z->width && pad_char == '0' && !z->minus_flag)
		str++;
	else
		neg = 0;
	if ((z->plus_flag && !neg2) ||
		(!z->plus_flag && z->space_flag && !neg2))
		i++;
	if (neg && pad_char == '0')
		n += _putchar('-');
	if (z->plus_flag && !neg2 && pad_char == '0' && !z->unsign)
		n += _putchar('+');
	else if (!z->plus_flag && z->space_flag && !neg2 &&
		!z->unsign && z->zero_flag)
		n += _putchar(' ');
	while (i++ < z->width)
		n += _putchar(pad_char);
	if (neg && pad_char == ' ')
		n += _putchar('-');
	if (z->plus_flag && !neg2 && pad_char == ' ' && !z->unsign)
		n += _putchar('+');
	else if (!z->plus_flag && z->space_flag && !neg2 &&
		!z->unsign && !z->zero_flag)
		n += _putchar(' ');
	n += _puts(str);
	return (n);
}

/**
 * print_number - prints a number with options
 * @str: the base number as a string
 * @z: the parameter struct
 *
 * Return: print characters
 */
int print_number(char *str,  flags_t *z)
{
	unsigned int i = _strlen(str);
	int neg = (!z->unsign && *str == '-');

	if (!z->precision && *str == '0' && !str[1])
		str = "";
	if (neg)
	{
		str++;
		i--;
	}
	if (z->precision != UINT_MAX)
		while (i++ < z->precision)
			*--str = '0';
	if (neg)
		*--str = '-';

	if (!z->minus_flag)
		return (print_number_right_shift(str, z));
	else
		return (print_number_left_shift(str, z));
}
