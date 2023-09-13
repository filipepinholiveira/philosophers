/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 17:32:49 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/09/13 16:03:03 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	run_threads(t_data *data)
{
	int	i;
	int	nb_philos;

	nb_philos = data->nb_philos;
	i = -1;
	data->start_time = get_time();
	while (++i < nb_philos)
	{
		if (pthread_create(&data->philo_ths[i], NULL,
				&routine, &data->philos[i]))
			return (1);
	}
	if (pthread_create(&data->monit_all_alive, NULL,
			&all_alive_routine, data))
		return (1);
	if (nb_meals_check(data) == true
		&& pthread_create(&data->monit_all_full, NULL,
			&all_full_routine, data))
		return (1);
	return (0);
}

int	join_trhead(t_data *data)
{
	int	i;
	int	nb_philos;

	nb_philos = data->nb_philos;
	i = -1;
	if (pthread_join(data->monit_all_alive, NULL))
		return (1);
	if (nb_meals_check(data) == true
		&& pthread_join(data->monit_all_full, NULL))
		return (1);
	while (++i < nb_philos)
	{
		if (pthread_join(data->philo_ths[i], NULL))
			return (1);
	}
	return (0);
}

int	philosophers(int ac, char **av)
{
	t_data	data;

	if (init_data(&data, ac, av) != 0)
		return (MALLOC_ERROR);
	init_philos(&data);
	init_forks(&data);
	run_threads(&data);
	join_trhead(&data);
	free_data(&data);
	return (0);
}

int	main(int ac, char **av)
{
	if (check_inputs(ac, av) != 0)
	{
		print_instructions();
		return (WRONG_INPUT);
	}
	if (philosophers(ac, av) != 0)
		return (MALLOC_ERROR);
	return (0);
}
