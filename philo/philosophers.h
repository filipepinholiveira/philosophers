/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fpinho-d <fpinho-d@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/08/28 15:58:17 by fpinho-d          #+#    #+#             */
/*   Updated: 2023/09/12 17:38:38 by fpinho-d         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <unistd.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <sys/time.h>
# include <stdint.h>
# include <stdbool.h>
# include <aio.h>

# define WRONG_INPUT 1
# define MALLOC_ERROR 2
# define TAKE_FORKS "has taken a fork"
# define EAT "is eating"
# define SLEEP "is sleeping"
# define THINK "is thinking"
# define DIED "died"

struct	s_data;

typedef enum e_philo_state
{
	EATING = 0,
	SLEEPING = 1,
	THINKING = 2,
	DEAD = 3,
	FULL = 4,
	IDLE = 5
}	t_state;

typedef struct s_philo
{
	int				id;
	int				nb_meals_had;
	struct s_data	*data;
	t_state			state;
	pthread_mutex_t	*left_f;
	pthread_mutex_t	*right_f;
	pthread_mutex_t	mut_state;
	pthread_mutex_t	mut_nb_meals_had;
	pthread_mutex_t	mut_last_eat_time;
	u_int64_t		last_eat_time;
}t_philo;

typedef struct s_data
{
	int				nb_philos;
	int				nb_meals;
	int				nb_full_p;
	bool			keep_iterating;
	u_int64_t		eat_time;
	u_int64_t		die_time;
	u_int64_t		sleep_time;
	u_int64_t		start_time;
	pthread_mutex_t	mut_print;
	pthread_mutex_t	mut_keep_iter;
	pthread_mutex_t	*forks;
	pthread_t		monit_all_alive;
	pthread_t		monit_all_full;
	pthread_t		*philo_ths;
	t_philo			*philos;
}	t_data;

//checkers.c

bool		philo_died(t_philo *philo);
void		notify_all_philo(t_data *data);
void		*all_alive_routine(void *data_p);
void		*all_full_routine(void *data_p);
bool		is_philo_full(t_data *data, t_philo *philo);

// eat.c

void		update_last_meal_time(t_philo *philo);
void		update_nb_meals_had(t_philo *philo);
int			eat(t_philo *philo);

//ft_atoi.c

int			ft_atoi(char *str);

//get_utils.c

int			get_nb_meals_had(t_philo *philo);
bool		get_keep_iterate(t_data *data);
t_state		get_philo_state(t_philo *philo);
int			get_nbr_philos(t_data *data);
uint64_t	get_last_eat_time(t_philo *philo);

//init_data.c

int			init_data(t_data *data, int ac, char **av);
int			init_philos(t_data *data);
int			init_forks(t_data *data);

// parse.c

int			check_inputs(int ac, char **av);
int			is_digit(int ac, char **av);
void		print_instructions(void);

// routine.c

void		*routine(void *philo_p);

// setter.c

void		set_philo_state(t_philo *philo, t_state state);
void		set_keep_iterate(t_data *data, bool set_to);

//sleep.c

int			ft_sleep(t_philo *philo);
void		sleep_for_eat(t_philo *philo);

//take_fork_utils.c && take_fork_utils_2.c

int			take_right_fork(t_philo *philo);
int			take_left_fork(t_philo *philo);
int			take_forks(t_philo *philo);

void		drop_right_fork(t_philo *philo);
void		drop_left_fork(t_philo *philo);
void		drop_forks(t_philo *philo);

// think.c

int			think(t_philo *philo);

//time.c

u_int64_t	get_time(void);
void		ft_usleep(uint64_t sleep_time);

//utils.c

int			handle_1_philo(t_philo *philo);
void		print_msg(t_data *data, int id, char *msg);
bool		nb_meals_check(t_data *data);
void		free_data(t_data *data);

#endif
