/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 00:00:00 by user42            #+#    #+#             */
/*   Updated: 2025/03/13 14:23:19 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

void	init_simulation(t_simulation *sim, t_config *config)
{
	sim->config = *config;
	sim->philosophers = NULL;
	sim->forks = NULL;
	sim->someone_died = 0;
	sim->all_ate_enough = 0;
	sim->start_time = get_timestamp_ms();
}