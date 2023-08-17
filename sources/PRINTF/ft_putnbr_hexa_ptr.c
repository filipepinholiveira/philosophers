/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa_ptr.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/26 16:12:43 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/01/26 18:16:53 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_putnbr_hexa_ptr(size_t x, char *base)
{
	int	len;

	if (x == 0)
		return (write(1, "(nil)", 5));
	ft_putstr("0x");
	len = ft_putnbr_hexa(x, base);
	return (len + 2);
}
