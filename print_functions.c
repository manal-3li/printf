#include "main.h"

/**
 * _int - the print of int
 * @l: pointer of argument
 * @z: struct of parameters
 *
 * Return: number chars printed
 */
int _int(va_list l, flags_t *z)
{
    long o;

    if (z->l_modifier)
        o = va_arg(l, long);
    else if (z->h_modifier)
        o = (short int)va_arg(l, int);
    else
        o = (int)va_arg(l, int);
    return (_number(convert(o, 10, 0, z), z));
}

/**
 * _char - print the character
 * @l: argument pointer
 * @z: the parameters struct
 *
 * Return: print num chars
 */
int _char(va_list l, flags_t *z)
{
    char pad_char = ' ';
    unsigned int pad = 1, s = 0, ch = va_arg(l, int);

    if (z->minus_f)
        s += put_char(ch);
    while (pad++ < z->width)
        s += put_char(pad_char);
    if (!z->minus_f)
        s += put_char(ch);
    return (s);
}

/**
 * _string - prints string
 * @l: argument pointer
 * @z: the parameters struct
 *
 * Return: number chars printed
 */
int _string(va_list l, flags_t *z)
{
    char *str = va_arg(l, char *), pad_char = ' ';
    unsigned int pad = 0, s = 0, i = 0, j;

    (void)z;
    switch ((int)(!str))
    case 1:
    str = NULL_STRING;

    j = pad = _strlen(str);
    if (z->precision < pad)
        j = pad = z->precision;

    if (z->minus_f)
    {
        if (z->precision != UINT_MAX)
            for (i = 0; i < pad; i++)
                s += put_char(*str++);
        else
            s += _put(str);
    }
    while (j++ < z->width)
        s += put_char(pad_char);
    if (!z->minus_f)
    {
        if (z->precision != UINT_MAX)
            for (i = 0; i < pad; i++)
                s += put_char(*str++);
        else
            s += _put(str);
    }
    return (s);
}

/**
 * _S - custom format specifier
 * @l: argument pointer
 * @z: the parameters struct
 *
 * Return: number chars printed
 */
int _S(va_list l, flags_t *z)
{
    char *str = va_arg(l, char *);
    char *hex;
    int s = 0;

    if ((int)(!str))
        return (_put(NULL_STRING));
    for (; *str; str++)
    {
        if ((*str > 0 && *str < 32) || *str >= 127)
        {
            s+= put_char('\\');
            s += put_char('x');
            hex = convert(*str, 16, 0, z);
            if (!hex[1])
                s += put_char('0');
            s += _put(hex);
        }
        else
        {
            s += put_char(*str);
        }
    }
    return (s);
}

/**
 * _percent - prints string
 * @l: argument pointer
 * @z: the parameters struct
 *
 * Return: number chars printed
 */
int _percent(va_list l, flags_t *z)
{
    (void)l;
    (void)z;
    return (put_char('%'));
}
