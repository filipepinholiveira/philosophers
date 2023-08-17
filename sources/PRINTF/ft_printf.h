/* ************************************************************************** */
/*																			*/
/*														:::	  ::::::::   */
/*   ft_printf.h										:+:	  :+:	:+:   */
/*													+:+ +:+		 +:+	 */
/*   By: fpinho-d <fpinho-d@student.42.fr>		  +#+  +:+	   +#+		*/
/*												+#+#+#+#+#+   +#+		   */
/*   Created: 2023/01/23 16:09:38 by fpinho-d		  #+#	#+#			 */
/*   Updated: 2023/01/23 18:45:47 by fpinho-d		 ###   ########.fr	   */
/*																			*/
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# define MIN_INT -2147483648
# define BASE_LOWER "0123456789abcdef"
# define BASE_UPPER "0123456789ABCDEF"

# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

int	ft_printf(const char *conteudo, ...);
int	ft_putchar(char c);
int	ft_putstr(char *str);
int	ft_putnbr(int x);
int	ft_count(int a);
int	ft_count_hexa_ptr(size_t a);
int	ft_putnbr_u(unsigned int x);
int	ft_count_u(unsigned int a);
int	ft_putnbr_hexa(size_t x, char *base);
int	ft_putnbr_hexa_ptr(size_t x, char *base);

#endif