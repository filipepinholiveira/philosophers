
#ifndef PHILOSOPHERS_H
#define PHILOSOPHERS_H

# include <stdio.h>
# include <unistd.h>
# include <stdio.h>
# include <pthread.h>


typedef struct data_s
{
    int num;
    pthread_mutex_t mutex;
} data_t;


#endif