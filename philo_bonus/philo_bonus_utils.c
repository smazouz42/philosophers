/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus_utils.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:56:29 by smazouz           #+#    #+#             */
/*   Updated: 2022/05/09 15:03:08 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo_bonus.h"

void	ft_free_list(t_philo **philo, int node_nb)
{
	t_philo	*tmp;

	while (node_nb > 0)
	{
		tmp = (*philo);
		(*philo) = (*philo)->next;
		free(tmp);
		node_nb--;
	}
}

size_t	get_time(void)
{
	struct timeval	time;

	gettimeofday(&time, NULL);
	return (time.tv_sec * 1000 + time.tv_usec / 1000);
}

void	ft_usleep(size_t time, size_t start_time)
{
	size_t	sleep_time;

	sleep_time = time * 0.94;
	usleep(sleep_time);
	while (get_time() < (start_time + (time / 1000)))
		usleep(100);
}

void	print_msg(t_philo *philo, int type)
{
	sem_t	*print;

	print = sem_open("/print", O_CREAT | O_EXCL, 0644, 1);
	sem_wait(print);
	if (type == 1)
		printf("\033[0;37m%ld %d has taken a fork\n",
			get_time() - philo->info->start_time, philo->id);
	else if (type == 2)
		printf("\033[0;32m%ld %d is sleeping\n",
			get_time() - philo->info->start_time, philo->id);
	else if (type == 3)
		printf("\033[0;37m%ld %d is thinking\n",
			get_time() - philo->info->start_time, philo->id);
	else if (type == 4)
	{
		printf("\033[0;33m%ld %d is eating\n",
			get_time() - philo->info->start_time, philo->id);
		philo->last_time_to_eat = get_time();
		philo->nb++;
	}
	sem_unlink("/print");
	sem_post(print);
}

void	*check(void *p)
{
	t_philo	*philo;
	int		index;

	philo = p;
	while (1)
	{
		if ((int)philo->info->nb == philo->info->nb_must_eat)
		{
			sem_post(philo->info->dead);
			exit(1);
		}
		if (get_time() - philo->last_time_to_eat > philo->info->time_to_die)
		{
			sem_wait(philo->info->print_dead);
			printf("\033[0;31m%lu %d has dead\n",
				get_time() - philo->info->start_time, philo->id);
			index = -1;
			while (++index < philo->info->philo_nb)
				sem_post(philo->info->dead);
		}
		usleep(50);
	}
	return (NULL);
}
