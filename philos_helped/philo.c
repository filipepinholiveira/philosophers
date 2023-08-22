/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:32:49 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/08/22 04:57:28 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	join_trhead(t_data *data)
{
	int	i;
	int	nb_philos;

	nb_philos = get_nbr_philos(data); //get_utils.c
	i = -1;
	if (pthread_join(data->monit_all_alive, NULL))
		return (1);
	if (nb_meals_check(data) == true
		&& pthread_join(data->monit_all_full, NULL)) //utils.c
		return(1);
	while(++i < nb_philos)
	{
		if(pthread_join(data->philo_ths[i], NULL))
			return(1);
	}
	return(0);
}


int	run_threads(t_data *data)
{
	int i;
	int	nb_philos;

	nb_philos = get_nbr_philos(data); //get_utils.c
	i = -1;
	data->start_time = get_time();
	while(++i < nb_philos)
	{
		if (pthread_create(&data->philo_ths[i], NULL,
			&routine, &data->philos[i]) != 0) //routine.c
				return(1);
	}
	if (pthread_create(&data->monit_all_alive, NULL,
		&all_alive_routine, data)) //checkers.c
			return (1);
	if (nb_meals_check(data) == true //utils.c
		&& pthread_create(&data->monit_all_full, NULL,
			&all_full_routine, data)) //checkers.c
				return(1);
	return (0);
}


int	philosophers(int ac, char **av)
{
	t_data data;

	if (init_data(&data, ac, av) != 0) //init_data.c
		return(MALLOC_ERROR);
	init_philos(&data); //init_data.c
	init_forks(&data); // init data.c
	run_threads(&data); // philo.c
	join_trhead(&data); //philo.c
	free_data(&data);
	return (0);
}


int	main(int ac, char **av)
{	
	if (check_inputs(ac, av) != 0) //  parse.c
		{
			print_instructions(); //parse.c 
			return (WRONG_INPUT);
		}
	if (philosophers(ac, av) != 0) // philo.c
		return (MALLOC_ERROR);
	//usleep(10000);
	//printf("tudo bem ate aqui\n");
	return (0);
}


