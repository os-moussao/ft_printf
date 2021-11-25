/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:54:39 by omoussao          #+#    #+#             */
/*   Updated: 2021/11/25 15:13:13 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
