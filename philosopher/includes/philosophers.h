/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosophers.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:00:00 by philosopher       #+#    #+#             */
/*   Updated: 2025/03/15 21:24:44 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILOSOPHERS_H
# define PHILOSOPHERS_H
# include <limits.h>
# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

/* Structures de données nécessaires */
typedef struct s_config
{
	/* Nombre de philosophes autour de la table */
	int					number_of_philosophers;
	/* Délai en ms au-delà duquel un philosophe meurt s'il n'a pas mangé */
	int					time_to_die;
	/* Durée en ms que prend un philosophe pour manger */
	int					time_to_eat;
	/* Durée en ms pendant laquelle un philosophe dort */
	int					time_to_sleep;
	/* Nombre optionnel de repas pour arrêter la simulation */
	int					number_of_meals;
	/* Flag indiquant si number_of_meals est spécifié (1) ou non (0) */
	int					must_eat_count;
}						t_config;

typedef struct s_philosopher
{
	/* Numéro du philosophe (de 1 à N) */
	int					id;
	/* Compteur de repas consommés */
	int					meals_eaten;
	/* Moment du dernier repas (pour surveiller la mort) */
	long long			last_meal_time;
	/* Index de la fourchette à sa gauche */
	int					left_fork;
	/* Index de la fourchette à sa droite */
	int					right_fork;
	/* Thread qui exécute la routine du philosophe */
	pthread_t			thread;
	/* Pointeur vers la simulation (accès aux données partagées) */
	struct s_simulation	*sim;
}						t_philosopher;

typedef struct s_simulation
{
	/* Thread de surveillance des philosophes */
	pthread_t			monitor_thread;
	/* Configuration de la simulation */
	t_config			config;
	/* Tableau dynamique des philosophes */
	t_philosopher		*philosophers;
	/* Tableau de mutex (un par fourchette) */
	pthread_mutex_t		*forks;
	/* Mutex pour éviter que les messages ne se mélangent */
	pthread_mutex_t		print_mutex;
	/* Mutex protégeant les vérifications de mort */
	pthread_mutex_t		death_mutex;
	/* Flag indiquant si un philosophe est mort (1) ou non (0) */
	int					someone_died;
	/* Flag indiquant si tous les philosophes ont assez mangé */
	int					all_ate_enough;
	/* Flag indiquant si tous les philosophes ont assez mangé */
	long long			start_time;
}						t_simulation;

/* Prototypes des fonctions d'initialisation */

int						parse_args(int argc, char **argv, t_config *config);
void					init_simulation(t_simulation *sim, t_config *config);
int						init_philosophers(t_simulation *sim);
int						init_mutexes(t_simulation *sim);
void					destroy_mutexes(t_simulation *sim);

/* Prototypes des fonctions de threads */

int						create_threads(t_simulation *sim);
int						create_single_thread(t_simulation *sim);
void					*philosopher_routine(void *arg);
void					*philosopher_routine_single(void *arg);
int						join_threads(t_simulation *sim);

/* Prototypes des fonctions du cycle de vie */

void					take_forks(t_philosopher *philo);
void					eat(t_philosopher *philo);
void					put_down_forks(t_philosopher *philo);
void					sleep_philosopher(t_philosopher *philo);
void					think(t_philosopher *philo);
void					log_state(t_simulation *sim, int philo_id,
							char *message);

/* Prototypes des fonctions de gestion du temps */

long long				get_timestamp_ms(void);
long long				get_elapsed_time(t_simulation *sim);
void					precise_sleep(int duration_ms);

/* Prototypes des fonctions de monitoring */

void					*monitor_routine(void *arg);
int						check_philosopher_death(t_philosopher *philo);
int						all_philosophers_ate_enough(t_simulation *sim);
void					announce_death(t_simulation *sim, int philo_id);

/* Prototypes des fonctions de nettoyage et gestion des erreurs */

void					cleanup_simulation(t_simulation *sim);
void					error_exit(t_simulation *sim, char *message);
int						handle_error(t_simulation *sim, int error_code,
							char *message);

/* Prototypes des fonctions pour éviter les deadlocks */

void					init_eating_strategy(t_simulation *sim);
int						should_take_forks_in_reverse(t_philosopher *philo);
void					smart_think_delay(t_philosopher *philo);

/* Prototypes des fonctions utilitaires */

int						atoi_strict(const char *str, int *result);
char					*get_state_message(int state);

#endif