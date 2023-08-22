/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/21 15:59:37 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/08/21 16:54:58 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"

// struct timeval 
// {
//     time_t      tv_sec;     /* seconds */
//     suseconds_t tv_usec;    /* microseconds */
// };
// 1 second = 1 000 000 microseconds
// 1 second =     1 000 milliseconds (este e o valor que usamos)

//int gettimeofday(struct timeval *tv, struct timezone *tz);

uint64_t	get_time(void)
{
	struct timeval tv;

	if (gettimeofday(&tv, NULL))
		return (0);
	return (tv.tv_sec * (uint64_t)1000 + (tv.tv_usec / 1000));
}



void example()
{
	struct timeval time;
	gettimeofday(&time, NULL);
	printf("valor em secs:%ld\n", time.tv_sec);
	printf("valor em microsecs:%ld\n", time.tv_usec);
	printf("anos passados desde 1970:%ld\n", time.tv_sec / 60 / 60 / 24 / 365);
}

void    example_2()
{
	uint64_t		start_time;
	uint_fast64_t	now;

	start_time = get_time();
	usleep(10000);
	now = get_time();
	printf("%ld millisegundos passaram desde o inicio da execuçao\n", now - start_time);

}


int main()
{
	example();
	puts("");
	example_2();
	return (0);
}