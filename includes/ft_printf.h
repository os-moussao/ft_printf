/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:43:00 by omoussao          #+#    #+#             */
/*   Updated: 2021/11/23 18:31:25 by omoussao         ###   ########.fr       */
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

/**
 * argument structure
 **/
typedef struct s_style
{
	char	*arg;
	char	specifier;
	int		min_width;
	int		precision;
	char	leading_char;
	char	sign;
	bool	left_justify;
	bool	hash;
}				t_style;

/**
 * helper functions
 **/
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t n);
int		ft_strlen(const char *str);
int		max(int a, int b);
int		min(int a, int b);

/**
 * style function
 **/
void	get_style(t_style *style, const char *fmt, int *ptr);

/**
 * argument printing
 **/
int		str_print(t_style style, va_list ap);

/**
 * mandatory function
 **/
int		ft_printf(const char *format, ...);

#endif
