/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   setter.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 22:16:58 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/08/22 02:26:55 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    set_philo_state(t_philo *philo, t_state state)
{
    pthread_mutex_lock(&philo->mut_state);
    if (philo->state != DEAD)
        philo->state = state;
    pthread_mutex_unlock(&philo->mut_state);
}

void    set_keep_iterate(t_data *data, bool set_to)
{
    pthread_mutex_lock(&data->mut_keep_iter);
    data->keep_iterating = set_to;
    pthread_mutex_unlock(&data->mut_keep_iter);
}