/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/10/26 16:11:44 by hramirez          #+#    #+#             */
/*   Updated: 2018/03/13 18:56:30 by hramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int		start_index(const char *str)
{
	int			index;

	index = 0;
	while ((str[index] == ' ' || str[index] == '\f' || str[index] == '\v'
			|| str[index] == '\n' || str[index] == '\r' || str[index] == '\t'))
		index++;
	return (index);
}

int				ft_atoi(const char *str)
{
	int			sign;
	int			index;
	long long	answer;

	index = start_index(str);
	sign = 1;
	answer = 0;
	if (str[index] == '-' || str[index] == '+')
	{
		if (str[index] == '-')
			sign = -1;
		index++;
	}
	while (str[index] >= '0' && str[index] <= '9')
	{
		answer = (answer * 10) + (str[index] - '0');
		index++;
	}
	return ((int)(answer * sign));
}
