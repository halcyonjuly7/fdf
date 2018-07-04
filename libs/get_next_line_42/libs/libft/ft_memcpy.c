/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/23 21:07:49 by hramirez          #+#    #+#             */
/*   Updated: 2018/03/13 17:20:15 by hramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void				*ft_memcpy(void *dst, const void *src, size_t n)
{
	unsigned char	*dst_copy;
	unsigned char	*src_copy;
	size_t			index;

	index = 0;
	dst_copy = (unsigned char*)dst;
	src_copy = (unsigned char*)src;
	while (index < n)
	{
		dst_copy[index] = src_copy[index];
		index++;
	}
	return (dst);
}
