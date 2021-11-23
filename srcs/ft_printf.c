/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:54:39 by omoussao          #+#    #+#             */
/*   Updated: 2021/11/23 16:57:29 by omoussao         ###   ########.fr       */
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
 *
 *
 *		don't forget to handle unknown specifier --> 2 cases: random char - empthy str
 **/

typedef struct sstring
{
	char	*str;
	int		len;
}				sstring;

typedef struct sstyle
{
	string	string;
	char		specifier;
	int			min_width; // width feild
	int			precision; // precision
	char		leading_char; // spaces or zeros
	char		sign; // ' ' or  '+' or '-'
	bool		left_justify; // the minus flag
	bool		hash; // 0 or 1
}				sstyle;

#include <stdio.h>
int	str_print(t_style style, va_list ap)
{
	char	*str;
	char	c;
	int		len;
	int		window_len;

	if (style.specifier == 's')
	{
		str = va_arg(ap, char *);
		len = ft_strlen(str);
	}
	else
	{
		c = (char)va_arg(ap, int);
		str = &c;
		len = 1;
	}
	if (style.precision >= 0)
		window_len = min(len, style.precision);
	else
		window_len = len;
	len = max(window_len, style.min_width);
	style.sarg.str = malloc(len);
	if (!style.sarg.str)
		return (-1);
	if (style.left_justify)
	{
		ft_memcpy(style.sarg.str, str, window_len);
		ft_memset(style.sarg.str + window_len, ' ', len - window_len);
	}
	else
	{
		ft_memset(style.sarg.str, ' ', len - window_len);
		ft_memcpy(style.sarg.str + len - window_len, str, window_len);
	}
	if (write(1, style.sarg.str, len) == -1)
		return (-1);
	free(style.sarg.str);
	return (len);
}

int	arg_print(t_style style, va_list ap)
{
	char	sp;
	int		ret;
	int		tmp;

	ret = 0;
	sp = style.specifier;
	if (sp == 's' || sp == 'c')
	{
		tmp = str_print(style, ap);
		if (tmp == -1)
			return (-1);
		ret += tmp;
	}
	/*
	else if (sp == 'd' || sp == 'i')
		ret += dec_print(style, ap);
	...
	*/
	return (ret);
}

int	fmt_print(const char *fmt, va_list ap)
{
	int		ret;
	int		ptr;
	int		tmp;
	t_style	style;

	ptr = 0;
	ret = 0;
	while (fmt[ptr])
	{
		if (fmt[ptr] != '%')
		{
			if (write(1, fmt + ptr++, 1) == -1)
				return (-1);
			ret++;
		}
		else
		{
			get_style(&style, fmt, &ptr);
			tmp = arg_print(style, ap);
			if (tmp == -1)
				return (-1);
			ret += tmp;
		}
	}
	return (ret);
}

int	ft_printf(const char *format, ...)
{
	va_list	ap;
	int		ret;

	va_start(ap, format);
	ret = fmt_print(format, ap);
	va_end(ap);
	return (ret);
}
