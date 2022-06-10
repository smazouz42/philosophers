/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 13:47:36 by smazouz           #+#    #+#             */
/*   Updated: 2022/05/09 13:47:42 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	destroy_mutex(t_philo **philo, int node_nb)
{
	while (node_nb > 0)
	{
		pthread_mutex_destroy(&(*philo)->mutex);
				(*philo) = (*philo)->next;
		node_nb--;
	}
}

void	ft_free_all(t_philos_inf *philo_inf, t_philo *p)
{
	free(philo_inf);
	ft_free_list(&p, philo_inf->philo_nb);
	destroy_mutex(&p, philo_inf->philo_nb);
}

void	ft_check_dead(t_philos_inf *p_inf, t_philo *p)
{
	if (p_inf->nb_philos_who_died == 0)
	{
		printf("\033[0;31m%lu %d died\n", get_time() - p_inf->start_time, p->id);
		p_inf->nb_philos_who_died++;
		destroy_mutex(&p, p_inf->philo_nb);
		free(p_inf);
		ft_free_list(&p, p_inf->philo_nb);
	}
}
