/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_string.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:20:26 by omoussao          #+#    #+#             */
/*   Updated: 2021/11/25 23:16:42 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	str_print(t_arg_data data, va_list ap)
{
	char	*out;
	char	*str;
	char	c;
	int		len;
	int		window_len;

	if (data.specifier == 's')
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
	if (data.precision >= 0)
		window_len = min(len, data.precision);
	else
		window_len = len;
	len = max(window_len, data.width);

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
	if (write(1, out, len) == -1)
		return (-1);
	free(out);
	return (len);
}
