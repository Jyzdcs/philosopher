/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cleanup.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 00:00:00 by user42            #+#    #+#             */
/*   Updated: 2025/03/13 14:22:01 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	destroy_mutexes(t_simulation *sim)
{
	int	i;
	int	n;

	if (sim->forks)
	{
		n = sim->config.number_of_philosophers;
		i = 0;
		while (i < n)
		{
			pthread_mutex_destroy(&sim->forks[i]);
			i++;
		}
	}
	pthread_mutex_destroy(&sim->print_mutex);
	pthread_mutex_destroy(&sim->death_mutex);
}

void	cleanup_simulation(t_simulation *sim)
{
	destroy_mutexes(sim);
	if (sim->philosophers)
		free(sim->philosophers);
	if (sim->forks)
		free(sim->forks);
}

void	error_exit(t_simulation *sim, char *message)
{
	if (message)
		printf("Error: %s\n", message);
	if (sim)
		cleanup_simulation(sim);
}

int	handle_error(t_simulation *sim, int error_code, char *message)
{
	error_exit(sim, message);
	return (error_code);
}