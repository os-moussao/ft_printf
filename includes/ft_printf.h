/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 15:43:00 by omoussao          #+#    #+#             */
/*   Updated: 2021/11/29 14:09:35 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

/**
 * includes
 **/
# include <unistd.h>
# include <stdlib.h>
# include <stdarg.h>
# include <stdbool.h>

/**
 * defines
 **/
# define LHEX "0123456789abcdef"
# define UHEX "0123456789ABCDEF"
# define HEX_RADIX 16

# define ZERO_PAD		1U
# define LEFT_JUSTIFY	2U
# define PLUS			4U
# define SPACE			8U
# define HASH			16U

/**
 * argument structure
 **/
typedef struct s_arg_data
{
	unsigned int	flags;
	char			specifier;
	int				width;
	int				precision;
}				t_arg_data;

/**
 * helper functions
 **/
void	*ft_memset(void *b, int c, size_t len);
void	*ft_memcpy(void *dest, const void *src, size_t n);
void	left_rotate(char *arr, int size, int d);
int		ft_strlen(const char *str);
int		max(int a, int b);
int		min(int a, int b);

/**
 * function to extract flags, width, precision and specifier from format string
 **/
void	get_arg_data(t_arg_data *data, const char **fmt);

/**
 * argument printing
 **/
int		print_string(t_arg_data data, va_list ap);
int		print_number(t_arg_data data, va_list ap);

/**
 * mandatory function
 **/
int		ft_printf(const char *format, ...);

#endif
