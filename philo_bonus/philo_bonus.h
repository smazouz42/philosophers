/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 17:55:58 by smazouz           #+#    #+#             */
/*   Updated: 2022/05/09 15:02:33 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H
# include <pthread.h>
# include <sys/time.h>
# include <stdlib.h>
# include <unistd.h>
# include <signal.h>
# include <stdio.h>
# include <semaphore.h>

typedef struct s_philos_inf {
	int		philo_nb;
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	int		nb_must_eat;
	size_t	nb_philos_who_died;
	time_t	start_time;
	size_t	nb;
	pid_t	*pids;
	sem_t	*fork;
	sem_t	*dead;
	sem_t	*print_dead;

}			t_philos_inf;

typedef struct s_philo
{
	t_philos_inf	*info;
	int				id;
	size_t			last_time_to_eat;
	size_t			nb;
	struct s_philo	*next;
}			t_philo;

long			ft_atoi(const char *str);
int				parser_bonus(int size, char **arg);
void			ft_lstadd_back(t_philo **lst, t_philo *new);
t_philo			*ft_new_philo(int id, t_philos_inf *inf);
t_philo			*ft_lstlast(t_philo *philo);
size_t			get_time(void);
t_philos_inf	*philo_data(t_philos_inf *philo_inf, char **av, int ac);
void			ft_philo_list(t_philo **philo, t_philos_inf *philo_inf);
void			ft_free_list(t_philo **philo, int node_nb);
size_t			get_time(void);
void			ft_usleep(size_t time, size_t start_time);
void			print_msg(t_philo *philo, int type);
void			*check(void *p);
#endif
