/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:00:00 by philosopher       #+#    #+#             */
/*   Updated: 2025/03/13 17:06:05 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/**
 * Libère proprement toutes les ressources allouées
 *
 * @param sim Pointeur vers la structure de simulation
 *
 * Libère toute la mémoire allouée dynamiquement.
 * S'assure que tous les threads sont correctement terminés.
 * Détruit tous les mutex.
 */
void	cleanup_simulation(t_simulation *sim)
{
	/* À implémenter */
}

/**
 * Affiche un message d'erreur et quitte le programme
 *
 * @param sim Pointeur vers la structure de simulation
 * @param message Message d'erreur à afficher
 *
 * Affiche un message d'erreur.
 * Nettoie les ressources déjà allouées.
 * Quitte le programme avec un code d'erreur.
 */
void	error_exit(t_simulation *sim, char *message)
{
	/* À implémenter */
}

/**
 * Gestion centralisée des erreurs
 *
 * @param sim Pointeur vers la structure de simulation
 * @param error_code Code d'erreur spécifique
 * @param message Message d'erreur à afficher
 * @return Le code d'erreur passé en paramètre
 *
 * Nettoie les ressources appropriées selon l'étape où l'erreur s'est produite.
 * Affiche des messages d'erreur informatifs.
 */
int	handle_error(t_simulation *sim, int error_code, char *message)
{
	/* À implémenter */
	printf("Error: %s\n", message);
	return (error_code);
}