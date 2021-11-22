/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:54:39 by omoussao          #+#    #+#             */
/*   Updated: 2021/11/22 18:53:49 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 * todo:
 * 	1-
 * 		understand variadic functions
 * 		understand these flags: - 0 . # +  space
 * 		understand width
 * 		make a simple version of printf that handle flags and width
 *	
 *	2-
 * 		test test test: detect special cases, combinations, and errors
 * 		fix code
 * 		redo
 *
 *	3- more stuff:
 *		take care of  printig negative hex values
 *
 *
 *
 *
 * 		- : left justify
 *		+ : display + sign when the number is positive
 *		space : display hidden sign when the number is positive
 *		0 : pad with leading zeros
 *		. : precision / max-width + leading zeros
 *		# : add 0x prefix in hex (%#x/%#X)
 *
 *		combinations of "0-.":
 *			flag '0' is ignored when flag '-' is present
 *
 *
 *		+ > space
 *		width > precision (if precision (max) is less than width (min))
 **/

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		i;
	int		count;
	
	i = 0;
	count = 0;
	va_start(ap, fmt);
	while (fmt[i])
	{
		if (fmt[i] != '%')
		{
			count += write(1, fmt + i, 1);
			continue ;
		}
		else
		{
			// check flags
			// move to width
			// move to precision
			// handle specifier
			// back to normal
		}
	}
	va_end(ap);
	return (0);
}
