/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 00:00:00 by user42            #+#    #+#             */
/*   Updated: 2025/03/13 14:20:55 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	*monitor_routine(void *arg)
{
	t_simulation *sim;
	int i;
	int n;

	sim = (t_simulation *)arg;
	n = sim->config.number_of_philosophers;
	while (1)
	{
		i = 0;
		while (i < n)
		{
			if (check_philosopher_death(&sim->philosophers[i]))
			{
				announce_death(sim, sim->philosophers[i].id);
				return (NULL);
			}
			i++;
		}
		if (sim->config.must_eat_count && all_philosophers_ate_enough(sim))
		{
			pthread_mutex_lock(&sim->death_mutex);
			sim->all_ate_enough = 1;
			pthread_mutex_unlock(&sim->death_mutex);
			return (NULL);
		}
		precise_sleep(1);
	}
	return (NULL);
}