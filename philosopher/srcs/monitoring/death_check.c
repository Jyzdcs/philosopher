/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   death_check.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 00:00:00 by user42            #+#    #+#             */
/*   Updated: 2025/03/13 14:21:09 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

int	check_philosopher_death(t_philosopher *philo)
{
	long	time_since_last_meal;
	long	current_time;

	pthread_mutex_lock(&philo->sim->death_mutex);
	current_time = get_timestamp_ms();
	time_since_last_meal = current_time - philo->last_meal_time;
	if (time_since_last_meal > philo->sim->config.time_to_die)
	{
		pthread_mutex_unlock(&philo->sim->death_mutex);
		return (1);
	}
	pthread_mutex_unlock(&philo->sim->death_mutex);
	return (0);
}

void	announce_death(t_simulation *sim, int philo_id)
{
	pthread_mutex_lock(&sim->death_mutex);
	if (!sim->someone_died)
	{
		sim->someone_died = 1;
		pthread_mutex_unlock(&sim->death_mutex);
		log_state(sim, philo_id, "died");
		return ;
	}
	pthread_mutex_unlock(&sim->death_mutex);
}

int	all_philosophers_ate_enough(t_simulation *sim)
{
	int i;
	int n;
	int all_ate_enough;

	n = sim->config.number_of_philosophers;
	pthread_mutex_lock(&sim->death_mutex);
	i = 0;
	all_ate_enough = 1;
	while (i < n)
	{
		if (sim->philosophers[i].meals_eaten < sim->config.number_of_meals)
		{
			all_ate_enough = 0;
			break ;
		}
		i++;
	}
	pthread_mutex_unlock(&sim->death_mutex);
	return (all_ate_enough);
}