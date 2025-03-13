/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 00:00:00 by user42            #+#    #+#             */
/*   Updated: 2025/03/13 14:19:36 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

int	init_philosophers(t_simulation *sim)
{
	int i;
	int n;

	n = sim->config.number_of_philosophers;
	sim->philosophers = (t_philosopher *)malloc(sizeof(t_philosopher) * n);
	if (!sim->philosophers)
		return (-1);
	i = 0;
	while (i < n)
	{
		sim->philosophers[i].id = i + 1;
		sim->philosophers[i].meals_eaten = 0;
		sim->philosophers[i].last_meal_time = sim->start_time;
		sim->philosophers[i].left_fork = i;
		sim->philosophers[i].right_fork = (i + 1) % n;
		sim->philosophers[i].sim = sim;
		i++;
	}
	return (0);
}