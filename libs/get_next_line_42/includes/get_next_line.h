/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hramirez <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/04/07 14:26:39 by hramirez          #+#    #+#             */
/*   Updated: 2018/04/07 14:26:47 by hramirez         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_GET_NEXT_LINE_H
#define GET_NEXT_LINE_GET_NEXT_LINE_H
#define BUFF_SIZE 90

int get_next_line(const int fd, char **line);
typedef struct		s_array
{
	int				size;
	int				contents;
	char 			*buffer;
	char			*start;
	int 			offset;
}					t_arr;

typedef struct		s_cache
{
	int				current;
	int				size;
	char 			**lines;
}					t_cache;

void				arr_insert(t_arr *arr, char new_char);
void				arr_resize(t_arr *arr, int new_size);

#endif
