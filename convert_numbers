#include "main.h"

/**
 * print_octal - print unsigned octal num
 * @l: pointer of arguments
 * @z: stuct parameters
 *
 * Return: print of bytes
 */
int print_octal(va_list l, flags_t *z)
{
            char *c;
	int i = 0;
	unsigned long u;
	
	if (z->h_modifier)
		u = (unsigned short int)va_arg(l, unsigned int);
	else if (z->l_modifier)
		u = (unsigned long)va_arg(l, unsigned long);
	else
		u = (unsigned int)va_arg(l, unsigned int);
	str = convert(u, 8, CONVERT_UNSIGNED, z);

	if (z->hashtag_flag && u)
		*--c = '0';
	z->unsign = 1;
	return (i += print_number(c, z));
}

/**
 * print_binary - prints unsigned num
 * @l: pointer of arguments
 * @z: stuct parameters
 *
 * Return: print of bytes
 */
int print_binary(va_list l, flags_t *z)
{
	unsigned int n = va_arg(l, unsigned int);
	char *c = convert(n, 2, CONVERT_UNSIGNED, z);
	int i = 0;

	if (z->hashtag_flag && n)
		*--c = '0';
	z->unsign = 1;
	return (i += print_number(c, z));
}

/**
 * print_hex - print the lowercase of unsigned hex numbers
 * @l: pointer of arguments
 * @z: stuct parameters
 *
 * Return: print of bytes
 */
int print_hex(va_list l, flags_t *z)
{
             int i = 0;
	char *c;
	unsigned long u;

	if (z->h_modifier)
		u = (unsigned short int)va_arg(l, unsigned int);
	else if (z->l_modifier)
		u = (unsigned long)va_arg(l, unsigned long);
	else
		u = (unsigned int)va_arg(l, unsigned int);

	str = convert(u, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, z);
	if (z->hashtag_flag && u)
	{
		*--c = 'x';
		*--c = '0';
	}
	z->unsign = 1;
	return (i += print_number(c, z));
}

/**
 * print_HEX - print the uppercase of unsigned hex numbers
 * @l: pointer of arguments
 * @z: stuct parameters
 *
 * Return: print of bytes
 */
int print_HEX(va_list l, flags_t *z )
{
             int i = 0;
	char *c;
	unsigned long u;
	
             if (z->h_modifier)
		u = (unsigned short int)va_arg(l, unsigned int);
	else if (z->l_modifier)
		u = (unsigned long)va_arg(l, unsigned long);
	else
		u = (unsigned int)va_arg(l, unsigned int);

	str = convert(u, 16, CONVERT_UNSIGNED, z);
	if (z->hashtag_flag && u)
	{
		*--c = 'X';
		*--c = '0';
	}
	z->unsign = 1;
	return (i += print_number(c, z));
}
