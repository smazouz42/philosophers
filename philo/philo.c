/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 16:57:12 by smazouz           #+#    #+#             */
/*   Updated: 2022/06/10 09:07:28 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"
#include <sys/time.h>

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
		usleep(50);
}

void	ft_philos_creat(t_philos_inf *philo_inf, t_philo *philo, char **av)
{
	int			index;
	pthread_t	philos;

	philo_inf->start_time = get_time();
	index = 0;
	(void)av;
	while (philo_inf->philo_nb > index)
	{
		if (pthread_create(&philos, NULL, &routine, philo) != 0)
		{
			perror("Failed to creat thread\n");
			return ;
		}
		pthread_detach(philos);
		index++;
		usleep(5);
		philo = philo->next;
	}
}

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

int	main(int ac, char *av[])
{
	t_philo			*p;
	t_philos_inf	*philo_inf;

	if (parser(ac, av) == 0)
		return (0);
	philo_inf = NULL;
	philo_inf = philo_data(philo_inf, av, ac);
	ft_philo_list(&p, philo_inf);
	ft_philos_creat(philo_inf, p, av);
	while (1)
	{
		if (philo_inf->philo_nb * philo_inf->nb_must_eat == (int)philo_inf->nb)
		{
			ft_free_all(philo_inf, p);
			return (0);
		}
		if (get_time() - p->last_time_to_eat > philo_inf->time_to_die)
		{
			ft_check_dead(philo_inf, p);
			return (0);
		}
		p = p->next;
		usleep(60);
	}
	return (0);
}
