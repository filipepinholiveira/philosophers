/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_putnbr.c										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: fpinho-d <fpinho-d@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/01/23 17:08:08 by fpinho-d		  #+#	#+#			 */
/*   Updated: 2023/01/23 17:35:40 by fpinho-d		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_count(int a)
{
	int	len;

	len = 0;
	if (a < 0)
	{
		len++;
		a = -a;
	}
	if (a == 0)
		return (1);
	while (a)
	{
		a = a / 10;
		len++;
	}
	return (len);
}

int	ft_putnbr(int x)
{
	int	len;

	len = ft_count(x);
	if (x == MIN_INT)
	{
		ft_putchar('-');
		ft_putchar('2');
		x = 147483648;
	}
	if (x < 0)
	{
		ft_putchar('-');
		x = -x;
	}
	if (x > 9)
	{
		ft_putnbr(x / 10);
		ft_putnbr(x % 10);
	}
	else
		ft_putchar(x + '0');
	return (len);
}
