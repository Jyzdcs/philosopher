/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_mutexes.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 00:00:00 by user42            #+#    #+#             */
/*   Updated: 2025/03/13 14:19:46 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

int	init_mutexes(t_simulation *sim)
{
	int i;
	int n;

	n = sim->config.number_of_philosophers;
	sim->forks = (pthread_mutex_t *)malloc(sizeof(pthread_mutex_t) * n);
	if (!sim->forks)
		return (-1);
	if (pthread_mutex_init(&sim->print_mutex, NULL) != 0)
		return (-1);
	if (pthread_mutex_init(&sim->death_mutex, NULL) != 0)
		return (-1);
	i = 0;
	while (i < n)
	{
		if (pthread_mutex_init(&sim->forks[i], NULL) != 0)
			return (-1);
		i++;
	}
	return (0);
}