/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:43:00 by omoussao          #+#    #+#             */
/*   Updated: 2021/11/23 16:30:01 by omoussao         ###   ########.fr       */
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

typedef struct s_string
{
	char	*str;
	int		len;
}				string;

typedef struct s_style
{
	string		sarg;
	char		specifier;
	int			min_width; // width feild
	int			precision; // precision
	char		leading_char; // spaces or zeros
	char		sign; // ' ' or  '+' or '-'
	bool		left_justify; // the minus flag
	bool		hash; // 0 or 1
}				t_style;

void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		max(int a, int b);
int		min(int a, int b);
int		ft_strlen(const char *str);
void	get_style(t_style *style, const char *fmt, int *ptr);

int	ft_printf(const char *format, ...);

#endif
