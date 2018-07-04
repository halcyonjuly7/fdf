//
// Created by Halcyon abrah Ramirez on 6/14/18.
//

#include <fdf.h>
#include <stdlib.h>
#include "struct_arr.h"

void append_sa(t_struct_arr* arr, int x, int y, int z) {
    t_data *data;
    if (arr->size == arr->max_size) {
        resize_sa(arr, arr->max_size * 2);
    }
    data = malloc(sizeof(t_data));
    data->x = x;
    data->y = y;
    data->z = z;
    arr->arr[arr->size++] = data;
}


void resize_sa(t_struct_arr* arr, int new_size) {
    t_data** new_arr;
    int index;

    index = 0;
    new_arr = malloc(new_size * sizeof(t_data *));
    while (index < arr->size) {
        new_arr[index] = arr->arr[index];
        index++;
    }
    free(arr->arr);
    arr->max_size = new_size;
    arr->arr = new_arr;
    arr->arr[index] = '\0';
}

void cont_insert(t_sa_container* cont, t_struct_arr *num_arr)
{
    if (cont->size == cont->max_size)
        cont_resize(cont, cont->max_size * 2);
    cont->arr[cont->size] = num_arr;
    cont->size++;

}


void cont_resize(t_sa_container* cont, int new_size)
{
    int index;
    t_struct_arr **new_arr;

    new_arr = malloc(new_size * sizeof(t_struct_arr *));
    index = 0;
    while (index < cont->size) {
        new_arr[index] = cont->arr[index];
        index++;
    }
    free(cont->arr);
    cont->arr = new_arr;
    cont->max_size = new_size;

}
