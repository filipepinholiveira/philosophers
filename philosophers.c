/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/14 18:49:23 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/08/14 20:02:42 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// gcc -g -pthread philosophers.c -o philosophers

void *routine()
{
	printf("routine created\n");
	sleep(3);
	printf("end routine\n");
}


int	main(int ac, char **av)
{
	pthread_t t1;
	pthread_t t2;
	pthread_create (&t1, NULL, &routine, NULL);
	pthread_create (&t2, NULL, &routine, NULL);
	pthread_join(t1, NULL);
	return (0);
}
