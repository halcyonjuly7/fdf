cmake_minimum_required(VERSION 3.0)

#set(CMAKE_BUILD_TYPE  Debug)
set(CMAKE_C_FLAGS "-Wall -Wextra -Werror")
set(LIBFT_INCLUDE_DIR libs/libft)
set(FILLIT_INCLUDE_DIR includes)
project(get_next_line)
add_subdirectory(${LIBFT_INCLUDE_DIR})
include_directories(${FILLIT_INCLUDE_DIR})
#add_executable(get_next_line
#        src/get_next_line.c)
#target_link_libraries(get_next_line libft)
#ADD_DEPENDENCIES(get_next_line libft)