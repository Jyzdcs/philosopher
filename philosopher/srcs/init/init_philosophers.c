/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:00:00 by philosopher       #+#    #+#             */
/*   Updated: 2025/03/13 21:43:32 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/**
 * Initialise les structures pour chaque philosophe
 *
 * @param sim Pointeur vers la structure de simulation
 * @return 0 en cas de succès, -1 en cas d'erreur
 *
 * Initialise chaque philosophe avec son numéro, état initial et compteurs.

	* Configure les indices des fourchettes gauche et droite pour chaque philosophe.
 * Configure le timestamp de leur dernier repas au début de la simulation.
 */
int	init_philosophers(t_simulation *sim)
{
	int i;

	i = 0;
	while (i < sim->config.number_of_philosophers)
	{
		sim->philosophers[i].id = i + 1;
		sim->philosophers[i].meals_eaten = 0;
		sim->philosophers[i].last_meal_time = get_timestamp_ms();
		sim->philosophers[i].left_fork = i;
		sim->philosophers[i].right_fork = (i + 1)
			% sim->config.number_of_philosophers;
		sim->philosophers[i].sim = sim;
		i++;
	}
	return (0);
}