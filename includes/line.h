//
// Created by Halcyon abrah Ramirez on 6/15/18.
//

#ifndef FDF_LINE_H
#define FDF_LINE_H

#include "mlx.h"
#include "fdf.h"

typedef struct s_line_cont {
    int x_diff;
    int y_diff;
    int y_index;
    int x_index;
    int distance;
    int x_axis;
    int y_axis;
}       t_line_cont;

void plot_linelow(t_mlx_holder* holder, t_coords* coords);
void plot_linehigh(t_mlx_holder *holder, t_coords* coords);
void draw(t_mlx_holder* holder, t_sa_container* cont, int pix_size);


#endif //FDF_LINE_H
