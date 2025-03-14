/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:00:00 by philosopher       #+#    #+#             */
/*   Updated: 2025/03/14 20:33:43 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/**
 * Fonction principale exécutée par chaque thread philosophe
 *
 * @param arg Pointeur vers la structure t_philosopher du philosophe
 * @return NULL à la fin de l'exécution
 *
 * Contient la boucle principale qui alterne entre manger, dormir et penser.
 * S'arrête lorsqu'un philosophe meurt ou que tous ont assez mangé.
 */
void	*philosopher_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	while (1)
	{
		take_forks(philo);
		eat(philo);
		put_down_forks(philo);
		sleep_philosopher(philo);
		think(philo);
		pthread_mutex_lock(&philo->sim->monitor_mutex);
		if (philo->sim->someone_died || philo->sim->all_ate_enough)
		{
			pthread_mutex_unlock(&philo->sim->monitor_mutex);
			break ;
		}
		pthread_mutex_unlock(&philo->sim->monitor_mutex);
	}
	return (NULL);
}

/**
 * Fonction special pour le philosophe unique
 *
 * @param arg Pointeur vers la structure t_philosopher du philosophe
 * @return NULL à la fin de l'exécution
 *
 * Contient la boucle principale qui alterne entre manger, dormir et penser.
 * S'arrête lorsqu'un philosophe meurt ou que tous ont assez mangé.
 */
void	*philosopher_routine_single(void *arg)
{
	t_philosopher *philo;

	philo = (t_philosopher *)arg;

	pthread_mutex_lock(&philo->sim->forks[philo->left_fork]);
	log_state(philo->sim, philo->id, "has taken a fork");
	precise_sleep(philo->sim->config.time_to_die);
	pthread_mutex_unlock(&philo->sim->forks[philo->left_fork]);
	announce_death(philo->sim, philo->id);
	return (NULL);
}