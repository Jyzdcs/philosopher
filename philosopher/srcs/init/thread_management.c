/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   thread_management.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 00:00:00 by user42            #+#    #+#             */
/*   Updated: 2025/03/13 14:19:58 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

int	create_threads(t_simulation *sim)
{
	int	i;
	int	n;

	n = sim->config.number_of_philosophers;
	i = 0;
	while (i < n)
	{
		if (pthread_create(&sim->philosophers[i].thread, NULL,
				philosopher_routine, &sim->philosophers[i]) != 0)
			return (-1);
		i++;
	}
	return (0);
}

int	join_threads(t_simulation *sim)
{
	int i;
	int n;

	n = sim->config.number_of_philosophers;
	i = 0;
	while (i < n)
	{
		if (pthread_join(sim->philosophers[i].thread, NULL) != 0)
			return (-1);
		i++;
	}
	return (0);
}