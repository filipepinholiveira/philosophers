/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   take_fork_utils.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:52:00 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/09/13 16:00:57 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	take_left_fork(t_philo *philo)
{
	if (philo_died(philo) || get_philo_state(philo) == DEAD) 
		return (1);
	pthread_mutex_lock(philo->left_f);
	print_msg(philo->data, philo->id, TAKE_FORKS);
	return (0);
}

int	take_right_fork(t_philo *philo)
{
	if (philo_died(philo) || get_philo_state(philo) == DEAD) 
		return (1);
	pthread_mutex_lock(philo->right_f);
	print_msg(philo->data, philo->id, TAKE_FORKS);
	return (0);
}

int	take_forks(t_philo *philo)
{
	if (philo->data->nb_philos == 1)
		return (handle_1_philo(philo));
	if (philo->id % 2 == 0)
	{
		if (take_right_fork(philo) != 0)
			return (1);
		if (take_left_fork(philo) != 0)
		{
			drop_right_fork(philo);
			return (1);
		}
	}
	else
	{
		if (take_left_fork(philo) != 0)
			return (1);
		if (take_right_fork(philo) != 0)
		{
			drop_left_fork(philo);
			return (1);
		}
	}
	return (0);
}
