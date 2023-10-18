#include "main.h"

/**
 * print_int - the print of int
 * @l: pointer of argument
 * @z: struct of parameters
 *
 * Return: number chars printed
 */
int print_int(va_list l, flags_t *z)
{
	long l;

	if (z->l_modifier)
		l = va_arg(l, long);
	else if (z->h_modifier)
		l = (short int)va_arg(l, int);
	else
		l = (int)va_arg(l, int);
	return (print_number(convert(l, 10, 0, z), z));
}

/**
 * print_char - print the character
 * @l: argument pointer
 * @z: the parameters struct
 *
 * Return: print num chars
 */
int print_char(va_list l, flags_t *z)
{
	char pad_char = ' ';
	unsigned int pad = 1, s = 0, ch = va_arg(l, int);

	if (z->minus_flag)
		s += _putchar(ch);
	while (pad++ < z->width)
		s += _putchar(pad_char);
	if (!z->minus_flag)
		s += _putchar(ch);
	return (s);
}

/**
 * print_string - prints string
 * @l: argument pointer
 * @z: the parameters struct
 *
 * Return: number chars printed
 */
int print_string(va_list l, flags_t *z)
{
	char *str = va_arg(l, char *), pad_char = ' ';
	unsigned int pad = 0, s = 0, i = 0, j;

	(void)params;
	switch ((int)(!str))
		case 1:
			str = NULL_STRING;

	j = pad = _strlen(str);
	if (z->precision < pad)
		j = pad = z->precision;

	if (z->minus_flag)
	{
		if (z->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				sum += _putchar(*str++);
		else
			sum += _puts(str);
	}
	while (j++ < z->width)
		sum += _putchar(pad_char);
	if (!z->minus_flag)
	{
		if (z->precision != UINT_MAX)
			for (i = 0; i < pad; i++)
				s += _putchar(*str++);
		else
			s += _puts(str);
	}
	return (s);
}

/**
 * print_S - custom format specifier
 * @l: argument pointer
 * @z: the parameters struct
 *
 * Return: number chars printed
 */
int print_S(va_list l, flags_t *z)
{
	char *str = va_arg(l, char *);
	char *hex;
	int s = 0;

	if ((int)(!str))
		return (_puts(NULL_STRING));
	for (; *str; str++)
	{
		if ((*str > 0 && *str < 32) || *str >= 127)
		{
			s+= _putchar('\\');
			s += _putchar('x');
			hex = convert(*str, 16, 0, z);
			if (!hex[1])
				s += _putchar('0');
			s += _puts(hex);
		}
		else
		{
			s += _putchar(*str);
		}
	}
	return (s);
}

/**
 * print_percent - prints string
 * @l: argument pointer
 * @z: the parameters struct
 *
 * Return: number chars printed
 */
int print_percent(va_list l, flags_t *z)
{
	(void)l;
	(void)z;
	return (_putchar('%'));
}
