/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 00:00:00 by user42            #+#    #+#             */
/*   Updated: 2025/03/13 14:21:31 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	log_state(t_simulation *sim, int philo_id, char *message)
{
	long elapsed_time;
	int should_print;

	pthread_mutex_lock(&sim->print_mutex);
	pthread_mutex_lock(&sim->death_mutex);
	should_print = !sim->someone_died;
	pthread_mutex_unlock(&sim->death_mutex);
	if (should_print)
	{
		elapsed_time = get_elapsed_time(sim);
		printf("%ld %d %s\n", elapsed_time, philo_id, message);
	}
	pthread_mutex_unlock(&sim->print_mutex);
}