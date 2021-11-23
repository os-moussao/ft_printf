/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:15:45 by omoussao          #+#    #+#             */
/*   Updated: 2021/11/23 15:26:26 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_strlen(const char *str)
{
	int	len;

	len = 0;
	while (str[len])
		len++;
	return (len);
}

int	max(int a, int b)
{
	return ((a > b) * a + (a <= b) * b);
}

int	min(int a, int b)
{
	return ((a < b) * a + (a >= b) * b);
}

void	memcopy(void *dest, const void *src, int n)
{
	int	i;

	i = -1;
	while (++i < n)
		*(char *)(dest + i) = *(char *)(src + i);
}

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t	i;

	if (!dest && !src)
		return (NULL);
	i = -1;
	while (++i < n)
		*(char *)(dest + i) = *(char *)(src + i);
	return (dest);
}

void	*ft_memset(void *b, int c, size_t len)
{
	size_t	i;

	i = -1;
	while (++i < len)
		*(char *)(b + i) = (unsigned char)c;
	return (b);
}
