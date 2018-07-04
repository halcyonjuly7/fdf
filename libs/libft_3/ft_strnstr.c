/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/21 19:35:39 by hramirez          #+#    #+#             */
/*   Updated: 2018/03/13 17:16:10 by hramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_strnstr(const char *h, const char *n, size_t len)
{
	size_t	hstck_ind;
	size_t	needle_len;
	size_t	needle_ind;
	char	*hstck_cpy;

	hstck_ind = 0;
	needle_ind = 0;
	hstck_cpy = (char *)h;
	needle_len = ft_strlen(n);
	if ((hstck_cpy[hstck_ind] == n[needle_ind]
				&& !hstck_cpy[hstck_ind]) || !n[needle_ind])
		return ((char *)&hstck_cpy[hstck_ind]);
	while (hstck_ind < len && hstck_cpy[hstck_ind])
	{
		while (hstck_cpy[hstck_ind + needle_ind] == n[needle_ind]
				&& (hstck_ind + needle_ind) < len)
		{
			if (needle_ind == (needle_len - 1))
				return (hstck_cpy + hstck_ind);
			needle_ind++;
		}
		needle_ind = 0;
		hstck_ind++;
	}
	return (0);
}
