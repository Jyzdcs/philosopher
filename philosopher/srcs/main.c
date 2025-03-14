/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:00:00 by philosopher       #+#    #+#             */
/*   Updated: 2025/03/14 18:14:19 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

/**
 * Point d'entrée du programme philosophers
 *
 * @param argc Nombre d'arguments passés au programme
 * @param argv Tableau des arguments du programme
 * @return Code de sortie du programme (0 pour succès, 1 pour erreur)
 *
 * Vérifie les arguments, initialise la simulation et lance les threads
 * des philosophes. Surveille l'état des philosophes et nettoie les
 * ressources à la fin.
 */
int	main(int argc, char **argv)
{
	t_simulation sim;
	t_config config;

	if (parse_args(argc, argv, &config) < 0)
		return (1);
	printf("1\n");
	// init_simulation(&sim, &config);
	// if (init_philosophers(&sim) || init_mutexes(&sim))
	// 	return (1);
	// create_threads(&sim);
	// join_threads(&sim);
	// cleanup_simulation(&sim);
	return (0);
}