/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mutex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/15 11:39:01 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/08/15 12:00:45 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philosophers.h"


void    exit_on_error(data_t *data, int error_value)
{
    free(data);
    free (error_value);
}

void    routine(void *arg)
{

    data_t *data;
    int i;

    data = (data_t *) arg;
    i = 0;
    while (i < 10)
    {
        pthread_mutex_lock(&data->mutex); // locka o mutex
        (data->num++);
        pthread_mutex_unlock(&data->mutex); // unlocka o mutex
        i++;
    }
}


data_t *init_data()
{
    data_t *data;
    data = malloc (sizeof(data_t));
    if (!data)
        return (1);
    data->num = 0;
    pthread_mutex_init(&data->mutex, NULL);
    free (data);
}



void    example()
{

    data_t  *data;
    pthread_t t1;
    pthread_t t2;

    data = init_data();
    if (pthread_create(&t1, NULL, routine, data))


}


int main()
{
    example();

    return (0);
}