#include "main.h"

/**
 * _specifier - to fund format function.
 * @s: string of format
 *
 * Return: num of printed bytes.
 */
int (*_specifier(char *s))(va_list l, flags_t *z)
{
	specifier_t specifiers[] = {
	        {"c", _char},
		{"d", _int},
		{"i", _int},
		{"s", _string},
		{"%", _percent},
		{"b", _binary},
		{"o", _octal},
		{"u", _unsigned},
		{"x", _hex},
		{"X", _HEX},
		{"p", _address},
		{"S", _S},
		{"r", _rev},
		{"R", _rot13},
		{NULL, NULL}
	};
	int j = 0;

	while (specifiers[j].specifier)
	{
		if (*s == specifiers[j].specifier[0])
		{
			return (specifiers[j].f);
		}
		j++;
	}
	return (NULL);
}

/**
 * _flag - to find the flags of functions
 * @s: string format
 * @z: stuct of parameters
 *
 * Return: flag (valid)
 */
int _flag(char *s, flags_t *z)
{
	int j = 0;

	switch (*s)
	{
                case '#':
			j = z->hash_f= 1;
			break;
		case '-':
			j = z->minus_f = 1;
			break;
                case '0':
			j = z->z_f = 1;
			break;
		case '+':
			j = z->p_f = 1;
			break;
		case ' ':
			j = z->s_f = 1;
			break;
			}
	return (j);
}

/**
 * _pfunc - find the function of formats
 * @l: pointer of arg
 * @z: struct of parameter
 * @s: string format
 *
 * Return: num of printed bytes
 */
int _pfunc(char *s, va_list l, flags_t *z)
{
	int (*f)(va_list, flags_t *) = _specifier(s);

	if (f)
		return (f(l, z));
	return (0);
}

/**
 * _width - find width of string
 * @z: stuct parameteers
 * @l: pointer of arg
 * @s: string of format
 *
 * Return: the new pointer
 */
char *_width(char *s, va_list l, flags_t *z)
{
	int d = 0;

	if (*s == '*')
	{
		d = va_arg(l, int);
		s++;
	}
	else
	{
	  while (_isdigit(*s))
			d = d * 10 + (*s++ - '0');
	}
	z->width = d;
	return (s);
}

/**
 * _modify - finds the modifier func
 * @s: format of string
 * @z: the struct of parameters
 *
 * Return: modifer (valid)
 */
int _modify(char *s, flags_t *z)
{
	int j = 0;

	switch (*s)
	{
           case 'l':
		j = z->l_modifier = 1;
		break;
	   case 'h':
		j = z->h_modifier = 1;
		break;
	}
	return (j);
}
