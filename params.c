#include "main.h"
/**
 * init_z - clears struct fields and reset buf
 * @z: the parameters struct
 * @l: the argument pointer
 *
 * Return: void
 *
*/
void init_z(flags_t *z, va_list l)
{
z->unsign = 0;
z->p_f = 0;
z->s_f = 0;
z->hash_f = 0;
z->z_f = 0;
z->minus_f = 0;
z->width = 0;
z->precision = UINT_MAX;
z->h_modifier = 0;
z->l_modifier = 0;
(void)l;
}
