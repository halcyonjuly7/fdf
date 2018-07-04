/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/26 16:11:05 by hramirez          #+#    #+#             */
/*   Updated: 2018/03/09 12:49:00 by hramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnew(size_t size)
{
	char *new_str;

	new_str = malloc(sizeof(char) * (size + 1));
	if (new_str == NULL)
		return (NULL);
	ft_bzero(new_str, size + 1);
	return (new_str);
}
