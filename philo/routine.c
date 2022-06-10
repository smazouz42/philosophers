/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:48:50 by smazouz           #+#    #+#             */
/*   Updated: 2022/05/09 14:14:10 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	take_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_lock(&philo->mutex);
		print_msg(philo, 1);
		pthread_mutex_lock(&philo->next->mutex);
		print_msg(philo, 1);
	}
	else
	{
		pthread_mutex_lock(&philo->next->mutex);
		print_msg(philo, 1);
		pthread_mutex_lock(&philo->mutex);
		print_msg(philo, 1);
	}
}

void	leave_fork(t_philo *philo)
{
	if (philo->id % 2 == 0)
	{
		pthread_mutex_unlock(&philo->mutex);
		pthread_mutex_unlock(&philo->next->mutex);
	}
	else
	{
		pthread_mutex_unlock(&philo->next->mutex);
		pthread_mutex_unlock(&philo->mutex);
	}
}

void	*routine(void *inf)
{
	t_philo	*philo;
	int		true;
	int		var;

	philo = inf;
	var = philo->info->nb_must_eat;
	true = 0;
	if (philo->info->nb_must_eat == -1)
		true = 1;
	while (var || true)
	{
		take_fork(philo);
		print_msg(philo, 4);
		ft_usleep(philo->info->time_to_eat * 1000, get_time());
		if (true == 0)
			philo->info->nb++;
		leave_fork(philo);
		print_msg(philo, 2);
		ft_usleep(philo->info->time_to_sleep * 1000, get_time());
		print_msg(philo, 3);
			var--;
	}
	return (NULL);
}
