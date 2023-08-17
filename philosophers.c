/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:49:23 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/08/17 16:08:18 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

int mails = 0;
pthread_mutex_t mutex;

void *routine(void *arg)
{	
	(void) arg;
	int k = 0;
	while (k < 10000)
	{
		pthread_mutex_lock(&mutex);
		mails++;
		pthread_mutex_unlock(&mutex);
		k++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	
	data_t philos;
	int i;
	pthread_mutex_init(&philos.mutex, NULL);

	(void) ac;
	(void) av;
	for (i = 0; i < 4; i++)
	{
		if (pthread_create (&philos.philos, NULL, &routine, NULL) != 0)
			return (1);
		if (pthread_join(philos.philos, NULL) != 0)
		return (2);
	}
	printf("valor de mails: %d\n", mails);
	pthread_mutex_destroy(&mutex);
	return (0);
}
