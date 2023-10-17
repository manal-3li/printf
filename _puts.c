#include "main.h"
/**
 * _puts - prints a string with newline
 * @st: string to print
 * return: void
 *
 *
*/
int _puts(char *st)
{

char *c = st;

while (*st)
_putchar(*st++);
return(st - c);

}

/**
 * _putchar - writes the char y to stdout
 *
 * @y: the char to print
 * Return: 1 if success, -1 if error
 *
*/
int _putchar(int y)
{
static int l;
static char  buf[OUTPUT_BUF_SIZE];
if (y == BUF_FLUSH || l >= OUT_BUF_SIZE)
{
write(1, buf, l);
l = 0;
}
if (y != BUF_FLUSH)
buf[l++] = y;
return (1);
}
