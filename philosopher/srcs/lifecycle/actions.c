/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:00:00 by philosopher       #+#    #+#             */
/*   Updated: 2025/03/14 16:49:47 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/**
 * Prend les deux fourchettes nécessaires pour manger
 *
 * @param philo Pointeur vers la structure du philosophe
 *
 * Prend les deux fourchettes dans un ordre défini.
 * Utilise pthread_mutex_lock pour verrouiller les fourchettes.
 * Affiche les messages appropriés pour chaque fourchette prise.
 */
void	take_forks(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->sim->forks[philo->left_fork]);
	pthread_mutex_lock(&philo->sim->forks[philo->right_fork]);
	log_state(philo->sim, philo->id, "has taken a fork");
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
	philo->last_meal_time = get_elapsed_time(philo->sim);
	philo->meals_eaten++;
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
