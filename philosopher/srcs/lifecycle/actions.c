/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:00:00 by philosopher       #+#    #+#             */
/*   Updated: 2025/03/17 14:13:57 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/**
 * Prend les deux fourchettes nécessaires pour manger
 *
 * @param philo Pointeur vers la structure du philosophe
 *
 * Prend les deux fourchettes dans un ordre fixe (par index croissant).
 * Utilise pthread_mutex_lock pour verrouiller les fourchettes.
 * Affiche les messages appropriés pour chaque fourchette prise.
 */
void	take_forks(t_philosopher *philo)
{
	int	first_fork;
	int	second_fork;

	if (philo->left_fork < philo->right_fork)
	{
		first_fork = philo->left_fork;
		second_fork = philo->right_fork;
	}
	else
	{
		first_fork = philo->right_fork;
		second_fork = philo->left_fork;
	}
	pthread_mutex_lock(&philo->sim->forks[first_fork]);
	log_state(philo->sim, philo->id, "has taken a fork");
	pthread_mutex_lock(&philo->sim->forks[second_fork]);
	log_state(philo->sim, philo->id, "has taken a fork");
}

/**
 * Fait manger le philosophe
 *
 * @param philo Pointeur vers la structure du philosophe
 *
 * Met à jour le timestamp du dernier repas.
 * Incrémente le compteur de repas.
 * Attend pendant time_to_eat millisecondes.
 * Affiche le message d'état "is eating".
 */
void	eat(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->sim->death_mutex);
	philo->last_meal_time = get_elapsed_time(philo->sim);;
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->sim->death_mutex);
	log_state(philo->sim, philo->id, "is eating");
	precise_sleep(philo->sim->config.time_to_eat);
}

/**
 * Repose les fourchettes après avoir mangé
 *
 * @param philo Pointeur vers la structure du philosophe
 *
 * Déverrouille les mutex des fourchettes avec pthread_mutex_unlock.
 * Libère les ressources pour les autres philosophes.
 */
void	put_down_forks(t_philosopher *philo)
{
	pthread_mutex_unlock(&philo->sim->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->sim->forks[philo->right_fork]);
}
