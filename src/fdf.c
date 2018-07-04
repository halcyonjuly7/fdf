//
// Created by Halcyon abrah Ramirez on 6/14/18.
//


#include "fdf.h"
#include "get_next_line.h"
#include "libft.h"

t_sa_container* parser(int fd) {
     char *line;
     char **splitted;
     int index;
    t_struct_arr* struct_arr;
    t_sa_container* container;
     int get_width;

     container = malloc(sizeof(t_sa_container));
     container->arr = malloc(4 * sizeof(t_struct_arr));
     container->size = 0;
     container->max_size = 4;
     container->height = 0;
     container->width = 0;
     get_width = -1;
    while (get_next_line(fd, &line) != 0) {
        index = 0;
        struct_arr = malloc(sizeof(t_struct_arr));
        struct_arr->arr = malloc(10 * sizeof(t_data));
        struct_arr->size = 0;
        struct_arr->max_size = 10;
        splitted = ft_strsplit(line, ' ');
        while (splitted[index]) {
            append_sa(struct_arr, index, container->height, ft_atoi(splitted[index]));
            index++;
            if (get_width == -1)
                container->width++;

        }
        container->height++;
        cont_insert(container, struct_arr);
        get_width = 1;
    }
    return container;
}