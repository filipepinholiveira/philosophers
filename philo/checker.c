/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:13:31 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/09/13 16:06:16 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

bool	is_philo_full(t_data *data, t_philo *philo)
{
	bool	result;

	result = false;
	if (get_nb_meals_had(philo) >= data->nb_meals)
		result = true;
	return (result);
}

void	notify_all_philo(t_data *data)
{
	t_philo	*philos;
	int		i;
	int		nb_philos;

	philos = data->philos;
	nb_philos = data->nb_philos;
	i = -1;
	while (++i < nb_philos)
		set_philo_state(&philos[i], DEAD);
}

bool	philo_died(t_philo *philo)
{
	bool	result;

	result = false;
	if (get_time() - get_last_eat_time(philo) > philo->data->die_time
		&& get_philo_state(philo) != EATING)
	{
		(set_philo_state(philo, DEAD));
		result = true;
	}
	return (result);
}

void	*all_alive_routine(void *data_p)
{
	int		i;
	int		nb_philos;
	t_data	*data;
	t_philo	*philo;

	data = (t_data *) data_p;
	philo = data->philos;
	nb_philos = data->nb_philos;
	i = -1;
	while (++i < nb_philos && get_keep_iterate(data))
	{
		if (philo_died(&philo[i]) && get_keep_iterate(data))
		{
			print_msg(data, philo[i].id, DIED);
			set_keep_iterate(data, false);
			notify_all_philo(data);
			break ;
		}
		if (i == nb_philos - 1)
			i = -1;
		usleep(1000);
	}
	return (NULL);
}

void	*all_full_routine(void *data_p)
{
	t_data	*data;
	int		i;
	int		nb_philos;

	data = (t_data *) data_p;
	i = -1;
	nb_philos = data->nb_philos;
	while (++i < nb_philos && get_keep_iterate(data))
	{
		ft_usleep(1000);
		if (is_philo_full(data, &data->philos[i]) == false)
			i = -1;
	}
	if (get_keep_iterate(data) == true)
	{
		set_keep_iterate(data, false);
		notify_all_philo(data);
	}
	return (NULL);
}
