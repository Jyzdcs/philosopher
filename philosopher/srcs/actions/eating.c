/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eating.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 00:00:00 by user42            #+#    #+#             */
/*   Updated: 2025/03/13 14:20:24 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	take_forks(t_philosopher *philo)
{
	int	first_fork;
	int	second_fork;

	if (should_take_forks_in_reverse(philo))
	{
		first_fork = philo->right_fork;
		second_fork = philo->left_fork;
	}
	else
	{
		first_fork = philo->left_fork;
		second_fork = philo->right_fork;
	}
	pthread_mutex_lock(&philo->sim->forks[first_fork]);
	log_state(philo->sim, philo->id, "has taken a fork");
	pthread_mutex_lock(&philo->sim->forks[second_fork]);
	log_state(philo->sim, philo->id, "has taken a fork");
}

void	eat(t_philosopher *philo)
{
	pthread_mutex_lock(&philo->sim->death_mutex);
	philo->last_meal_time = get_timestamp_ms();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->sim->death_mutex);
	log_state(philo->sim, philo->id, "is eating");
	precise_sleep(philo->sim->config.time_to_eat);
}

void	put_down_forks(t_philosopher *philo)
{
	pthread_mutex_unlock(&philo->sim->forks[philo->left_fork]);
	pthread_mutex_unlock(&philo->sim->forks[philo->right_fork]);
}