/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/02/28 21:05:20 by hramirez          #+#    #+#             */
/*   Updated: 2018/03/07 13:52:55 by hramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem))
{
	t_list	*current;
	t_list	*new_lst;
	t_list	*new_lst_head;

	new_lst_head = NULL;
	while (lst)
	{
		new_lst = malloc(sizeof(size_t));
		if (!new_lst)
			return (NULL);
		new_lst = f(lst);
		if (!new_lst_head)
		{
			new_lst_head = new_lst;
			current = new_lst;
		}
		else
		{
			current->next = new_lst;
			current = current->next;
		}
		lst = lst->next;
	}
	return (new_lst_head);
}
