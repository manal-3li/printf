#include "main.h"
/**
 * _put - prints a string with newline
 * @st: string to print
 * return: void
 *
*/
int _put(char *st)
{

char *c = st;

while (*st)
put_char(*st++);
return(st - c);

}

/**
 * put_char - writes the char y to stdout
 * @y: the char to print
 * Return: 1 if success, -1 if error
 *
*/
int put_char(int y)
{
static int l;
static char  buf[OUTPUT_BUF_SIZE];
if (y == BUF_FLUSH || l >= OUTPUT_BUF_SIZE)
{
write(1, buf, l);
l = 0;
}
if (y != BUF_FLUSH)
buf[l++] = y;
return (1);
}
