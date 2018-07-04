/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 14:54:53 by hramirez          #+#    #+#             */
/*   Updated: 2018/03/13 17:20:43 by hramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int					ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned char	*str_1copy;
	unsigned char	*str_2copy;
	size_t			index;

	str_1copy = (unsigned char *)s1;
	str_2copy = (unsigned char *)s2;
	index = 0;
	while (index < n)
	{
		if (str_1copy[index] != str_2copy[index])
			return (str_1copy[index] - str_2copy[index]);
		index++;
	}
	return (0);
}
