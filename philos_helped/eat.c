/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:56:23 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/08/22 01:17:03 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    update_nb_meals_had(t_philo *philo)
{
    pthread_mutex_lock(&philo->mut_nb_meals_had);
    philo->nb_meals_had++;
    pthread_mutex_unlock(&philo->mut_nb_meals_had);
}

void	update_last_meal_time(t_philo *philo)
{
    pthread_mutex_lock(&philo->mut_last_eat_time);
    philo->last_eat_time = get_time(); //time.c
    pthread_mutex_unlock(&philo->mut_last_eat_time);
}

int eat(t_philo *philo)
{
    if (take_forks(philo) != 0) //take_fork_utils.c
        return (1);
    set_philo_state(philo, EATING); //setters.c
    print_msg(philo->data, philo->id, EAT); //utils.c
    update_last_meal_time(philo); //eat.c
    sleep_for_eat(philo); //sleep.c
    drop_forks(philo); //drop_fork_utils_2.c
    return (0);
}