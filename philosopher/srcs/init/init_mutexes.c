/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutexes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:00:00 by philosopher       #+#    #+#             */
/*   Updated: 2025/03/13 19:38:12 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/**
 * Initialise tous les mutex nécessaires à la synchronisation
 *
 * @param sim Pointeur vers la structure de simulation
 * @return 0 en cas de succès, -1 en cas d'erreur
 *
 * Initialise un mutex pour chaque fourchette, un mutex pour l'affichage
 * (pour éviter que les messages se mélangent) et un mutex pour protéger
 * la vérification de la mort des philosophes.
 */
int	init_mutexes(t_simulation *sim)
{
	int	i;

	i = 0;
	while (i < sim->config.number_of_philosophers)
	{
		pthread_mutex_init(&sim->forks[i], NULL);
		i++;
	}
	pthread_mutex_init(&sim->print_mutex, NULL);
	pthread_mutex_init(&sim->death_mutex, NULL);
	return (0);
}

/**
 * Détruit proprement tous les mutex initialisés
 *
 * @param sim Pointeur vers la structure de simulation
 *
 * Détruit tous les mutex créés pour les fourchettes et la synchronisation.
 * Libère la mémoire associée.
 */
void	destroy_mutexes(t_simulation *sim)
{
	int i;

	i = 0;
	while (i < sim->config.number_of_philosophers)
	{
		pthread_mutex_destroy(&sim->forks[i]);
		i++;
	}
	pthread_mutex_destroy(&sim->print_mutex);
	pthread_mutex_destroy(&sim->death_mutex);
}