/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   think.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 01:30:26 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/09/12 18:25:04 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int	think(t_philo *philo)
{
	set_philo_state(philo, THINKING); // setters.c
	if (get_philo_state(philo) == DEAD) //get_utils.c
		return (1);
	print_msg(philo->data, philo->id, THINK);
	ft_usleep((philo->data->die_time - (philo->data->eat_time + philo->data->sleep_time)) / 2);
	return (0);
}
