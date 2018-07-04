
#include "libft.h"
#include "get_next_line.h"
#include "mlx.h"
#include "fdf.h"
#include <fcntl.h>
#include <stdlib.h>
#include "line.h"


int main(int argc, char **argv) {

    mlx_init();
    if(argc == 2)
    {
        int fd = open(argv[1], O_RDONLY);
        t_sa_container *map_data = parser(fd);

        void *mlx;
        void *window;

        mlx = mlx_init();
        window = mlx_new_window(mlx, 1500, 1500, "Title");
        mlx_clear_window(mlx, window);
        t_mlx_holder holder;
        holder.mlx = mlx;
        holder.window = window;
        draw(&holder, map_data, 1);
        mlx_loop(mlx);
        return (0);

    }
    return 0;
}