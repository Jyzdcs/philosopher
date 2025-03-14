/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:00:00 by philosopher       #+#    #+#             */
/*   Updated: 2025/03/14 18:13:01 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/**
 * Analyse et valide les arguments d'entrée du programme
 *
 * @param argc Nombre d'arguments passés au programme
 * @param argv Tableau des arguments du programme
 * @param config Pointeur vers la structure de configuration à remplir
 * @return 0 en cas de succès, -1 en cas d'erreur de parsing
 *
 * Vérifie que le nombre d'arguments est correct (5 ou 6),
 * convertit et valide les arguments numériques,
 * remplit la structure de configuration avec les valeurs.
 */
int	parse_args(int argc, char **argv, t_config *config)
{
	if (argc != 5 && argc != 6)
		return (handle_error(NULL, -1, "Invalid number of arguments"));
	if (ft_atoi_strict(argv[1], &config->number_of_philosophers) != 0)
		return (handle_error(NULL, -1, "Invalid number of philosophers"));
	if (ft_atoi_strict(argv[2], &config->time_to_die) != 0)
		return (handle_error(NULL, -1, "Invalid time to die"));
	if (ft_atoi_strict(argv[3], &config->time_to_eat) != 0)
		return (handle_error(NULL, -1, "Invalid time to eat"));
	if (ft_atoi_strict(argv[4], &config->time_to_sleep) != 0)
		return (handle_error(NULL, -1, "Invalid time to sleep"));
	if (argc == 6 && ft_atoi_strict(argv[5], &config->number_of_meals) > -1)
		config->must_eat_count = 1;
	else if (argc == 6 && ft_atoi_strict(argv[5], &config->number_of_meals) ==
		-1)
		return (handle_error(NULL, -1, "Invalid number of meals"));
	return (0);
}
