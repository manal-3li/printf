#include "main.h"

/**
 * number_leftshift - prints a number with options
 * @str: the base number as a string
 * @z: the parameter struct
 *
 * Return: chars printed
 */
int number_leftshift(char *str, flags_t *z)
{
    unsigned int n = 0, neg, neg2, i = _strlen(str);
    char pad_char = ' ';

    if (z->z_f && !z->minus_f)
        pad_char = '0';
    neg = neg2 = (!z->unsign && *str == '-');
    if (neg && i < z->width && pad_char == '0' && !z->minus_f)
        str++;
    else
        neg = 0;

    if (z->p_f && !neg2 && !z->unsign)
        n += put_char('+'), i++;
    else if (z->s_f && !neg2 && !z->unsign)
        n += put_char(' '), i++;
    n += _put(str);
    while (i++ < z->width)
        n += put_char(pad_char);
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
 * number_rightshift - prints a number
 * @str: the base number as a string
 * @z: the parameter struct
 *
 * Return: chars printed
 */
int number_rightshift(char *str, flags_t *z)
{
    unsigned int n = 0, neg, neg2, i = _strlen(str);
    char pad_char = ' ';

    if (z->z_f && !z->minus_f)
        pad_char = '0';
    neg = neg2 = (!z->unsign && *str == '-');
    if (neg && i < z->width && pad_char == '0' && !z->minus_f)
        str++;
    else
        neg = 0;
    if ((z->p_f && !neg2) ||
            (!z->p_f && z->s_f && !neg2))
        i++;
    if (neg && pad_char == '0')
        n += put_char('-');
    if (z->p_f && !neg2 && pad_char == '0' && !z->unsign)
        n += put_char('+');
    else if (!z->p_f && z->s_f && !neg2 &&
             !z->unsign && z->z_f)
        n += put_char(' ');
    while (i++ < z->width)
        n += put_char(pad_char);
    if (neg && pad_char == ' ')
        n += put_char('-');
    if (z->p_f && !neg2 && pad_char == ' ' && !z->unsign)
        n += put_char('+');
    else if (!z->p_f && z->s_f && !neg2 &&
             !z->unsign && !z->z_f)
        n += put_char(' ');
    n += _put(str);
    return (n);
}

/**
 * _number - prints a number with options
 * @str: the base number as a string
 * @z: the parameter struct
 *
 * Return: print characters
 */
int _number(char *str,  flags_t *z)
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

    if (!z->minus_f)
        return (number_rightshift(str, z));
    else
        return (number_leftshift(str, z));
}
