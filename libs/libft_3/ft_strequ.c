/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strequ.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 12:19:23 by hramirez          #+#    #+#             */
/*   Updated: 2018/03/13 17:01:25 by hramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_strequ(char const *s1, char const *s2)
{
	int	index;

	index = 0;
	if (!s1 || !s2)
		return (-1);
	return (ft_strcmp(s1, s2) ? 0 : 1);
}
