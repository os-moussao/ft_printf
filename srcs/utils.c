/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/23 13:15:45 by omoussao          #+#    #+#             */
/*   Updated: 2021/11/27 03:38:36 by omoussao         ###   ########.fr       */
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

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	size_t	i;

	i = -1;
	if (dest > src)
		while (n--)
			*(char *)(dest + n) = *(char *)(src + n);
	else if (dest < src)
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

/**
 * This function rotates an array to the left by d elements
 * it is mostly used with the flag LEFT_JUSTIFY
 **/
void	left_rotate(char *arr, int size, int d)
{
	char	tmp;
	int		i;

	while (d--)
	{
		tmp = arr[0];
		i = 0;
		while (i + 1 < size)
		{
			arr[i] = arr[i + 1];
			i++;
		}
		arr[i] = tmp;
	}
}

int	get_nbr_size(long long nbr, int base)
{
	int	size;

	if (nbr == 0)
		return (1);
	size = 0;
	while (nbr)
	{
		size++;
		nbr /= base;
	}
	return (size);
}

/*
char	*ft_memdup(const void *src, int n)
{
	char	*dup;

	dup = malloc(n);
	if (!dup)
		return (NULL);
	ft_memmove(dup, src, n);
	return (dup);
}
*/

