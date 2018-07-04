cmake_minimum_required(VERSION 3.6)
project(fdf)

set(CMAKE_C_FLAGS "-std=c99")
#set(CMAKE_C_FLAGS "-Wall -Wextra -Werror")


include_directories("libs/libft_3" "includes" "libs/minilibx")
add_subdirectory(libs/libft_3)
add_subdirectory(libs/minilibx)


add_executable(fdf src/main.c src/get_next_line.c src/fdf.c src/struct_arr.c includes/struct_arr.h src/line.c includes/line.h src/rotate.c includes/rotate.h)
target_link_libraries(fdf libft)
target_link_libraries(fdf minilibx "-framework OpenGL -framework AppKit")