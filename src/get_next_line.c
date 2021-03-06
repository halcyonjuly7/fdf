//
// Created by Halcyon abrah Ramirez on 4/7/18.
//

#include "get_next_line.h"
# include <unistd.h>
#include <libft.h>
#include <stdio.h>
#include <fcntl.h>


void arr_insert(t_arr *arr, char new_char)
{
    if(arr->contents == arr->size)
        arr_resize(arr, arr->size * 2);
    arr->buffer[arr->contents] = new_char;
    ++arr->contents;
	arr->buffer[arr->contents] = '\0';


}

void arr_resize(t_arr *arr, int new_size)
{
    int index;
    char *new_str;

    index = 0;
    new_str = ft_strnew(new_size);
    while(arr->buffer[index])
	{
		new_str[index] = arr->buffer[index];
		index++;
	}
    ft_strdel(&arr->buffer);
	arr->buffer = new_str;
	arr->size = new_size;

}


int get_next_line(const int fd, char **line)
{
    char    buffer[BUFF_SIZE+1];
    t_arr   local_buffer;
    int     index;
    int     cache_ind;
	int 	read_file;
    static  t_arr *cache;

	if (fd < 0 || read(fd, 0, 0))
		return (-1);

    if(!cache)
    {
		if (!(cache = malloc(sizeof(t_arr))))
			return (-1);
        cache->size = BUFF_SIZE;
        cache->contents = 0;
		cache->start = NULL;
		cache->offset = 0;
		if (!(cache->buffer = ft_strnew(BUFF_SIZE)))
			return (-1);
    }

    if (!(local_buffer.buffer = ft_strnew(BUFF_SIZE)))
		return (-1);
	local_buffer.size = BUFF_SIZE;
	local_buffer.contents = 0;
	if (ft_strchr(cache->buffer, '\n'))
	{
		char *cpy;
		cache_ind = 0;
		while(cache->buffer[cache_ind] != '\n')
			cache_ind++;
		*line = ft_strsub(cache->buffer, 0, cache_ind);
		cpy = cache->buffer;
		cache->buffer = ft_strdup(&(cache->buffer[cache_ind+1]));
		cache->contents = ft_strlen(cache->buffer);
		cache->size = cache->contents;
		ft_strdel(&cpy);
		ft_strdel(&local_buffer.buffer);
		return (1);
	}

    while ((read_file = read(fd, buffer, BUFF_SIZE)) > 0)
    {
        index = 0;
		buffer[read_file] = '\0';
        while (buffer[index])
        {
            if (buffer[index] == '\n')
            {
				index++;
                if (cache->contents != 0)
                {
					*line = ft_strjoin(cache->buffer,
									   local_buffer.buffer);
					ft_strclr(cache->buffer);
					cache->contents = 0;
					cache->offset = 0;
                }
				else
					*line = ft_strdup(local_buffer.buffer);
				ft_strdel(&local_buffer.buffer);
                while (buffer[index])
					arr_insert(cache, buffer[index++]);
				return (1);
            }
            else
                arr_insert(&local_buffer, buffer[index]);
			index++;
        }
		ft_strclr(buffer);
    }
	if(local_buffer.contents != 0 || cache->contents !=0)
	{
		*line = ft_strjoin(cache->buffer, local_buffer.buffer);
		cache->contents = 0;
		ft_strdel(&local_buffer.buffer);
		return (1);
	}
	ft_strdel(&local_buffer.buffer);
	ft_strdel(&cache->buffer);
	ft_memdel((void *)&cache);
    return (0);
}

