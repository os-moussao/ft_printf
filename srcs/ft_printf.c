/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:54:39 by omoussao          #+#    #+#             */
/*   Updated: 2021/11/23 00:33:32 by omoussao         ###   ########.fr       */
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

typedef struct sstyle
{
	char	specifier;
	char	*varg;
	int		min_width; // width feild
	int		precision; // precision
	int		lenght; // final length inc. width ans str/num length
	char	leading_char; // spaces or zeros
	char	sign; // ' ' or  '+' or '-'
	bool	left_justify; // the minus flag
	bool	hash; // 0 or 1
}				sstyle;

int	ft_print_varg(t_style style, va_list ap)
{
	char	sp;

	sp = style->specifier;
}

int	ft_print(const char *fmt, va_list ap)
{
	int		ret;
	int		ptr;
	t_style	style;

	ptr = 0;
	ret = 0;
	while (fmt[ptr])
	{
		if (fmt[ptr] != '%')
			ret += write(1, fmt + ptr++, 1);
		else
		{
			get_style(&style, fmt, &(++i));
			ret += ft_print_varg(style, ap);
		}
	}
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = f_printf(format, ap);
	va_end(ap);
	return (ret);
}
