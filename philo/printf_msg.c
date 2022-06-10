/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 14:14:45 by smazouz           #+#    #+#             */
/*   Updated: 2022/06/10 09:13:40 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

void	printf_msg_utils(t_philo *p, int type)
{
	pthread_mutex_t	print;

	pthread_mutex_init(&print, NULL);
	if (type == 3)
	{
		pthread_mutex_lock(&print);
		printf("\033[0;37m%ld %d is thinking\n",
			get_time() - p->info->start_time, p->id);
		pthread_mutex_unlock(&print);
	}
	else if (type == 4)
	{
		pthread_mutex_lock(&print);
		printf("\033[0;33m%ld %d is eating\n",
			get_time() - p->info->start_time, p->id);
		p->last_time_to_eat = get_time();
		p->nb++;
		pthread_mutex_unlock(&print);
	}
	pthread_mutex_destroy(&print);
}

void	print_msg(t_philo *p, int type)
{
	pthread_mutex_t	print;

	pthread_mutex_init(&print, NULL);
	if (type == 1)
	{
		pthread_mutex_lock(&print);
		printf("\033[0;37m%ld %d has taken a fork\n",
			get_time() - p->info->start_time, p->id);
		pthread_mutex_unlock(&print);
	}
	else if (type == 2)
	{
		pthread_mutex_lock(&print);
		printf("\033[0;32m%ld %d is sleeping\n",
			get_time() - p->info->start_time, p->id);
		pthread_mutex_unlock(&print);
	}
	else if (type == 3 || type == 4)
		printf_msg_utils(p, type);
	pthread_mutex_destroy(&print);
}
