/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memccpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/20 16:28:27 by hramirez          #+#    #+#             */
/*   Updated: 2018/03/10 15:36:58 by hramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void					*ft_memccpy(void *dst, const void *src, int c, size_t n)
{
	unsigned char		*dest_copy;
	const unsigned char	*source_copy;

	dest_copy = dst;
	source_copy = src;
	while (n)
	{
		if ((*dest_copy++ = *source_copy++) == (unsigned char)c)
			return (dest_copy);
		n--;
	}
	return (0);
}
