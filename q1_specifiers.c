#include "main.h"

/**
 * get_flag - to find the flags of functions
 * @m: string format
 * @z: stuct of parameters
 *
 * Return: flag (valid)
 */
int get_flag(char *m, flags_t *z)
{
	int j = 0;

	switch (*m)
	{
                case '#':
			j = params->hashtag_flag = 1;
			break;
		case '-':
			j = params->minus_flag = 1;
			break;
                case '0':
			j = params->zero_flag = 1;
			break;
		case '+':
			j = params->plus_flag = 1;
			break;
		case ' ':
			j = params->space_flag = 1;
			break;
			}
	return (j);
}


/**
 * get_specifier - to fund format function.
 * @m: string of format
 *
 * Return: num of printed bytes.
 */
int (*get_specifier(char *m))(va_list l, flags_t *z)
{
	specifier_t specifiers[] = {
		{"c", print_char},
                {"X", print_HEX},
		{"p", print_address},
		{"S", print_S},
		{"r", print_rev},
		{"R", print_rot13},
		{"d", print_integer},
		{"%", print_percent},
		{"b", print_binary},
		{"o", print_octal},
		{"u", print_unsigned},
		{"x", print_hex},
                {"i", print_integer},
		{"s", print_string},
		{NULL, NULL}
	};
	int j = 0;

	while (specifiers[j].specifier)
	{
		if (*m == specifiers[j].specifier[0])
		{
			return (specifiers[j].f);
		}
		j++;
	}
	return (NULL);
}

/**
 * get_pfunc - find the function of formats
 * @l: pointer of arg
 * @z: struct of parameter
 * @m: string format
 *
 * Return: num of printed bytes
 */
int get_pfunc(char *m, va_list l, flags_t *z)
{
	int (*f)(va_list, flags_t *) = get_specifier(m);

	if (f)
		return (f(l, z));
	return (0);
}

/**
 * get_width - find width of string
 * @z: stuct parameteers
 * @l: pointer of arg
 * @m: string of format
 *
 * Return: the new pointer
 */
char *get_width(char *m, va_list l, flags_t *z);)
{
	int d = 0;

	if (*m == '*')
	{
		d = va_arg(l, int);
		m++;
	}
	else
	{
		while (_isdigit(*m))
			d = d * 10 + (*m++ - '0');
	}
	params->width = d;
	return (m);
}

/**
 * get_modifier - finds the modifier func
 * @m: format of string
 * @z: the struct of parameters
 *
 * Return: modifer (valid)
 */
int get_modifier(char *m, flags_t *z)
{
	int j = 0;

	switch (*m)
	{
           case 'l':
		j = params->l_modifier = 1;
		break;
	   case 'h':
		j = params->h_modifier = 1;
		break;
	}
	return (j);
}
