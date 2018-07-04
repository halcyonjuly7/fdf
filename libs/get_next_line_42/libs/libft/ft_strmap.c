/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 11:49:55 by hramirez          #+#    #+#             */
/*   Updated: 2018/03/13 17:00:50 by hramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strmap(char const *s, char (*f)(char))
{
	int		index;
	char	*new_str;

	index = 0;
	if (!s || !f)
		return (NULL);
	new_str = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (new_str == NULL)
		return (NULL);
	while (s[index])
	{
		new_str[index] = f(s[index]);
		index++;
	}
	new_str[index] = '\0';
	return (new_str);
}
