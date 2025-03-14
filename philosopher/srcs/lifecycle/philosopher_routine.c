/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:00:00 by philosopher       #+#    #+#             */
/*   Updated: 2025/03/14 17:32:24 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/**
 * Fonction principale exécutée par chaque thread philosophe
 *
 * @param arg Pointeur vers la structure t_philosopher du philosophe
 * @return NULL à la fin de l'exécution
 *
 * Contient la boucle principale qui alterne entre manger, dormir et penser.
 * S'arrête lorsqu'un philosophe meurt ou que tous ont assez mangé.
 */
void	*philosopher_routine(void *arg)
{
	t_philosopher	*philo;

	philo = (t_philosopher *)arg;
	while (1)
	{
		take_forks(philo);
		eat(philo);
		put_down_forks(philo);
		sleep_philosopher(philo);
		think(philo);
		if (philo->sim->someone_died || philo->sim->all_ate_enough)
			break ;
	}
	return (NULL);
}
