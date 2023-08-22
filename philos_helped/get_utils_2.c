/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_utils_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 22:06:34 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/08/22 01:28:22 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

uint64_t	get_sleep_time(t_data *data)
{
	uint64_t sleep_time;

	pthread_mutex_lock(&data->mut_sleep_t);
	sleep_time = data->sleep_time;
	pthread_mutex_unlock(&data->mut_sleep_t);
	return(sleep_time);
}


uint64_t	get_eat_time(t_data *data)
{
	u_int64_t	eat_time;

	pthread_mutex_lock(&data->mut_eat_t);
	eat_time = data->eat_time;
	pthread_mutex_unlock(&data->mut_eat_t);
	return(eat_time);
}


uint64_t    get_die_time(t_data *data)
{
	u_int64_t die_time;

	pthread_mutex_lock(&data->mut_die_t);
	die_time = data->die_time;
	pthread_mutex_unlock(&data->mut_die_t);
	return(die_time);
}

uint64_t	get_last_eat_time(t_philo *philo)
{
	uint64_t last_eat_time;

	pthread_mutex_lock(&philo->mut_last_eat_time);
	last_eat_time = philo->last_eat_time;
	pthread_mutex_unlock(&philo->mut_last_eat_time);
	return(last_eat_time);
}