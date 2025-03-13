/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:00:00 by philosopher       #+#    #+#             */
/*   Updated: 2025/03/13 18:26:16 by kclaudan         ###   ########.fr       */
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

	if (parse_args(argc, argv, &config))
		return (1);
	return (0);
}