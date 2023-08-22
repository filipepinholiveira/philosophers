/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 20:57:54 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/08/22 01:35:45 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include "philo.h"

void	*routine(void *philo_p)
{
	t_philo *philo;
	philo = (t_philo *) philo_p;
	update_last_meal_time(philo); //eat.c
	while(get_philo_state(philo) != DEAD) //get_utils.c
	{
		if (eat(philo) != 0) //eat.c
			break ;
		if (get_philo_state(philo) == DEAD) //get_utils.c
			break ;
		if (ft_sleep(philo) != 0) //sleep.c
			break ;
		if (get_philo_state(philo) == DEAD) //get_utils.c
			break ;
		if (think(philo) != 0)
			break ;
	}
	return (NULL);
}