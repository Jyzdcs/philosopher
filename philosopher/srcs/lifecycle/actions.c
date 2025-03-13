/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   actions.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:00:00 by philosopher       #+#    #+#             */
/*   Updated: 2025/03/13 15:59:29 by kclaudan         ###   ########.fr       */
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
	/* À implémenter */
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
	/* À implémenter */
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
	/* À implémenter */
}