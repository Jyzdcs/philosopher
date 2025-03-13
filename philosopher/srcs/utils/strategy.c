/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strategy.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:00:00 by philosopher       #+#    #+#             */
/*   Updated: 2025/03/13 21:07:41 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/**
 * Configure une stratégie pour éviter les deadlocks
 *
 * @param sim Pointeur vers la structure de simulation
 *
 * Configure une stratégie pour éviter les deadlocks

	* (ex: philosophes pairs/impairs prennent les fourchettes dans un ordre différent).
 * Peut introduire un léger délai pour les philosophes pairs/impairs.
 */
void	init_eating_strategy(t_simulation *sim)
{
	/* À implémenter */
}

/**
 * Détermine si un philosophe spécifique devrait prendre ses fourchettes
 * dans l'ordre inverse
 *
 * @param philo Pointeur vers la structure du philosophe
 * @return 1 si les fourchettes doivent être prises dans l'ordre inverse,
	0 sinon
 *
 * Aide à prévenir les situations où tous les philosophes prennent
 * leur fourchette gauche en même temps.
 */
int	should_take_forks_in_reverse(t_philosopher *philo)
{
	/* À implémenter */
	return (0);
}

/**
 * Calcule un délai intelligent pour la phase de réflexion
 *
 * @param philo Pointeur vers la structure du philosophe
 *
 * Calcule un délai intelligent pour la phase de réflexion.
 * Peut utiliser l'ID du philosophe pour introduire un décalage.
 * Aide à désynchroniser les philosophes naturellement.
 */
void	smart_think_delay(t_philosopher *philo)
{
	int delay;

	if (philo->id % 2 == 0)
		delay = 100;
	else
		delay = 0;
	precise_sleep(delay);
}