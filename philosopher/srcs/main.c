/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 00:00:00 by user42            #+#    #+#             */
/*   Updated: 2025/03/13 14:19:00 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/philosophers.h"

int	main(int argc, char **argv)
{
	t_simulation sim;
	t_config config;

	if (parse_args(argc, argv, &config) != 0)
		return (1);
	init_simulation(&sim, &config);
	if (init_philosophers(&sim) != 0)
		return (handle_error(&sim, 1, "Failed to initialize philosophers"));
	if (init_mutexes(&sim) != 0)
		return (handle_error(&sim, 2, "Failed to initialize mutexes"));
	if (create_threads(&sim) != 0)
		return (handle_error(&sim, 3, "Failed to create threads"));
	if (join_threads(&sim) != 0)
		return (handle_error(&sim, 4, "Failed to join threads"));
	cleanup_simulation(&sim);
	return (0);
}