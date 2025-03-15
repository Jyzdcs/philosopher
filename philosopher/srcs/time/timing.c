/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   timing.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:00:00 by philosopher       #+#    #+#             */
/*   Updated: 2025/03/15 19:32:33 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/**
 * Récupère le timestamp actuel en millisecondes
 *
 * @return Timestamp actuel en millisecondes
 *
 * Utilise gettimeofday pour obtenir le temps actuel en millisecondes.
 */
long long	get_timestamp_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (tv.tv_sec * 1000 + tv.tv_usec / 1000);
}

/**
 * Calcule le temps écoulé depuis le début de la simulation
 *
 * @param sim Pointeur vers la structure de simulation
 * @return Temps écoulé en millisecondes
 *
 * Calcule la différence entre le timestamp actuel et le timestamp de départ.
 */
long long	get_elapsed_time(t_simulation *sim)
{
	return (get_timestamp_ms() - sim->start_time);
}

/**
 * Implémente une attente précise pendant la durée spécifiée
 *
 * @param duration_ms Durée d'attente en millisecondes
 *
 * Utilise usleep avec de petits intervalles pour une meilleure précision.
 * Évite la dérive temporelle sur de longues périodes.
 */
void	precise_sleep(int duration_ms)
{
	int	remaining_time;
	int	sleep_time;

	remaining_time = duration_ms;
	while (remaining_time > 0)
	{
		if (remaining_time > 100)
			sleep_time = 100;
		else
			sleep_time = remaining_time;
		usleep(sleep_time * 1000);
		remaining_time -= sleep_time;
	}
}
