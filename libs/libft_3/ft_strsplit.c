/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 15:06:15 by hramirez          #+#    #+#             */
/*   Updated: 2018/03/13 17:30:07 by hramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	ft_count_words(char const *string, char sep)
{
	int		index;
	int		sep_count;

	index = 0;
	sep_count = 0;
	while (string[index])
	{
		while (string[index] == sep)
			index++;
		if (string[index])
			sep_count++;
		if (string[index] != sep && string[index])
			index++;
	}
	return (sep_count);
}

static char	*ft_strndup(int start, int end, char const *str)
{
	char	*substr;

	substr = ft_strsub(str, start, end - start);
	return (substr);
}

#	define INITIALIZE index=0,start=0,end=0,splitted_index=0

char		**ft_strsplit(char const *s, char c)
{
	int		start;
	int		end;
	int		index;
	int		splitted_index;
	char	**splitted;

	INITIALIZE;
	if (!s)
		return (NULL);
	splitted = (char **)malloc(sizeof(char *) * ft_count_words(s, c) + 1);
	if (splitted == NULL)
		return (NULL);
	while (s[index])
	{
		while (s[index] == c)
			index++;
		start = index;
		while (s[index] && s[index] != c)
			index++;
		if (index > start)
			splitted[splitted_index++] = ft_strndup(start, index, s);
	}
	splitted[splitted_index] = NULL;
	return (splitted);
}
