/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sleeping_thinking.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 00:00:00 by user42            #+#    #+#             */
/*   Updated: 2025/03/13 14:20:34 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	sleep_philosopher(t_philosopher *philo)
{
	log_state(philo->sim, philo->id, "is sleeping");
	precise_sleep(philo->sim->config.time_to_sleep);
}

void	think(t_philosopher *philo)
{
	log_state(philo->sim, philo->id, "is thinking");
	smart_think_delay(philo);
}