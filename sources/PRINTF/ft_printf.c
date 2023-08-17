/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*													+:+ +:+		 +:+	 */
/*   By: fpinho-d <fpinho-d@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/01/23 15:39:06 by fpinho-d		  #+#	#+#			 */
/*   Updated: 2023/01/26 18:30:20 by fpinho-d         ###   ########.fr       */
/*																			*/
/* ************************************************************************** */

#include "ft_printf.h"

int	ft_print_arg(va_list arg, char c)
{
	int	len;

	len = 0;
	if (c == 'c')
		len += ft_putchar(va_arg(arg, int));
	if (c == 's')
		len += ft_putstr(va_arg(arg, char *));
	if ((c == 'd') || (c == 'i'))
		len += ft_putnbr(va_arg(arg, int));
	if (c == 'u')
		len += ft_putnbr_u(va_arg(arg, unsigned int));
	if (c == 'x')
		len += ft_putnbr_hexa(va_arg(arg, unsigned int), "0123456789abcdef");
	if (c == 'X')
		len += ft_putnbr_hexa(va_arg(arg, unsigned int), "0123456789ABCDEF");
	if (c == '%')
		len += ft_putchar('%');
	if (c == 'p')
		len += ft_putnbr_hexa_ptr(va_arg(arg, size_t), "0123456789abcdef");
	return (len);
}

int	ft_printf(const char *conteudo, ...)
{
	va_list	arg;
	int		i;
	int		retorno;

	va_start (arg, conteudo);
	i = 0;
	retorno = 0;
	while (conteudo[i])
	{
		if (conteudo[i] == '%')
		{
			i++;
			retorno += ft_print_arg(arg, conteudo[i]);
		}
		else
			retorno += ft_putchar(conteudo[i]);
		i++;
	}
	va_end (arg);
	return (retorno);
}
/* 
int main()
{
	char a = 'D';
	char b [] = "(null)";
	char c [] = "Filipe";
	int d = -10;
	unsigned int	e = 255;
	 
	printf("Original: %c %s %s %d %u %x\n", a, b, c, d, e, e);
	ft_printf("      Meu: %c %s %s %d %u\n", a, b, c, d, e);
}
 */
