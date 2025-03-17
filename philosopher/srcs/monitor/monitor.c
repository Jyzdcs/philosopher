/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:00:00 by philosopher       #+#    #+#             */
/*   Updated: 2025/03/17 13:44:14 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/**
 * Routine de surveillance des philosophes
 *
 * @param arg Pointeur vers la structure de simulation
 * @return NULL à la fin de l'exécution
 *
 * Surveille l'état de tous les philosophes à intervalles réguliers.
 * Vérifie s'ils ont dépassé time_to_die sans manger.
 * Détecte si tous les philosophes ont mangé suffisamment.
 */
void	*monitor_routine(void *arg)
{
	t_simulation	*sim;
	t_philosopher	*philo;
	int				shortest_time;

	sim = (t_simulation *)arg;
	while (1)
	{
		// Trouver le délai de vérification optimal
		shortest_time = sim->config.time_to_die / 10;
		if (shortest_time > 10)
			shortest_time = 10;
		// Maximum 10ms pour la précision de détection de mort
		philo = sim->philosophers;
		while (philo < sim->philosophers + sim->config.number_of_philosophers)
		{
			if (check_philosopher_death(philo))
			{
				announce_death(sim, philo->id);
				return (NULL);
			}
			philo++;
		}
		if (sim->config.must_eat_count != -1
			&& all_philosophers_ate_enough(sim))
		{
			sim->all_ate_enough = 1;
			return (NULL);
		}
		// Pause stratégique pour réduire la charge CPU
		usleep(shortest_time * 1000); // Conversion en microsecondes
	}
}

/**
 * Vérifie si un philosophe a dépassé son temps maximal sans manger
 *
 * @param philo Pointeur vers la structure du philosophe
 * @return 1 si le philosophe est mort, 0 sinon
 *
 * Compare le temps écoulé depuis le dernier repas avec time_to_die.
 */
int	check_philosopher_death(t_philosopher *philo)
{
	int	death;

	death = 0;
	pthread_mutex_lock(&philo->sim->death_mutex);
	if (philo->last_meal_time
		+ philo->sim->config.time_to_die < get_elapsed_time(philo->sim))
		death = 1;
	pthread_mutex_unlock(&philo->sim->death_mutex);
	return (death);
}

/**
 * Vérifie si tous les philosophes ont mangé au moins number_of_meals fois
 *
 * @param sim Pointeur vers la structure de simulation
 * @return 1 si c'est le cas, 0 sinon
 *
 * Parcourt tous les philosophes et vérifie leur compteur de repas.
 */
int	all_philosophers_ate_enough(t_simulation *sim)
{
	t_philosopher	*philo;

	philo = sim->philosophers;
	pthread_mutex_lock(&sim->death_mutex);
	while (philo < sim->philosophers + sim->config.number_of_philosophers)
	{
		if (philo->meals_eaten < sim->config.number_of_meals)
		{
			pthread_mutex_unlock(&sim->death_mutex);
			return (0);
		}
		philo++;
	}
	pthread_mutex_unlock(&sim->death_mutex);
	return (1);
}

/**
 * Annonce la mort d'un philosophe
 *
 * @param sim Pointeur vers la structure de simulation
 * @param philo_id Identifiant du philosophe mort
 *
 * Affiche le message de mort avec le bon format.
 * Met à jour l'état de la simulation pour indiquer qu'un philosophe est mort.
 */
void	announce_death(t_simulation *sim, int philo_id)
{
	long long	timestamp;

	timestamp = get_timestamp_ms() - sim->start_time;
	pthread_mutex_lock(&sim->print_mutex);
	pthread_mutex_lock(&sim->death_mutex);
	printf("%lld %d died\n", timestamp, philo_id);
	sim->someone_died = 1;
	pthread_mutex_unlock(&sim->death_mutex);
	pthread_mutex_unlock(&sim->print_mutex);
}
