/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:15:57 by omoussao          #+#    #+#             */
/*   Updated: 2021/11/22 17:05:08 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putstr(const char *str)
{
	int	i;

	if (!str)
		return (0);
	i = 0;
	while (str[i])
		write(1, str + i++, 1);
	return (i);
}

int	ft_putchar(const char c)
{
	return (write(1, &c, 1));
}

int	ft_putnbr(LL nbr)
{
	int count;

	count = 0;
	if (nbr < 0)
	{
		count += ft_putchar('-');
		nbr *= -1;
	}
	if (nbr >= 10)
		count += ft_putnbr(nbr / 10);
	count += ft_putchar(nbr % 10 + '0');
	return (count);
}

int	print_hex(ULL nbr, char option, len)
{
	int	count;

	count = 0;
	if (nbr >= HEX_RADIX)
		count += printf_hex(nbr / HEX_RADIX, option);
	if (option == 'x')
		count += ft_putchar(LHEX[nbr % HEX_RADIX]);
	else
		count += ft_putchar(UHEX[nbr % HEX_RADIX]);
	return (count);
}



/*
int	ft_putstr_l(const char *str, int len)
{
	return (write(1, str, len));
}
*/
