/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:43:00 by omoussao          #+#    #+#             */
/*   Updated: 2021/11/22 21:10:19 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>

# define LL long long
# define ULL unsigned long long
# define LHEX "0123456789abcdef"
# define UHEX "0123456789ABCDEF"
# define HEX_RADIX 16
# define MIN_WIDTH 'w'
# define PRECISION 'p'

typedef struct s_style
{
	char	specifier;
	int		min_width; // width feild
	int		max_width; // precision
	int		len; // final length inc. width ans str/num length
	char	leading_char; // spaces or zeros
	char	sign; // ' ' or  '+' or '-'
	char	hex; // 'x' or 'X'
	bool	left_justify; // the minus flag
	bool	hash; // 0 or 1
}				t_style;

# define LL long long
# define ULL unsigned long long
# define LHEX "0123456789abcdef"
# define UHEX "0123456789ABCDEF"
# define HEX_RADIX 16

#endif
