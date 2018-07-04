/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsub.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 12:38:29 by hramirez          #+#    #+#             */
/*   Updated: 2018/03/13 17:04:27 by hramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strsub(char const *s, unsigned int start, size_t len)
{
	size_t	new_strindex;
	char	*new_str;

	new_strindex = 0;
	if (!s)
		return (NULL);
	new_str = malloc(sizeof(char) * (len + 1));
	if (new_str == NULL)
		return (NULL);
	while (s[start] && new_strindex < len)
	{
		new_str[new_strindex] = s[start];
		new_strindex++;
		start++;
	}
	new_str[new_strindex] = '\0';
	return (new_str);
}
