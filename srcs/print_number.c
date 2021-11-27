/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 23:42:24 by omoussao          #+#    #+#             */
/*   Updated: 2021/11/27 03:18:26 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

#include <stdio.h>
// get number size
// alloc
// copy
// print
// free
// for now work only on decimal
int	print_number(t_arg_data data, va_list ap)
{
	unsigned int	flags;
	char			sp;
	int				sign_size;
	char			sign;
	int				abs_size;
	int				size;
	char			*arg;
	long long		nbr;
	long long		n;
	int				radix = 10;

	nbr = (long long) va_arg(ap, int);
	n = nbr;
	// printf("%lld	%lld\n", nbr, n);

	sp = data.specifier;
	flags = data.flags;

	if (nbr < 0 || sp == 'x' || sp == 'X' || sp == 'p')
		flags &= ~(SPACE | PLUS);
	if (flags & PLUS)
		flags &= ~SPACE;
	if (data.precision >= 0 || flags & LEFT_JUSTIFY)
		flags &= ~ZERO_PAD;

	// printf("\ndebug: space flag is %s\n", (flags & SPACE)? "on": "off");

	sign_size = (nbr < 0) || (flags & PLUS) || (flags & SPACE);

	sign = '-' * (nbr < 0) + '+' * ((flags & PLUS) != 0)
		+ ' ' * ((flags & SPACE) != 0);

	// len = max( max(abs_size, precision) , width) + has_sign;
	
	if (n < 0)
	{
		n*= -1;
		nbr *= -1;
	}

	abs_size = (n == 0);
	while (n)
	{
		n /= radix;
		abs_size++;
	}

	int nbr_size = max(abs_size, data.precision) + sign_size;
	size = max(nbr_size, data.width);
	int pad_size = size - nbr_size;
	
	arg = malloc(size);
	if (!arg)
		return (-1);

	// set padding
	if (flags & ZERO_PAD)
	{
		// set sign
		ft_memset(arg, sign, sign_size);

		// pad with zeros
		ft_memset(arg + 1, '0', pad_size);
	}
	else
	{
		// pad with spaces
		ft_memset(arg, ' ', pad_size);

		// set sign
		ft_memset(arg + pad_size, sign, sign_size);

		// set 0's if the precision > abs_size
		if (data.precision > abs_size)
			ft_memset(arg + pad_size + sign_size, '0', data.precision - abs_size);
	}

	// set number
	if (nbr == 0)
		arg[size - 1] = '0';
	int i = size - 1;
	while (nbr)
	{
		arg[i--] = (nbr % radix) + '0';
		nbr /= radix;
	}

	// apply LEFT_JUSTIFY flag
	if (flags & LEFT_JUSTIFY)
		left_rotate(arg, size, pad_size);

	write(1, arg, size);
	free(arg);

	return (size);
}
