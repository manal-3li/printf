#include "main.h"
/**
 * _precision - get precision from the format string
 * @n: the format string
 * @z: the parameters struct
 * @l: argument pointer
 *
 * Return: new pointer
 *
*/
char *_precision(char *n, va_list l, flags_t *z)
{

int f = 0;
if (*n != '.')
return (n);
n++;
if (*n == '*')
{
f = va_arg(l, int);
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
