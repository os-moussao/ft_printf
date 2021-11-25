/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 23:42:24 by omoussao          #+#    #+#             */
/*   Updated: 2021/11/25 23:56:02 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	_itoi(t_arg_data data, long long n)
{

}

int	print_number(t_arg_data data, va_list ap)
{
	char	sp;

	sp = data.specifier;
	if (sp == 'x' || sp == 'X' || sp == 'p')
		data.flags &= ~(SPACE | PLUS);
	if (dada.precision >= 0)
		data.flags &= ~ZERO_PAD;
}
