/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:20:26 by omoussao          #+#    #+#             */
/*   Updated: 2021/11/29 21:14:41 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static int	out(t_arg_data data, const char *str, int len)
{
	int		window_len;
	char	*out;

	window_len = len;
	if (data.precision >= 0)
		window_len = min(len, data.precision);
	len = max(window_len, data.width);
	if (!len)
		return (len);
	out = malloc(len);
	if (!out)
		return (-1);
	if (data.flags & LEFT_JUSTIFY)
	{
		ft_memcpy(out, str, window_len);
		ft_memset(out + window_len, ' ', len - window_len);
	}
	else
	{
		ft_memset(out, ' ', len - window_len);
		ft_memcpy(out + len - window_len, str, window_len);
	}
	write(1, out, len);
	free(out);
	return (len);
}

int	print_string(t_arg_data data, va_list ap)
{
	char	*str;
	char	c;
	int		len;

	if (data.specifier == 's')
	{
		str = va_arg(ap, char *);
		if (!str)
			str = "(null)";
		len = ft_strlen(str);
	}
	else
	{
		if (data.specifier == 'c')
			c = (char)va_arg(ap, int);
		else
			c = data.specifier;
		str = &c;
		len = 1;
	}
	return (out(data, str, len));
}
