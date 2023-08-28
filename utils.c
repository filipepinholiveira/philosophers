/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 21:17:56 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/08/28 16:25:02 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	handle_1_philo(t_philo *philo)
{
	take_left_fork(philo); //take_fork_utils.c
	ft_usleep(get_die_time(philo->data)); //time.c
	set_philo_state(philo, DEAD); //setter.c
	return (1);
}

void	print_msg(t_data *data, int id, char *msg)
{
	uint64_t	time;

	time = get_time() - get_start_time(data); //time.c
	pthread_mutex_lock(&data->mut_print);
	if (get_keep_iterate(data)) //get_utils.c
		printf("%lu %d %s\n", time, id, msg);
	pthread_mutex_unlock(&data->mut_print);
}

bool	nb_meals_check(t_data *data)
{
	if (data->nb_meals > 0)
		return (true);
	return (false);
}

void	free_data(t_data *data)
{
	int	i;
	int	nb_philos;

	nb_philos = get_nbr_philos(data);
	i = -1;
	while (++i < nb_philos)
	{
		pthread_mutex_destroy(&data->forks[i]);
		pthread_mutex_destroy(&data->philos[i].mut_state);
		pthread_mutex_destroy(&data->philos[i].mut_last_eat_time);
		pthread_mutex_destroy(&data->philos[i].mut_nb_meals_had);
	}
	pthread_mutex_destroy(&data->mut_die_t);
	pthread_mutex_destroy(&data->mut_eat_t);
	pthread_mutex_destroy(&data->mut_keep_iter);
	pthread_mutex_destroy(&data->mut_nb_philos);
	pthread_mutex_destroy(&data->mut_print);
	pthread_mutex_destroy(&data->mut_sleep_t);
	pthread_mutex_destroy(&data->mut_start_time);
	free (data->philo_ths);
	free (data->philos);
	free (data->forks);
}
