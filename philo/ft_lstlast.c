/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstlast.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/30 23:01:29 by smazouz           #+#    #+#             */
/*   Updated: 2022/05/08 23:51:43 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

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
