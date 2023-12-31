#include "main.h"
/**
 * simple_printers - prints a range of char addresses
 * @stt: starting address
 * @stp: stoping address
 * @exc: except address
 *
 * Return: number of bytes
*/
int simple_printers(char *stt, char *stp, char *exc)
{
    int y = 0;
    while (stt <= stp)
    {
        if (stt != exc)
            y += put_char(*stt);
        stt++;
    }
    return (y);
}
/**
 * _rev - print string in reverse
 * @l: string
 * @z: the parameters struct
 * Return: number bytes printed
 *
*/
int _rev(va_list l, flags_t *z)
{
    int i;
    int s = 0;
    char *y = va_arg(l, char *);
    (void)z;
    if (y)
    {
        for (i = 0; *y; y++)
            i++;
        y--;
        for (; i > 0; i--, y--)
            s += put_char(*y);
    }
    return (s);
}
/**
 * _rot13 - prints the rot13'ed string
 * @l: string
 * @z: the parameters struct
 * Return: number bytes printed
*/
int _rot13(va_list l, flags_t *z)
{
    int n;
    int ind;
    int c = 0;
    char ai[] =
        "NOPQRSTUVWXYZABCDEFGHIJKLM    nopqrstuvwxyzabcdefghijklm";
    char *x = va_arg(l, char *);
    (void)z;
    n = 0, ind = 0;
    while (x[n])
    {
        if ((x[n] >= 'A' && x[n] <= 'Z') || (x[n] >= 'a' && x[n] <= 'z'))
        {
            ind = x[n] - 65;
            c += put_char(ai[ind]);
        }
        else
            c += put_char(x[n]);
        n++;
    }
    return (c);
}
