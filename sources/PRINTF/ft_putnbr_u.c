/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_putnbr_u.c									  :+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: fpinho-d <fpinho-d@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/01/23 18:19:38 by fpinho-d		  #+#	#+#			 */
/*   Updated: 2023/01/23 18:26:21 by fpinho-d		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count_u(unsigned int a)
{
	int	len;

	len = 0;
	if (a == 0)
		return (1);
	while (a)
	{
		a = a / 10;
		len++;
	}
	return (len);
}

int	ft_putnbr_u(unsigned int x)
{
	int	len;

	len = ft_count_u(x);
	if (x > 9)
	{
		ft_putnbr_u(x / 10);
		ft_putnbr_u(x % 10);
	}
	else
		ft_putchar(x + '0');
	return (len);
}
