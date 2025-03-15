/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:00:00 by philosopher       #+#    #+#             */
/*   Updated: 2025/03/15 19:32:05 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/**
 * Crée un thread pour chaque philosophe
 *
 * @param sim Pointeur vers la structure de simulation
 * @return 0 en cas de succès, -1 en cas d'erreur
 *
 * Crée un thread pour chaque philosophe avec pthread_create.
 * Passe la structure du philosophe comme argument à la routine.
 */
int	create_threads(t_simulation *sim)
{
	int	i;

	i = 0;
	pthread_create(&sim->monitor_thread, NULL, monitor_routine, sim);
	while (i < sim->config.number_of_philosophers)
	{
		pthread_create(&sim->philosophers[i].thread, NULL, philosopher_routine,
			&sim->philosophers[i]);
		i++;
	}
	return (0);
}

/**
 * Crée un thread pour le philosophe unique
 *
 * @param sim Pointeur vers la structure de simulation
 * @return 0 en cas de succès, -1 en cas d'erreur
 *
 * Crée un thread pour le philosophe unique avec pthread_create.
 * Passe la structure du philosophe comme argument à la routine.
 */
int	create_single_thread(t_simulation *sim)
{
	pthread_create(&sim->philosophers[0].thread, NULL,
		philosopher_routine_single, &sim->philosophers[0]);
	return (0);
}

/**
 * Attend la fin de tous les threads avec pthread_join
 *
 * @param sim Pointeur vers la structure de simulation
 * @return 0 en cas de succès, -1 en cas d'erreur
 *
 * Attend la fin de tous les threads avec pthread_join.
 * Gère les erreurs potentielles lors de la jonction.
 */
int	join_threads(t_simulation *sim)
{
	int	i;

	i = 0;
	pthread_join(sim->monitor_thread, NULL);
	while (i < sim->config.number_of_philosophers)
	{
		pthread_join(sim->philosophers[i].thread, NULL);
		i++;
	}
	return (0);
}
