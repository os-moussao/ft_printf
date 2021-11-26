/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:28:35 by omoussao          #+#    #+#             */
/*   Updated: 2021/11/26 23:37:32 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static bool	is_flag(char c)
{
	return (c == '0' || c == '-' || c == '#'
		|| c == ' ' || c == '+');
}

static void	data_init(t_arg_data *data)
{
	data->flags = 0U;
	data->width = 0;
	data->precision = -1;
}

static int	fmt_atoi(const char **fmt)
{
	int	res;

	res = 0;
	while (**fmt >= '0' && **fmt <= '9')
		res = res * 10 + *(*fmt)++ - '0';
	return (res);
}

void	get_arg_data(t_arg_data *data, const char **fmt)
{
	char	c;

	(*fmt)++;
	data_init(data);
	while (is_flag(**fmt))
	{
		c = *(*fmt)++;
		if (c == '0')
			data->flags |= ZERO_PAD;
		else if (c == '-')
			data->flags |= LEFT_JUSTIFY;
		else if (c == '#')
			data->flags |= HASH;
		else if (c == ' ' && (data->flags & PLUS))
			data->flags |= SPACE;
		else if (c == '+')
			data->flags |= PLUS;
	}
	data->width = fmt_atoi(fmt);
	if (**fmt == '.')
	{
		(*fmt)++;
		data->precision = fmt_atoi(fmt);
	}
	data->specifier = **fmt;
}
