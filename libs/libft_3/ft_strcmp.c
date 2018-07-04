/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 13:46:47 by hramirez          #+#    #+#             */
/*   Updated: 2018/03/05 15:32:41 by hramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strcmp(const char *s1, const char *s2)
{
	unsigned int	index;
	unsigned char	*s1_copy;
	unsigned char	*s2_copy;

	index = 0;
	s1_copy = (unsigned char *)s1;
	s2_copy = (unsigned char *)s2;
	while (s1_copy[index] == s2_copy[index])
	{
		if (s1[index] == '\0')
			return (0);
		index++;
	}
	return (s1_copy[index] - s2_copy[index]);
}
