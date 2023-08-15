/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:49:23 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/08/15 16:29:36 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// gcc -g -pthread philosophers.c -o philosophers

int mails = 0;
pthread_mutex_t mutex;

void *routine(void *arg)
{	
	int k = 0;
	while (k < 10000)
	{
		pthread_mutex_lock(&mutex);
		mails++;
		pthread_mutex_unlock(&mutex);
		k++;
	}
}

int	main(int ac, char **av)
{
	//pthread_t th[4];
	data_t philos;
	int i;
	pthread_mutex_init(&philos.mutex, NULL);

	for (i = 0; i < 4; i++)
	{
		// if (pthread_create (&th[i], NULL, &routine, NULL) != 0)
		// 	return (1);
		// if (pthread_join(th[i], NULL) != 0)
		// return (2);
		if (pthread_create (&philos.philos, NULL, &routine, NULL) != 0)
			return (1);
		if (pthread_join(philos.philos, NULL) != 0)
		return (2);
	}
	printf("valor de mails: %d\n", mails);
	pthread_mutex_destroy(&mutex);
	return (0);
}
