/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:47:14 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/08/28 16:14:14 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	get_nb_meals_had(t_philo *philo)
{
	int	nb_meals_had;

	pthread_mutex_lock(&philo->mut_nb_meals_had);
	nb_meals_had = philo->nb_meals_had;
	pthread_mutex_unlock(&philo->mut_nb_meals_had);
	return (nb_meals_had);
}

bool	get_keep_iterate(t_data *data)
{
	bool	keep_iterate;

	pthread_mutex_lock(&data->mut_keep_iter);
	keep_iterate = data->keep_iterating;
	pthread_mutex_unlock(&data->mut_keep_iter);
	return (keep_iterate);
}

int	get_nbr_philos(t_data *data)
{
	int	nb_philos;

	pthread_mutex_lock(&data->mut_nb_philos);
	nb_philos = data->nb_philos;
	pthread_mutex_unlock(&data->mut_nb_philos);
	return (nb_philos);
}

t_state	get_philo_state(t_philo *philo)
{
	t_state	state;

	pthread_mutex_lock(&philo->mut_state);
	state = philo->state;
	pthread_mutex_unlock(&philo->mut_state);
	return (state);
}

u_int64_t	get_start_time(t_data *data)
{
	uint64_t	start_time;

	pthread_mutex_lock(&data->mut_start_time);
	start_time = data->start_time;
	pthread_mutex_unlock(&data->mut_start_time);
	return (start_time);
}
