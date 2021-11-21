/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: omoussao <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/20 15:54:39 by omoussao          #+#    #+#             */
/*   Updated: 2021/11/21 15:49:51 by omoussao         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 *
 * todo:
 * 	1-
 * 		understand variadic functions
 * 		understand these flags: - 0 . # +  space
 * 		understand width
 * 		make a simple version of printf that handle flags and width
 *	
 *	2-
 * 		test test test: detect special cases, combinations, and errors
 * 		fix code
 * 		redo
 *
 *	3- more stuff:
 *		take care of  printig negative hex values
 *
 *
 *
 *
 * 		- : left justify
 *		+ : display + sign when the number is positive
 *		space : display hidden sign when the number is positive
 *		0 : pad with leading zeros
 *		. : precision
 *		# : add 0x prefix in hex (%#x/%#X)
 *		+ > space
 **/

