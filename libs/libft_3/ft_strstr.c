/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 19:35:39 by hramirez          #+#    #+#             */
/*   Updated: 2018/03/05 19:49:12 by hramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strstr(const char *haystack, const char *needle)
{
	int		hstck_ind;
	int		needle_len;
	int		needle_ind;
	char	*hstck_copy;

	hstck_ind = 0;
	needle_ind = 0;
	hstck_copy = (char *)haystack;
	needle_len = ft_strlen(needle);
	if ((hstck_copy[hstck_ind] == needle[needle_ind]
			&& !hstck_copy[hstck_ind]) || !needle[needle_ind])
		return ((char *)&hstck_copy[hstck_ind]);
	while (hstck_copy[hstck_ind])
	{
		while (hstck_copy[hstck_ind + needle_ind] == needle[needle_ind])
		{
			if (needle_ind == (needle_len - 1))
				return (hstck_copy + hstck_ind);
			needle_ind++;
		}
		needle_ind = 0;
		hstck_ind++;
	}
	return (0);
}
