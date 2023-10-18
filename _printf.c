#include "main.h"
/**
 * _printf - function that produces output according to a format
 * @format: is a character string
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
init_params(&z, l);
if (*x != '%')
{
m += _putchar(*x);
continue;
}
st = x;
x++;
while (get_flag(x, &z))
{
x++;
}
x = get_width(x, l, &z);
x = get_precision(x, l, &z);

if (get_modifier(x, &z))
x++;
if (!get_specifier(x))
m += print_from_to(st, x, z.l_modifier || z.h_modifier ? x - 1 : 0);
else
m += get_pfunc(x, l, &z);

}
_putchar(BUF_FLUSH);
va_end(l);
return (m);
}
