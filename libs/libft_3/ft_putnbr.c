/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/27 18:42:35 by hramirez          #+#    #+#             */
/*   Updated: 2018/03/02 15:00:52 by hramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void		ft_putnbr(int nb)
{
	int		is_negative;
	int		rem;
	int		index;
	char	str[11];

	is_negative = (nb < 0) ? -1 : 1;
	index = 0;
	if (nb == 0)
		ft_putchar('0');
	while (nb != 0)
	{
		rem = nb % 10;
		str[index++] = (rem * is_negative) + '0';
		nb = nb / 10;
	}
	if (is_negative == -1)
		str[index++] = '-';
	while (index > 0)
		ft_putchar(str[--index]);
}
