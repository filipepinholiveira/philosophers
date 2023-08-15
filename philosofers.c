/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosofers.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/17 16:52:59 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/08/15 17:54:14 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


void *routine(data_t *philos)
{	
	int k = 0;
	while (k < 5)
	{
		pthread_mutex_lock(&philos->o_meu_garfo);
		printf("%ls\n", (int *) &philos->o_meu_garfo);
		printf("Eat\n");
		pthread_mutex_unlock(&philos->o_meu_garfo);
		k++;
	}
	return (0);
}

void	init_philos (int philos_nbr)
{
	data_t *philos;
	int i;

	philos = malloc (sizeof(data_t));
	if (!philos)
		return ;
	i = 0;
	while (i < philos_nbr)
	{
		ft_printf("Filosofo numero %d pronto\n", i + 1);
		pthread_mutex_init(&philos->o_meu_garfo, NULL);
		pthread_create(&philos->philos, NULL, routine(philos), philos);
		i++;
	}
	i = 0;
	while (i < philos_nbr)
	{
		pthread_join(philos->philos, NULL);
		i++;
	}
	pthread_mutex_destroy(&philos->o_meu_garfo);

}

int	main(int ac, char **av)
{
	(void) ac;
	(void) av;
	int k;

	if (ac == 1)
		return (1);
	k = ft_atoi(av[1]);
	printf("Numeros de filosofos é %d\n", k);
	init_philos(k);
	return (0);
}