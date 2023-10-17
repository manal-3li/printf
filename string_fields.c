#include "main.h"
/**
 * get_precision - get precision from the format string
 * @n: the format string
 * @z: the parameters struct
 * @l: argument pointer
 * Return: new pointer
 *
*/
char *get_precision(char *n, flags_t *z, va_list l)
{

int f = 0;
if (*n != '.')
return (n);
n++;
if (*n == '*')
{
d = va_arg(l, int)
n++;
}
else
{
while (_isdigit(*n))
f = f * 10 + (*n++ - '0');
}
z->precision = f;
return (n);
}
