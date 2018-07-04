/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 14:32:02 by hramirez          #+#    #+#             */
/*   Updated: 2018/03/13 16:19:56 by hramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strjoin(char const *s1, char const *s2)
{
	int		new_strlen;
	char	*new_str;
	int		str1_index;
	int		str2_index;

	if (!s1 || !s2)
		return (NULL);
	new_strlen = (ft_strlen(s1) + ft_strlen(s2));
	new_str = malloc(sizeof(char) + (new_strlen + 1));
	if (new_str == NULL)
		return (NULL);
	str1_index = 0;
	while (s1[str1_index])
	{
		new_str[str1_index] = s1[str1_index];
		str1_index++;
	}
	str2_index = 0;
	while (s2[str2_index])
	{
		new_str[str1_index + str2_index] = s2[str2_index];
		str2_index++;
	}
	new_str[str1_index + str2_index] = '\0';
	return (new_str);
}
