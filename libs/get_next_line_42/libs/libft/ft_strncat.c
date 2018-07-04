/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 18:56:22 by hramirez          #+#    #+#             */
/*   Updated: 2018/03/13 17:19:23 by hramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strncat(char *s1, const char *s2, size_t n)
{
	size_t index;
	size_t index2;

	index = ft_strlen(s1);
	index2 = 0;
	while (index2 < n && s2[index2])
	{
		s1[index++] = s2[index2++];
	}
	s1[index] = '\0';
	return (s1);
}
