/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:49:58 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/09/13 16:06:33 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

void	print_instructions(void)
{
	printf("\t\tWRONG INPUT!\n\n");
}

int	is_digit(int ac, char **av)
{
	int	i;
	int	k;

	i = 1;
	while (i < ac)
	{
		k = 0;
		while (av[i][k] != '\0')
		{
			if (av[i][k] < '0' || av[i][k] > '9')
				return (WRONG_INPUT);
			k++;
		}
		i++;
	}
	return (0);
}

int	check_inputs(int ac, char **av)
{
	if (ac != 5 && ac != 6)
		return (WRONG_INPUT);
	if (is_digit(ac, av) != 0)
		return (WRONG_INPUT);
	return (0);
}
