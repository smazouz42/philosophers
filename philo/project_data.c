/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project_data.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 12:54:32 by smazouz           #+#    #+#             */
/*   Updated: 2022/05/09 12:58:13 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

t_philos_inf	*philo_data(t_philos_inf *philo_inf, char **av, int ac)
{
	philo_inf = malloc(sizeof(t_philos_inf));
	philo_inf->philo_nb = ft_atoi(av[1]);
	philo_inf->time_to_die = ft_atoi(av[2]);
	philo_inf->time_to_eat = ft_atoi(av[3]);
	philo_inf->time_to_sleep = ft_atoi(av[4]);
	philo_inf->nb_philos_who_died = 0;
	philo_inf->nb = 0;
	if (ac == 6)
		philo_inf->nb_must_eat = ft_atoi(av[5]);
	else
		philo_inf->nb_must_eat = -1;
	return (philo_inf);
}

void	ft_philo_list(t_philo **philo, t_philos_inf *philo_inf)
{
	int	index;

	index = 0;
	while (philo_inf->philo_nb > index)
	{
		if (index == 0)
		(*philo) = ft_philo_new(index + 1, philo_inf);
		else
			ft_lstadd_back(philo, ft_philo_new(index + 1, philo_inf));
		index++;
	}
	ft_lstlast(*philo)->next = (*philo);
}
