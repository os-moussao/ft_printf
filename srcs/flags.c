/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:28:35 by omoussao          #+#    #+#             */
/*   Updated: 2021/11/23 16:58:55 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

static bool	is_flag(char c)
{
	return (c == '0' || c == '-' || c == '#'
		|| c == ' ' || c == '+');
}

static void	style_init(t_style *style)
{
	style->min_width = 0;
	style->precision = -1;
	style->leading_char = ' ';
	style->sign = '-';
	style->left_justify = false;
	style->hash = false;
}

static void	get_width_type(t_style *style, const char *fmt, int *ptr, char type)
{
	int	width;

	if (type == PRECISION)
		(*ptr)++;
	width = 0;
	while (fmt[*ptr] >= '0' && fmt[*ptr] <= '9')
		width = width * 10 + fmt[(*ptr)++] - '0';
	if (type == MIN_WIDTH)
		style->min_width = width;
	else
		style->precision = width;
}

void	get_style(t_style *style, const char *fmt, int *ptr)
{
	char	c;

	(*ptr)++;
	style_init(style);
	while (is_flag(fmt[*ptr]))
	{
		c = fmt[(*ptr)++];
		if (c == '0')
			style->leading_char = '0';
		else if (c == '-')
			style->left_justify = true;
		else if (c == '#')
			style->hash = true;
		else if (c == ' ' && style->sign != '+')
			style->sign = ' ';
		else if (c == '+')
			style->sign = '+';
	}
	get_width_type(style, fmt, ptr, MIN_WIDTH);
	if (fmt[*ptr] == '.')
		get_width_type(style, fmt, ptr, PRECISION);
	style->specifier = fmt[(*ptr)++];
}
