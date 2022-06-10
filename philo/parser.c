/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parser.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: smazouz <smazouz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/03 11:56:14 by smazouz           #+#    #+#             */
/*   Updated: 2022/05/09 12:47:10 by smazouz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include"philo.h"

long	ft_atoi(const char *str)
{
	int	res;
	int	i;
	int	count;

	if (!str)
		return (0);
	res = 0;
	i = 0;
	count = 1;
	while ((str[i] == ' ') || (str[i] == '\t') || (str[i] == '\n')
		|| (str[i] == '\v') || (str[i] == '\r') || (str[i] == '\f'))
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			count = -1;
		i++;
	}
	while (str[i] && (str[i] >= '0') && (str[i] <= '9'))
		res = res * 10 + str[i++] - '0';
	if (count == -1)
		return (-res);
	else
		return (res);
}

static int	parser_utils(char **arg, int x, int y)
{
	while (arg[x][y])
	{
		if ((!(arg[x][y] >= '0' && arg[x][y] <= '9')))
		{
			printf("{%s} it not a number\n", arg[x]);
			return (0);
		}
		if (ft_atoi(arg[x]) < 0)
		{
			printf("{%s}: the number is less than '0'\n", arg[x]);
			return (0);
		}
		y++;
	}
	return (1);
}

int	parser(int size, char **arg)
{
	long	x;
	long	y;

	x = 1;
	y = 0;
	if (size == 5 || size == 6)
	{
		while (arg[x])
		{
			y = 0;
			if (arg[x][y] == '-' && (arg[x][y + 1] >= '0' &&
				arg[x][y + 1] <= '9'))
				y++;
			if (parser_utils(arg, x, y) == 0)
				return (0);
			x++;
		}
	}
	else
	{
		printf("args error\n");
		return (0);
	}
	return (1);
}
