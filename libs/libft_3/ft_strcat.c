/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcat.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 16:13:04 by hramirez          #+#    #+#             */
/*   Updated: 2018/02/26 14:06:22 by hramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strcat(char *s1, const char *s2)
{
	int index;
	int index2;

	index = ft_strlen(s1);
	index2 = 0;
	while (s2[index2])
	{
		s1[index++] = s2[index2++];
	}
	s1[index] = '\0';
	return (s1);
}
