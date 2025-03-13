/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   deadlock_prevention.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 00:00:00 by user42            #+#    #+#             */
/*   Updated: 2025/03/13 14:20:44 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	init_eating_strategy(t_simulation *sim)
{
	(void)sim;
}

int	should_take_forks_in_reverse(t_philosopher *philo)
{
	return (philo->id % 2 == 0);
}

void	smart_think_delay(t_philosopher *philo)
{
	long eat_sleep_time;
	long think_time;

	eat_sleep_time = philo->sim->config.time_to_eat
		+ philo->sim->config.time_to_sleep;
	think_time = philo->sim->config.time_to_die - eat_sleep_time - 10;
	if (think_time > 0)
		precise_sleep(think_time / 2);
}