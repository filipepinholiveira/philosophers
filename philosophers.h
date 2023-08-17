
#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>
# include <stdlib.h>
# include "sources/libft/libft.h"
# include "sources/PRINTF/ft_printf.h"


typedef struct data_s
{
    pthread_t philos;
    pthread_mutex_t o_meu_garfo;
	pthread_mutex_t *garfo_do_outro;

} data_t;

#endif