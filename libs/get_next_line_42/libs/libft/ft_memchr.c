/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 14:36:52 by hramirez          #+#    #+#             */
/*   Updated: 2018/03/10 15:36:25 by hramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memchr(const void *s, int c, size_t n)
{
	unsigned int	index;
	unsigned char	*src_copy;

	index = 0;
	src_copy = (unsigned char *)s;
	while (index < n)
	{
		if (src_copy[index] == (unsigned char)c)
			return ((void *)&src_copy[index]);
		index++;
	}
	return (NULL);
}
