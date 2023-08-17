/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:52:59 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/08/17 18:12:29 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


void *routine(void *arg)
{	
	(void) arg;
	int k = 0;
	while (k < 5)
	{
		//pthread_mutex_lock(&mutex);
		printf("Eat\n");
		//count++;
		//pthread_mutex_unlock(&mutex);
		k++;
	}
	return (0);
}

data_t *init_data()
{
	data_t *philos;
	philos = malloc (sizeof(data_t));
	if (!philos)
		return (NULL);
	pthread_create(&philos->philos, NULL, routine, philos);
	pthread_mutex_init(&philos->o_meu_garfo, NULL);
//	free (philos);
	return philos;
}



int	main(int ac, char **av)
{
	(void) ac;
	(void) av;
	int k;

	if (ac == 1)
		return (1);
	k = ft_atoi(av[1]);
	data_t *philos[k];
	int i = 0;
	
	while (i < k)
	{
		philos[i] = init_data();
		ft_printf("Filosofo numero %d pronto\n", i + 1);
		i++;
	}
	
	return (0);
}