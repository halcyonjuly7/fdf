//
// Created by Halcyon abrah Ramirez on 6/15/18.
//

#include "line.h"
#include "math.h"
#include "rotate.h"
#include <unistd.h>
#include <stdlib.h>
#define D_VARS  int h;int w;float x_m;float y_m;
#define D_VARS1 t_struct_arr *cur_c;t_coords cds;t_coords *starting_point;


void plot_linelow(t_mlx_holder* holder, t_coords* coords)
{
    int index;
    t_line_cont cont;

    cont.x_diff = coords->x1 - coords->x0;
    cont.y_diff = coords->y1  - coords->y0;
    cont.y_index = 1;
    if (cont.y_diff < 0)
    {
        cont.y_index = -1;
        cont.y_diff = -cont.y_diff;
    }
    cont.distance = (2*cont.y_diff) - cont.x_diff;
    cont.y_axis = coords->y0;
    index = coords->x0;
    while(index < coords->x1)
    {
        mlx_pixel_put(holder->mlx,holder->window, index, cont.y_axis,
                      0xffffff);
        if (cont.distance > 0)
        {
            cont.y_axis = cont.y_axis + cont.y_index;
            cont.distance = cont.distance - (2 * cont.x_diff);
        }
        cont.distance = cont.distance + (2*cont.y_diff);
        index++;
    }
}

void plot_linehigh(t_mlx_holder* holder, t_coords *coords)
{
    int index;
    t_line_cont cont;

    cont.x_diff = coords->x1 - coords->x0;
    cont.y_diff = coords->y1 - coords->y0;
    cont.x_index = 1;

    if(cont.x_diff < 0) {
        cont.x_index = -1;
        cont.x_diff = -cont.x_diff;
    }
    cont.distance = (2 *cont.x_diff) - cont.y_diff;
    cont.x_axis = coords->x0;

    index = coords->y0;
    while (index < coords->y1)
    {
        mlx_pixel_put(holder->mlx, holder->window, cont.x_axis, index,
                      0xffffff);
        if (cont.distance > 0)
        {
            cont.x_axis = cont.x_axis + cont.x_index;
            cont.distance = cont.distance - (2 * cont.y_diff);
        }
        cont.distance = cont.distance + (2 * cont.x_diff);
        index++;
    }
}

void plot_line(t_mlx_holder* holder, t_coords *coords)
{
    float tmp;
    if (fabsf(coords->y1 - coords->y0) < fabsf(coords->x1 - coords->x0))
    {
        if (coords->x0 > coords->x1)
        {
            tmp = coords->x0;
            coords->x0 = coords->x1;
            coords->x1 = tmp;
            tmp = coords->y0;
            coords->y0 = coords->y1;
            coords->y1 = tmp;

        }
        plot_linelow(holder, &coords);
    } else {
        if (coords->y0 > coords->y1) {
            tmp = coords->x0;
            coords->x0 = coords->x1;
            coords->x1 = tmp;
            tmp = coords->y0;
            coords->y0 = coords->y1;
            coords->y1 = tmp;
        }
        plot_linehigh(holder, &coords);
    }
}


t_coords *find_starting_point(int rows, int cols, int cell_width, int pix_size)
{
    int total_width;
    int total_height;
    t_coords *start_point;

    total_width  = cols * cell_width;
    total_height = rows * cell_width;
    start_point = malloc(sizeof(t_coords));
    start_point->x0 = (pix_size / 2) - (total_width / 2);
    start_point->y0 = (pix_size / 2) - (total_height / 2);
    if (cols % 2 == 0)
        start_point->x0 = start_point->x0 -  (cell_width / 2);
    if (rows % 2 == 0)
        start_point->y0 = start_point->y0 - (cell_width / 2);
    start_point->x1 = total_width / 2;
    start_point->y1 = total_height / 2;
    return start_point;
}

void center_coordinates(t_coords *starting_point, t_sa_container* cont)
{
    int row;
    int col;

    row = 0;
    while (row < cont->height)
    {
        col = 0;
        while (col < cont->width)
        {
            cont->arr[row]->arr[col]->x += starting_point->x0;
            cont->arr[row]->arr[col]->y += starting_point->y0;
            col++;
        }
        row++;
    }
}


void draw(t_mlx_holder* holder, t_sa_container* cont, int pix_size) {
    int h;
    int w;
    float x_m;
    float y_m;
    t_struct_arr *cur_c;
    t_coords cds;
    t_coords *starting_point;

    h = 0;
    x_m = 50;
    y_m = 50;
    starting_point = find_starting_point(cont->height, cont->width, 50, 1500);
    rotate(cont);
    center_coordinates(starting_point, cont);
    while (h  < cont->height) {
        w = 0;
        while ((w + 1)  < cont->width) {
            cur_c = cont->arr[h];
            cds.x0 = cur_c->arr[w]->x + (w * x_m);
            cds.y0 = cur_c->arr[w]->y + (h * y_m);
            cds.x1 = cur_c->arr[w + 1]->x + ((w + 1) * x_m);
            cds.y1 = cur_c->arr[w + 1]->y + (h * y_m);
            plot_linelow(holder, &cds);
            if (h + 1 < cont->height) {
                cds.x1 = cont->arr[h + 1]->arr[w]->x + (w * x_m);
                cds.y1 = cont->arr[h + 1]->arr[w]->y + ((h + 1) * y_m);
                plot_linehigh(holder, &cds);
                if (w + 1 == cont->width - 1) {
                    cds.x0 = cur_c->arr[w + 1]->x + ((w + 1) * x_m);
                    cds.y0 = cur_c->arr[w + 1]->y + (h * y_m);
                    cds.x1 = cont->arr[h + 1]->arr[w + 1]->x + ((w + 1) * x_m);
                    cds.y1 = cont->arr[h + 1]->arr[w + 1]->y + ((h + 1) * y_m);
                    plot_linehigh(holder, &cds);
                }
            }
            w++;
        }
        h++;
    }
}


