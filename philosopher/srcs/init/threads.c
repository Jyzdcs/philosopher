/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   threads.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:00:00 by philosopher       #+#    #+#             */
/*   Updated: 2025/03/13 15:59:29 by kclaudan         ###   ########.fr       */
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
	/* À implémenter */
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
	/* À implémenter */
	return (0);
}