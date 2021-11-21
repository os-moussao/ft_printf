/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:54:39 by omoussao          #+#    #+#             */
/*   Updated: 2021/11/21 19:34:08 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

/**
 *
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
 *		. : precision / max-width
 *		# : add 0x prefix in hex (%#x/%#X)
 *		+ > space
 *		width > precision (if precision (max) is less than width (min))
 **/

int	specifier(char *pt)
{
	if (pt[0] == '%')
	{
		if (pt[1] == 'c')
			return (1);
		if (pt[1] == 's')
			return (2);
	//	if (pt[1] == 'p')
	//		return (3);
		if (pt[1] == 'd')
			return (4);
	}
	return (0);
}

int	ft_printf(const char *fmt, ...)
{
	va_list	ap;
	int		sp;
	// int		print_last = 0;
	int		i = 0;
	int		d;
	char	c;
	char	*s;
	// void	*p;

	va_start(ap, fmt);
	while (fmt[i])
	{
		if (!fmt[i + 1])
		{
			ft_putchar_fd(fmt[i], 1);
			break ;
		}
		sp = specifier((char *)fmt + i);
		if (sp == 1)
		{
			c = (char)va_arg(ap, int);
			ft_putchar_fd(c, 1);
			i++;
		}
		else if (sp == 2)
		{
			s = va_arg(ap, char *);
			ft_putstr_fd(s, 1);
			i++;
		}
//		else if (sp == 3)
//		{
//			p = va_arg(ap, void *);
//			ft_putnbr_fd((int)p, 1);
//		}
		else if (sp == 4)
		{
			d = va_arg(ap, int);
			ft_putnbr_fd(d, 1);
			i++;
		}
		else
			ft_putchar_fd(fmt[i], 1);
		i++;
	}
	va_end(ap);
	return (0);
}
