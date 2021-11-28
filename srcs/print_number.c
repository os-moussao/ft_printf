/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_number.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/25 23:42:24 by omoussao          #+#    #+#             */
/*   Updated: 2021/11/28 22:28:39 by omoussao         ###   ########.fr       */
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
	unsigned long	n;
	unsigned long	abs;
	int				radix = 10;
	int				nbr_size;
	int				pad_size;
	int				i;
	int				hash_prefix;


	sp = data.specifier;
	flags = data.flags;

	if (sp == 'd' || sp == 'i')
		nbr = va_arg(ap, int);
	else if (sp == 'u' || sp == 'x' || sp == 'X')
		nbr = va_arg(ap, unsigned int);
	else // if sp == 'p'
		abs = (unsigned long)va_arg(ap, void *);


	if (sp != 'p')
	{
		if (nbr < 0)
			abs = -nbr;
		else
			abs = nbr;
	}
	n = abs;

	if (sp == 'x' || sp == 'X' || sp == 'p')
		radix = 16;

	// printf("%lld	%lld\n", nbr, n);

	if (sp == 'x' || sp == 'X' || sp == 'p' || nbr < 0)
		flags &= ~(SPACE | PLUS);
	if (flags & PLUS)
		flags &= ~SPACE;
	if (data.precision >= 0 || flags & LEFT_JUSTIFY)
		flags &= ~ZERO_PAD;
	if (sp == 'd' || sp == 'i' || sp == 'u' || ((sp == 'x' || sp == 'X') && abs == 0))
		flags &= ~HASH;
	if (sp == 'p')
		flags |= HASH;

	// printf("\ndebug: space flag is %s\n", (flags & SPACE)? "on": "off");

	if (sp == 'd' || sp == 'i' || sp == 'u')
	{
		sign_size = (nbr < 0) || (flags & PLUS) || (flags & SPACE);

		sign = '-' * (nbr < 0) + '+' * ((flags & PLUS) != 0)
			+ ' ' * ((flags & SPACE) != 0);
	}
	else
		sign_size = sign = 0;

	// len = max( max(abs_size, precision) , width) + has_sign;
	
	/*
	if (n < 0)
	{
		n*= -1;
		nbr *= -1;
	}
	*/

	// abs_size = (n == 0) && (data.precision < 0);
	abs_size = (n == 0) && (data.precision != 0);
	while (n)
	{
		n /= radix;
		abs_size++;
	}

	hash_prefix = 2 * ((flags & HASH) != 0);
	nbr_size = max(abs_size, data.precision) + sign_size + hash_prefix;
	size = max(nbr_size, data.width);
	pad_size = size - nbr_size;
	
	if (!size)
		return (size);
	arg = malloc(size);
	if (!arg)
		return (-1);

	// set padding
	if (flags & ZERO_PAD)
	{
		// set sign
		ft_memset(arg, sign, sign_size);

		if (hash_prefix)
		{
			arg[0] = '0';
			arg[1] = 'x' * (sp != 'X') + 'X' * (sp == 'X');
		}

		// pad with zeros
		ft_memset(arg + sign_size + hash_prefix, '0', pad_size);
	}
	else
	{
		// pad with spaces
		ft_memset(arg, ' ', pad_size);

		// set sign
		ft_memset(arg + pad_size, sign, sign_size);

		if (hash_prefix)
		{
			arg[pad_size] = '0';
			arg[pad_size + 1] = 'x' * (sp != 'X') + 'X' * (sp == 'X');;
		}

		// set 0's if the precision > abs_size
		if (data.precision > abs_size)
			ft_memset(arg + pad_size + sign_size + hash_prefix,
				'0', data.precision - abs_size);
	}

	// set number
	if (abs == 0 && (data.precision != 0))
		arg[size - 1] = '0';
	i = size - 1;
	while (abs)
	{
		arg[i--] = LHEX[abs % radix] * (sp != 'X') + UHEX[abs % radix] * (sp == 'X');
		abs /= radix;
	}

	// apply LEFT_JUSTIFY flag
	if (flags & LEFT_JUSTIFY)
		left_rotate(arg, size, pad_size);

	write(1, arg, size);
	free(arg);

	return (size);
}
