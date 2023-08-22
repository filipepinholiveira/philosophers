/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleep.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/22 00:59:08 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/08/22 01:27:16 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    sleep_for_eat(t_philo *philo)
{
    ft_usleep(get_eat_time(philo->data)); //time.c
}

int ft_sleep(t_philo *philo)
{
    set_philo_state(philo, SLEEPING); //setters.c
    if (get_philo_state(philo) == DEAD) //get_utils.c
        return (1);
    print_msg(philo->data, philo->id, SLEEP); //utils.c
    ft_usleep(get_sleep_time(philo->data));
    return (0);
}