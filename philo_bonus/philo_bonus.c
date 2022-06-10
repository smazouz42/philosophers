/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:55:10 by smazouz           #+#    #+#             */
/*   Updated: 2022/05/09 15:02:02 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo_bonus.h"

void	routine_utils(int true, t_philo *philo)
{
	sem_wait(philo->info->fork);
	print_msg(philo, 1);
	sem_wait(philo->info->fork);
	print_msg(philo, 1);
	print_msg(philo, 4);
	ft_usleep(philo->info->time_to_eat * 1000, get_time());
	if (true == 0)
		philo->info->nb++;
	sem_post(philo->info->fork);
	sem_post(philo->info->fork);
	print_msg(philo, 2);
	ft_usleep(philo->info->time_to_sleep * 1000, get_time());
	print_msg(philo, 3);
}

void	*routine(t_philo *philo)
{
	int			true;
	int			var;
	pthread_t	thread;

	var = philo->info->nb_must_eat;
	true = 0;
	if (philo->info->nb_must_eat == -1)
		true = 1;
	pthread_create(&thread, NULL, &check, philo);
	pthread_detach(thread);
	while (var || true)
	{
		routine_utils(true, philo);
		var--;
	}
	return (NULL);
}

void	ft_philos_creat(t_philos_inf *philo_inf, t_philo *philo)
{
	int		index;
	pid_t	id;

	philo_inf->pids = malloc(sizeof(pid_t) * philo_inf->philo_nb);
	index = 0;
	while (philo->info->philo_nb > index)
	{
		id = fork();
		if (id < 0)
		{
			printf("fork failed\n");
			exit(1);
		}
		else if (id == 0)
			routine(philo);
		philo_inf->pids[index] = id;
		philo = philo->next;
		index++;
	}
}

void	ft_free_all(t_philos_inf *philo_inf, t_philo *philo)
{
	free(philo_inf->pids);
	free(philo_inf);
	ft_free_list(&philo, philo_inf->philo_nb);
}

int	main(int ac, char *av[])
{
	int				i;
	t_philo			*philo;
	t_philos_inf	*philo_inf;

	i = -1;
	if (parser_bonus(ac, av) == 0)
		return (0);
	philo_inf = NULL;
	philo_inf = philo_data(philo_inf, av, ac);
	ft_philo_list(&philo, philo_inf);
	sem_unlink("/dead");
	philo_inf->dead = sem_open("/dead", O_CREAT | O_EXCL, 0644, 0);
	sem_unlink("/print_dead");
	philo_inf->print_dead = sem_open("/print_dead", O_CREAT | O_EXCL, 0644, 1);
	philo_inf->start_time = get_time();
	ft_philos_creat(philo_inf, philo);
	while (++i < philo_inf->philo_nb)
		sem_wait(philo_inf->dead);
	i = -1;
	while (++i < philo_inf->philo_nb)
		kill(philo->info->pids[i], SIGTERM);
	sem_unlink("/dead");
	sem_unlink("/print_dead");
	sem_unlink("/fork");
	ft_free_all(philo_inf, philo);
}
