#include "main.h"
/**
 * _printf - function produces output to a format
 * @format: character string
 *
 * Return: the number of characters printed
 *
 */
int _printf(const char *format, ...)
{
    int m = 0;
    va_list l;
    char *x, *st;
    flags_t z = PARAMS_INIT;
    va_start(l, format);
    if ((!format[1] && format[0] == '%') || !format)
    {
        return (-1);
    }
    if (format[1] == ' ' && !format[2] && format[0] == '%')
    {
        return (-1);
    }
    for (x = (char*)format; *x; x++)
    {
        init_z(&z, l);
        if (*x != '%')
        {
            m += put_char(*x);
            continue;
        }
        st = x;
        x++;
        while (_flag(x, &z))
        {
            x++;
        }
        x = _width(x, l, &z);
        x = _precision(x, l, &z);

        if (_modify(x, &z))
            x++;
        if (!_specifier(x))
            m += simple_printers(st, x, z.l_modifier || z.h_modifier ? x - 1 : 0);
        else
            m += _pfunc(x, l, &z);

    }
    put_char(BUF_FLUSH);
    va_end(l);
    return (m);
}
