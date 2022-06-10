/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_philo_new.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/08 23:48:52 by smazouz           #+#    #+#             */
/*   Updated: 2022/05/08 23:52:58 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

t_philo	*ft_philo_new(int id, t_philos_inf *inf)
{
	t_philo			*philo;
	pthread_mutex_t	fork;

	pthread_mutex_init(&fork, NULL);
	philo = malloc(sizeof(t_philo));
	if (!philo)
		return (NULL);
	philo->id = id;
	philo->info = inf;
	philo->mutex = fork;
	philo->last_time_to_eat = get_time();
	philo->nb = 0;
	philo->next = NULL;
	return (philo);
}
