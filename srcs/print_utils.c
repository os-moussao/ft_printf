/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/21 18:15:57 by omoussao          #+#    #+#             */
/*   Updated: 2021/11/21 19:25:15 by omoussao         ###   ########.fr       */
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






/*
int	ft_putstr_l(const char *str, int len)
{
	return (write(1, str, len));
}
*/
