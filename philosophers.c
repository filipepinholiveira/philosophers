/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:49:23 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/08/15 11:32:45 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// gcc -g -pthread philosophers.c -o philosophers

void *routine(void *arg)
{
	int i = 0;
	while (i <= 10)
	{
	printf("routine created\n");
	i++;
	usleep(100000);
	}
}

void *routine_2(void *arg)
{	
	int k = 0;
	while (k <= 10)
	{
	printf("routine ended\n");
	k++;
	usleep(100000);
	}
}


int	main(int ac, char **av)
{
	pthread_t t1;
	pthread_t t2;
	pthread_create (&t1, NULL, &routine, NULL);
	pthread_create (&t2, NULL, &routine_2, NULL);
	pthread_join(t1, NULL);
	pthread_join(t2, NULL);
	return (0);
}
