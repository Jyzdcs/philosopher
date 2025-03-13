/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:00:00 by philosopher       #+#    #+#             */
/*   Updated: 2025/03/13 15:59:29 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>
# include <pthread.h>
# include <sys/time.h>

/* Structures de données nécessaires */

typedef struct s_config
{
	int		number_of_philosophers;
	long	time_to_die;
	long	time_to_eat;
	long	time_to_sleep;
	int		number_of_meals;
	int		must_eat_count;
}	t_config;

typedef struct s_philosopher
{
	int				id;
	int				meals_eaten;
	long			last_meal_time;
	int				left_fork;
	int				right_fork;
	pthread_t		thread;
	struct s_simulation	*sim;
}	t_philosopher;

typedef struct s_simulation
{
	t_config		config;
	t_philosopher	*philosophers;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_mutex;
	pthread_mutex_t	death_mutex;
	int				someone_died;
	int				all_ate_enough;
	long			start_time;
}	t_simulation;

/* Prototypes des fonctions d'initialisation */
int		parse_args(int argc, char **argv, t_config *config);
void	init_simulation(t_simulation *sim, t_config *config);
int		init_philosophers(t_simulation *sim);
int		init_mutexes(t_simulation *sim);
void	destroy_mutexes(t_simulation *sim);

/* Prototypes des fonctions de threads */
int		create_threads(t_simulation *sim);
void	*philosopher_routine(void *arg);
int		join_threads(t_simulation *sim);

/* Prototypes des fonctions du cycle de vie */
void	take_forks(t_philosopher *philo);
void	eat(t_philosopher *philo);
void	put_down_forks(t_philosopher *philo);
void	sleep_philosopher(t_philosopher *philo);
void	think(t_philosopher *philo);
void	log_state(t_simulation *sim, int philo_id, char *message);

/* Prototypes des fonctions de gestion du temps */
long	get_timestamp_ms(void);
long	get_elapsed_time(t_simulation *sim);
void	precise_sleep(long duration_ms);

/* Prototypes des fonctions de monitoring */
void	*monitor_routine(void *arg);
int		check_philosopher_death(t_philosopher *philo);
int		all_philosophers_ate_enough(t_simulation *sim);
void	announce_death(t_simulation *sim, int philo_id);

/* Prototypes des fonctions de nettoyage et gestion des erreurs */
void	cleanup_simulation(t_simulation *sim);
void	error_exit(t_simulation *sim, char *message);
int		handle_error(t_simulation *sim, int error_code, char *message);

/* Prototypes des fonctions pour éviter les deadlocks */
void	init_eating_strategy(t_simulation *sim);
int		should_take_forks_in_reverse(t_philosopher *philo);
void	smart_think_delay(t_philosopher *philo);

/* Prototypes des fonctions utilitaires */
int		ft_atoi_strict(const char *str, int *result);
void	ft_usleep(long microseconds);
char	*get_state_message(int state);
void	debug_log(t_simulation *sim, char *format, ...);

#endif 