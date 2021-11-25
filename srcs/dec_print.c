/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dec_print.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 18:33:42 by omoussao          #+#    #+#             */
/*   Updated: 2021/11/23 20:38:27 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

typedef struct sstyle
{
	char	*arg;
	char	specifier;
	int		min_width;
	int		precision;
	char	leading_char;
	char	sign;
	bool	left_justify;
	bool	hash;
}				tstyle;

typedef	struct s_nbr_style
{
	int	base;
	int	length;
	int	size;
	int	zeros;
	int	sign;
	int	spaces;
}				t_nbr_style;

	/* zab ila fhamty had lcode */
void	get_dec_style(t_style style, t_nbr_style *nbr_style, int nbr)
{
	int	window_len;

	nbr_style->size = get_nbr_size(nbr, 10);

	if (style.precision >= nbr_style->size)
		nbr_style->zeros = style.precision - nbr_style->size;
	else
		nbr_style->zeros = 0;


	if (nbr < 0 || style.sign != '-')
		nbr_style->sign = 1;
	else
		nbr_style->sign = 0;

	window_len = nbr_style->size + nbr_style->zeros + nbr_style->sign;

	nbr_style->spaces = max(style.min_width, window_len) - window_len;

	nbr_style->length = window_length + nbr_style->spaces;
}

int	dec_print(t_style style, va_list ap)
{
	int	nbr;
	
	nbr = va_arg(ap, int);
}
