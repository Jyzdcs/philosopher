/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:00:00 by philosopher       #+#    #+#             */
/*   Updated: 2025/03/13 15:54:44 by kclaudan         ###   ########.fr       */
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
	/* À implémenter */
	return (NULL);
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
	/* À implémenter */
	return (0);
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
	/* À implémenter */
	return (0);
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
	/* À implémenter */
}