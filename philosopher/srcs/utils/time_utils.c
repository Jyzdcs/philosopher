/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   time_utils.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 00:00:00 by user42            #+#    #+#             */
/*   Updated: 2025/03/13 14:21:21 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

long	get_timestamp_ms(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return ((tv.tv_sec * 1000) + (tv.tv_usec / 1000));
}

long	get_elapsed_time(t_simulation *sim)
{
	return (get_timestamp_ms() - sim->start_time);
}

void	precise_sleep(long duration_ms)
{
	long start_time;
	long current_time;

	start_time = get_timestamp_ms();
	while (1)
	{
		current_time = get_timestamp_ms();
		if (current_time - start_time >= duration_ms)
			break ;
		usleep(100);
	}
}