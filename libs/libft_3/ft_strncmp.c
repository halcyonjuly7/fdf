/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 17:29:22 by hramirez          #+#    #+#             */
/*   Updated: 2018/03/13 17:18:42 by hramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_strncmp(const char *s1, const char *s2, size_t n)
{
	unsigned char	*s1_copy;
	unsigned char	*s2_copy;
	size_t			index;

	index = 0;
	s1_copy = (unsigned char *)s1;
	s2_copy = (unsigned char *)s2;
	if (n == 0)
		return (0);
	while (s1_copy[index] == s2_copy[index] && index < n - 1
			&& s1_copy[index] && s2_copy[index])
	{
		if (s1_copy[index] == '\0')
			return (0);
		index++;
	}
	return (s1_copy[index] - s2_copy[index]);
}
