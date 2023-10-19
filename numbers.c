#include "main.h"

/**
 * _address - prints address
 * @l: argument pointer
 * @z: the parameters struct
 *
 * Return: bytes printed
 */
int _address(va_list l, flags_t *z)
{
	unsigned long int n = va_arg(l, unsigned long int);
	char *s;

	if (!n)
		return (_put("(nil)"));

	s = convert(n, 16, CONVERT_UNSIGNED | CONVERT_LOWERCASE, z);
	*--s = 'x';
	*--s = '0';
	return (_number(s, z));
}

/**
 * _unsigned - prints unsigned integer numbers
 * @z: the parameters struct
 * @l: argument pointer
 *
 * Return: bytes printed
 */
int _unsigned(va_list l, flags_t *z)
{
	unsigned long u;

	if (z->h_modifier)
		u = (unsigned short int)va_arg(l, unsigned int);
	else if (z->l_modifier)
		u = (unsigned long)va_arg(l, unsigned long);
	else
		u = (unsigned int)va_arg(l, unsigned int);
	z->unsign = 1;
	return (_number(convert(u, 10, CONVERT_UNSIGNED, z), z));
}

/**
 * convert - ,a clone of itoa - converter function
 * @f: argument flags
 * @b: thebase
 * @z: paramater struct
 * @num: the number
 *
 * Return: string
 */
char *convert(long int num, int b, int f, flags_t *z)
{
	static char *a;
	static char buffer[50];
	char sign = 0;
	char *p;
	unsigned long n = num;
	(void)z;

	if (!(f & CONVERT_UNSIGNED) && num < 0)
	{
		n = -num;
		sign = '-';

	}
	a = f & CONVERT_LOWERCASE ? "0123456789abcdef" : "0123456789ABCDEF";
	p = &buffer[49];
	*p = '\0';

	do	{
		*--p = a[n % b];
		n /= b;
	} while (n != 0);

	if (sign)
		*--p = sign;
	return (p);
}
