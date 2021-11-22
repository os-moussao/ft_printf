/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   flags.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/22 18:28:35 by omoussao          #+#    #+#             */
/*   Updated: 2021/11/22 21:02:31 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

bool	is_flag(char c)
{
	return (c == '0' || c == '-' || c == '#'
		|| c == ' ' || c == '+');
}

bool	style_init(t_style **style)
{
	*style = malloc(sizeof(style));
	if (!*style)
		return (false);
	(*style)->min_width = 0;
	(*style)->precision = 0;
	(*style)->length = 0;
	(*style)->sign = '-';
	(*style)->leading_char = ' ';
	(*style)->left_justify = false;
	(*style)->hash = false;
	return (true);
}

void	get_width_type(t_style *style, char *fmt, int *ptr, char type)
{
	int	width;

	width = 0;
	while (fmt[*ptr] >= '0' && fmt[*ptr] <= '9')
		width = width * 10 + fmt[(*ptr)++] - '0';
	if (type == MIN_WIDTH)
		(*style)->min_width = width;
	else
		(*style)->precision = width;
}

void	get_style(t_style **style, char *fmt, int *ptr)
{
	char	c;

	while (is_flag(fmt[*ptr]))
	{
		c = fmt[(*ptr)++];
		if (c == '0')
			(*style)->leading_char = '0';
		else if (c == '-')
			(*style)->left_justify = true;
		else if (c == '#')
			(*style)->hash = true;
		else if (c == ' ' && style->sign != '+')
			(*style)->sign = ' ';
		else if (c == '+')
			(*style)->sign = '+';
	}
	get_width_type(style, fmt, ptr, MIN_WIDTH);
	if (fmt[(*ptr)++] == '.')
		get_width_type(style, fmt, ptr, PRECISION);
	(*style)->specifier = fmt[(*ptr)++];
}

void	update_style(t_style **style)
{
	
}
