/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:52:59 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/08/20 18:21:38 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


// ph[0] - ph[4]

// while(5)

// 	if (i < 5 - 1)
// 		ph[i].garfo = &ph[i + 1].gf
// 	else
// 		ph[i].garfo = &ph[0].gf

void *routine(void *philos)
{	
	data_t *ph;

	ph = (data_t *)philos;
	pthread_mutex_lock(&ph->o_meu_garfo);
	printf("Filisofo: %d, Eat\n", ph->id_philos);
	pthread_mutex_unlock(&ph->o_meu_garfo);
	return (0);
}

void	init_philos (int philos_nbr)
{
	data_t *philos;
	int i;
	
	philos = malloc (sizeof(data_t) * philos_nbr);
	if (!philos)
		return ;
	i = 0;
	while (i < philos_nbr)
	{
		philos[i].id_philos = i + 1;
		pthread_mutex_init(&philos[i].o_meu_garfo, NULL);
		pthread_create(&philos[i].philos, NULL, routine, ((void *)&philos[i]));
		i++;
	}
	i = 0;
	while (i < philos_nbr)
	{
		pthread_join(philos[i].philos, NULL);
		i++;
	}
	pthread_mutex_destroy(&philos[i].o_meu_garfo);
}

int	main(int ac, char **av)
{
	(void) ac;
	(void) av;

	if (ac < 6 || ac > 7)
		return (1);
	if (ft_philos_parcer(av, ac - 1) == 1)
		return (1);
	init_philos(ac - 1);
	return (0);
}