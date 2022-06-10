/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/04 13:08:13 by smazouz           #+#    #+#             */
/*   Updated: 2022/05/09 00:24:04 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo_bonus.h"

t_philo	*ft_lstlast(t_philo *philo)
{
	if (!philo)
		return (NULL);
	while (philo->next != NULL )
	{
		philo = philo->next;
	}
	return (philo);
}
