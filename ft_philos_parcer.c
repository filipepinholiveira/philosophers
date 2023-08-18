/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philos_parcer.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/18 15:55:13 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/08/18 17:45:07 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


int	ft_check_nbr(char *av)
{
	int i;
	i = 0;
	while (av[i])
	{
		if ((av[i] >= '0' && av[i] <= '9'))
			i++;
		else
		{
			ft_printf("Error\nInvalid argument\n");
			return (1);
		}
	}
	return (0);
}


int	ft_philos_parcer(char **av, int args)
{
	int i = 1;
	while (i <= args)
	{
		if (ft_check_nbr(av[i]) == 1)
			return (1);
		i++;
	}
	// av[1] = number_of_philosopher;
	// av[2] = time_to_die; 
	// av[3] = time_to_eat;
	// av[4] = ime_to_sleep;
	// av[5] = number_of_times_each_philosopher_must_eat;
	return (0);
}