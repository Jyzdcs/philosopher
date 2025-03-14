/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helpers.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kclaudan <kclaudan@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/13 12:00:00 by philosopher       #+#    #+#             */
/*   Updated: 2025/03/13 17:24:07 by kclaudan         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/philosophers.h"

/**
 * Version stricte de atoi qui détecte les erreurs
 *
 * @param str Chaîne de caractères à convertir
 * @param result Pointeur vers l'entier où stocker le résultat
 * @return 0 en cas de succès, -1 en cas d'erreur
 *
 * Vérifie les overflows et les caractères non numériques.
 */
int	ft_atoi_strict(const char *str, int *result)
{
	if (!str || !result)
		return (-1);
	*result = 0;
	while ((9 <= *str && *str <= 13) || *str == ' ')
		str++;
	if (*str == '-')
		return (-1);
	if (*str == '+')
		str++;
	while (*str >= '0' && *str <= '9')
	{
		*result = *result * 10 + (*str - '0');
		str++;
	}
	if (*str != '\0')
		return (-1);
	return (0);
}

/**
 * Convertit un code d'état en message formaté
 *
 * @param state Code d'état (entier)
 * @return Message formaté correspondant à l'état
 *
 * Utile pour centraliser les messages d'état.
 */
char	*get_state_message(int state)
{
	if (state == 0)
		return ("is thinking");
	else if (state == 1)
		return ("is eating");
	else if (state == 2)
		return ("is sleeping");
	return (NULL);
}

 * Fonction de journalisation pour le débogage
 *
 * @param sim Pointeur vers la structure de simulation
 * @param format Format de la chaîne à afficher (comme printf)
 * @param ... Arguments variables pour le format
 *
 * Peut être activée/désactivée via une macro.
 */
void	debug_log(t_simulation *sim, char *format, ...)
{
	/* À implémenter */
}
