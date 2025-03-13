/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 00:00:00 by user42            #+#    #+#             */
/*   Updated: 2025/03/13 14:19:15 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

static int	validate_args(t_config *config)
{
	if (config->number_of_philosophers <= 0)
		return (-1);
	if (config->time_to_die <= 0)
		return (-1);
	if (config->time_to_eat <= 0)
		return (-1);
	if (config->time_to_sleep <= 0)
		return (-1);
	if (config->must_eat_count && config->number_of_meals <= 0)
		return (-1);
	return (0);
}

int	parse_args(int argc, char **argv, t_config *config)
{
	int result;

	if (argc != 5 && argc != 6)
		return (-1);
	if (ft_atoi_strict(argv[1], &result) != 0)
		return (-1);
	config->number_of_philosophers = result;
	if (ft_atoi_strict(argv[2], &result) != 0)
		return (-1);
	config->time_to_die = (long)result;
	if (ft_atoi_strict(argv[3], &result) != 0)
		return (-1);
	config->time_to_eat = (long)result;
	if (ft_atoi_strict(argv[4], &result) != 0)
		return (-1);
	config->time_to_sleep = (long)result;
	config->must_eat_count = 0;
	if (argc == 6)
	{
		if (ft_atoi_strict(argv[5], &result) != 0)
			return (-1);
		config->number_of_meals = result;
		config->must_eat_count = 1;
	}
	return (validate_args(config));
}