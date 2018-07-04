
#ifndef FDF_H
#define FDF_H

#include "struct_arr.h"
#include "mlx.h"



typedef struct s_mlx_holder {
    void *mlx;
    void *window;
}              t_mlx_holder;


typedef struct s_coords {
    float x0;
    float y0;
    float x1;
    float y1;
} t_coords;

t_sa_container* parser(int fd);

#endif FDF_H