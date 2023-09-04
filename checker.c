/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checker.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 16:13:31 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/09/04 19:20:49 by fpinho-d         ###   ########.fr       */
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
	nb_philos = data->nb_philos; //get_utils.c
	i = -1;
	while (++i < nb_philos)
		set_philo_state(&philos[i], DEAD); //setters.c
}

bool	philo_died(t_philo *philo)
{
	bool	result;
	t_data	*data;

	data = philo->data;
	result = false;
	if (get_time() - get_last_eat_time(philo) > philo->data->die_time //time.c && ... && get_utils_2.c
		&& get_philo_state(philo) != EATING)
	{
		(set_philo_state(philo, DEAD)); //setters.c
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
	nb_philos = data->nb_philos; //get_utils.c
	i = -1;
	while (++i < nb_philos && get_keep_iterate(data)) //get_utils_2.c
	{
		if (philo_died(&philo[i]) && get_keep_iterate(data)) //checkers.c && get_utils_2.c
		{
			print_msg(data, philo[i].id, DIED); //utils.c
			set_keep_iterate(data, false); //setter.c
			notify_all_philo(data); //checker.c
			break ;
		}
		if (i == nb_philos - 1)
			i = -1;
		ft_usleep(1000); //time.c
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
	nb_philos = data->nb_philos; //get_utils.c
	while (++i < nb_philos && get_keep_iterate(data)) //get_utils_2.c
	{
		ft_usleep(1000);
		if (is_philo_full(data, &data->philos[i]) == false) //checkers.c
			i = -1;
	}
	if (get_keep_iterate(data) == true) //get_utils.c
	{
		set_keep_iterate(data, false); //setter.c
		notify_all_philo(data); //checkers.c
	}
	return (NULL);
}
