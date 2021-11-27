/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:54:39 by omoussao          #+#    #+#             */
/*   Updated: 2021/11/27 03:06:37 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	arg_print(t_arg_data data, va_list ap)
{
	char	sp;
	int		ret;
	int		tmp;

	ret = 0;
	sp = data.specifier;
	if (sp == 's' || sp == 'c')
	{
		tmp = str_print(data, ap);
		if (tmp == -1)
			return (-1);
		ret += tmp;
	}
	else if (sp == 'd' || sp == 'i' || sp == 'u'
		|| sp == 'x' || sp == 'X' || sp == 'p')
	{
		tmp = print_number(data, ap);
		if (tmp == -1)
			return (-1);
		ret += tmp;
	}
	/*
	else
	{
		// if sp == '%' or a random character
	}
	*/
	return (ret);
}

int	fmt_print(const char *fmt, va_list ap)
{
	int			ret;
	int			tmp;
	t_arg_data	data;

	ret = 0;
	while (*fmt)
	{
		if (*fmt != '%')
		{
			write(1, fmt++, 1);
			ret++;
		}
		else
		{
			get_arg_data(&data, &fmt);
			tmp = arg_print(data, ap);
			if (tmp == -1)
				return (-1);
			ret += tmp;
			if (!*fmt)
				break ;
			fmt++;
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
