#include "main.h"

/**
 * get_specifier - to fund format function.
 * @s: string of format
 *
 * Return: num of printed bytes.
 */
int (*get_specifier(char *s))(va_list l, flags_t *z)
{
	specifier_t specifiers[] = {
	       {"c", print_char},
		{"d", print_rev},
		{"i", print_rev},
		{"s", print_string},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
		{"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
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
 * get_flag - to find the flags of functions
 * @s: string format
 * @z: stuct of parameters
 *
 * Return: flag (valid)
 */
int get_flag(char *s, flags_t *z)
{
	int j = 0;

	switch (*s)
	{
                case '#':
			j = z->hashtag_flag = 1;
			break;
		case '-':
			j = z->minus_flag = 1;
			break;
                case '0':
			j = z->zero_flag = 1;
			break;
		case '+':
			j = z->plus_flag = 1;
			break;
		case ' ':
			j = z->space_flag = 1;
			break;
			}
	return (j);
}

/**
 * get_pfunc - find the function of formats
 * @l: pointer of arg
 * @z: struct of parameter
 * @s: string format
 *
 * Return: num of printed bytes
 */
int get_pfunc(char *s, va_list l, flags_t *z)
{
	int (*f)(va_list, flags_t *) = get_specifier(s);

	if (f)
		return (f(l, z));
	return (0);
}

/**
 * get_width - find width of string
 * @z: stuct parameteers
 * @l: pointer of arg
 * @s: string of format
 *
 * Return: the new pointer
 */
char *get_width(char *s, va_list l, flags_t *z)
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
 * get_modifier - finds the modifier func
 * @s: format of string
 * @z: the struct of parameters
 *
 * Return: modifer (valid)
 */
int get_modifier(char *s, flags_t *z)
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
