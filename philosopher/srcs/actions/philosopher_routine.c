/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philosopher_routine.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 00:00:00 by user42            #+#    #+#             */
/*   Updated: 2025/03/13 14:20:10 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

static int	should_stop_simulation(t_philosopher *philo)
{
	int	result;

	pthread_mutex_lock(&philo->sim->death_mutex);
	result = philo->sim->someone_died || philo->sim->all_ate_enough;
	pthread_mutex_unlock(&philo->sim->death_mutex);
	return (result);
}

void	*philosopher_routine(void *arg)
{
	t_philosopher *philo;

	philo = (t_philosopher *)arg;
	if (philo->id % 2 == 0)
		precise_sleep(philo->sim->config.time_to_eat / 2);
	while (!should_stop_simulation(philo))
	{
		take_forks(philo);
		eat(philo);
		put_down_forks(philo);
		sleep_philosopher(philo);
		think(philo);
	}
	return (NULL);
}