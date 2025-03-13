/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/01 00:00:00 by user42            #+#    #+#             */
/*   Updated: 2025/03/13 14:21:47 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

static int	ft_isspace(char c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\v' || c == '\f'
		|| c == '\r');
}

static int	ft_isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

int	ft_atoi_strict(const char *str, int *result)
{
	long num;
	int sign;
	int i;

	num = 0;
	sign = 1;
	i = 0;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	if (!ft_isdigit(str[i]))
		return (-1);
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + (str[i] - '0');
		if ((sign == 1 && num > INT_MAX) || (sign == -1 && num
				* sign < INT_MIN))
			return (-1);
		i++;
	}
	if (str[i] != '\0')
		return (-1);
	*result = (int)(num * sign);
	return (0);
}