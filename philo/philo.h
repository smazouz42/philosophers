/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/09 00:15:43 by smazouz           #+#    #+#             */
/*   Updated: 2022/05/09 14:15:26 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H
# include <pthread.h>
# include <stdlib.h>
# include <unistd.h>
# include <stdio.h>

typedef struct s_philos_inf {
	int		philo_nb;
	size_t	time_to_die;
	size_t	time_to_eat;
	size_t	time_to_sleep;
	int		nb_must_eat;
	size_t	nb_philos_who_died;
	time_t	start_time;
	size_t	nb;
}			t_philos_inf;

typedef struct s_philo
{
	t_philos_inf	*info;
	int				id;
	pthread_mutex_t	mutex;
	size_t			last_time_to_eat;
	size_t			nb;
	struct s_philo	*next;
}			t_philo;

t_philo			*ft_philo_new(int id, t_philos_inf *inf);
void			ft_lstadd_back(t_philo **lst, t_philo *new);
t_philo			*ft_lstlast(t_philo *philo);
int				parser(int size, char **arg);
long			ft_atoi(const char *str);
void			*routine(void *inf);
void			print_msg(t_philo *philo, int type);
void			ft_usleep(size_t time, size_t start_time);
size_t			get_time(void);
t_philos_inf	*philo_data(t_philos_inf *philo_inf, char **av, int ac);
void			ft_philo_list(t_philo **philo, t_philos_inf *philo_inf);
void			destroy_mutex(t_philo **philo, int node_nb);
void			ft_check_dead(t_philos_inf *p_inf, t_philo *p);
void			ft_free_all(t_philos_inf *philo_inf, t_philo *p);
void			ft_free_list(t_philo **philo, int node_nb);
void			printf_msg_utils(t_philo *p, int type);
void			print_msg(t_philo *p, int type);

#endif