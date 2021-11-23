/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:20:26 by omoussao          #+#    #+#             */
/*   Updated: 2021/11/23 18:21:17 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

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
	style.arg = malloc(len);
	if (!style.arg)
		return (-1);
	if (style.left_justify)
	{
		ft_memcpy(style.arg, str, window_len);
		ft_memset(style.arg + window_len, ' ', len - window_len);
	}
	else
	{
		ft_memset(style.arg, ' ', len - window_len);
		ft_memcpy(style.arg + len - window_len, str, window_len);
	}
	if (write(1, style.arg, len) == -1)
		return (-1);
	free(style.arg);
	return (len);
}
