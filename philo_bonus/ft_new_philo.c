/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_new_philo.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:07:22 by smazouz           #+#    #+#             */
/*   Updated: 2022/05/09 00:25:12 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo_bonus.h"

t_philo	*ft_new_philo(int id, t_philos_inf *inf)
{
	t_philo	*philo;

	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->id = id;
	philo->info = inf;
	philo->nb = 0;
	philo->last_time_to_eat = get_time();
	philo->next = NULL;
	return (philo);
}
