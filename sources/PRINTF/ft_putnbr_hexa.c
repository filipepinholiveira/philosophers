/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_hexa.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/25 18:29:28 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/01/26 18:18:30 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_hexa(size_t a)
{
	int	len;

	len = 1;
	while (a > 15)
	{
		a = a / 16;
		len++;
	}
	return (len);
}

int	ft_putnbr_hexa(size_t x, char *base)
{
	int	len;

	len = ft_count_hexa(x);
	if (x > 15)
	{
		ft_putnbr_hexa(x / 16, base);
		ft_putnbr_hexa(x % 16, base);
	}
	else
		ft_putchar(base[x]);
	return (len);
}
