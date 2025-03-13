/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   states.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:00:00 by philosopher       #+#    #+#             */
/*   Updated: 2025/03/13 15:54:11 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/**
 * Fait dormir le philosophe
 *
 * @param philo Pointeur vers la structure du philosophe
 *
 * Affiche le message d'état "is sleeping".
 * Attend pendant time_to_sleep millisecondes.
 */
void	sleep_philosopher(t_philosopher *philo)
{
	/* À implémenter */
}

/**
 * Fait penser le philosophe
 *
 * @param philo Pointeur vers la structure du philosophe
 *
 * Affiche le message d'état "is thinking".
 * Peut inclure un délai calculé pour éviter la famine.
 */
void	think(t_philosopher *philo)
{
	/* À implémenter */
}

/**
 * Affiche l'état d'un philosophe avec le format requis
 *
 * @param sim Pointeur vers la structure de simulation
 * @param philo_id Identifiant du philosophe
 * @param message Message d'état à afficher
 *
 * Protège l'affichage avec un mutex pour éviter les mélanges.
 * N'affiche pas si un philosophe est déjà mort.
 */
void	log_state(t_simulation *sim, int philo_id, char *message)
{
	/* À implémenter */
}