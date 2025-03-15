/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:00:00 by philosopher       #+#    #+#             */
/*   Updated: 2025/03/15 19:31:59 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/**
 * Initialise la structure principale de simulation
 *
 * @param sim Pointeur vers la structure de simulation à initialiser
 * @param config Pointeur vers la configuration validée
 *
 * Initialise la structure principale de simulation, copie la configuration,
 * alloue la mémoire pour les philosophes et les fourchettes,
 * et définit le timestamp de démarrage de la simulation.
 */
void	init_simulation(t_simulation *sim, t_config *config)
{
	sim->config = *config;
	sim->philosophers = malloc(sizeof(t_philosopher)
			* config->number_of_philosophers);
	sim->forks = malloc(sizeof(pthread_mutex_t)
			* config->number_of_philosophers);
	sim->start_time = get_timestamp_ms();
	sim->someone_died = 0;
	sim->all_ate_enough = 0;
}
