//
// Created by Halcyon abrah Ramirez on 6/14/18.
//

#ifndef FDF_INT_ARR_H
#define FDF_INT_ARR_H



typedef struct s_data {
    float x;
    float y;
    float z;
} t_data;

typedef struct s_struct_arr {
    int max_size;
    int size;
    t_data **arr;
}   t_struct_arr;


typedef struct s_sa_container {
    int size;
    int max_size;
    int width;
    int height;
    t_struct_arr **arr;
}   t_sa_container;


void cont_insert(t_sa_container* cont, t_struct_arr *sa);
void cont_resize(t_sa_container* cont, int new_size);

void append_sa(t_struct_arr* arr, int x, int y, int z);
void resize_sa(t_struct_arr* arr, int new_size);
#endif //FDF_INT_ARR_H
