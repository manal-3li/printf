#include "main.h"

/**
 * _octal - print unsigned octal num
 * @l: pointer of arguments
 * @z: stuct parameters
 *
 * Return: print of bytes
 */
int _octal(va_list l, flags_t *z)
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
	c = convert(u, 8, CONVERT_UNSIGNED, z);

	if (z->hash_f && u)
		*--c = '0';
	z->unsign = 1;
	return (i += _number(c, z));
}

/**
 * _binary - prints unsigned num
 * @l: pointer of arguments
 * @z: stuct parameters
 *
 * Return: print of bytes
 */
int _binary(va_list l, flags_t *z)
{
	unsigned int n = va_arg(l, unsigned int);
	char *c = convert(n, 2, CONVERT_UNSIGNED, z);
	int i = 0;

	if (z->hash_f && n)
		*--c = '0';
	z->unsign = 1;
	return (i += _number(c, z));
}

/**
 * _hex - print the lowercase of unsigned hex numbers
 * @l: pointer of arguments
 * @z: stuct parameters
 *
 * Return: print of bytes
 */
int _hex(va_list l, flags_t *z)
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

	c = convert(u, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, z);
	if (z->hash_f && u)
	{
		*--c = 'x';
		*--c = '0';
	}
	z->unsign = 1;
	return (i += _number(c, z));
}

/**
 * _HEX - print the uppercase of unsigned hex numbers
 * @l: pointer of arguments
 * @z: stuct parameters
 *
 * Return: print of bytes
 */
int _HEX(va_list l, flags_t *z )
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

	c = convert(u, 16, CONVERT_UNSIGNED, z);
	if (z->hash_f && u)
	{
		*--c = 'X';
		*--c = '0';
	}
	z->unsign = 1;
	return (i += _number(c, z));
}
