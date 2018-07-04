cmake_minimum_required(VERSION 3.0)

set(MINILIBX_SRCS
        font.c
        mlx.h
        mlx_init_loop.m
        mlx_int.h
        mlx_int_str_to_wordtab.c
        mlx_new_image.m
        mlx_new_window.h
        mlx_new_window.m
        mlx_shaders.c
        mlx_xpm.c)

SET(LIB_TYPE STATIC)

add_library(minilibx  ${MINILIBX_SRCS})