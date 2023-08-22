/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 19:59:53 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/08/21 22:15:31 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_usleep(uint64_t sleep_time)
{
	u_int64_t start;

	start = get_time(); //time.c
	while(get_time() - start < sleep_time) //time.c
		usleep(500);
}

u_int64_t	get_time(void)
{
	struct timeval	tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return ((tv.tv_sec * (u_int64_t)1000) + (tv.tv_usec / 1000));
}