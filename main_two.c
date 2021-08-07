#include "fdf.h"

void	ft_redraw_image(t_fdf *pointer)
{
	void	*tmp;

	tmp = pointer->img;
	pointer->img = mlx_new_image(pointer->mlx_ptr, 1920, 1080);
	pointer->addr = mlx_get_data_addr(pointer->img, \
	&pointer->bits_per_pixel, &pointer->line_lenght, &pointer->endian);
	mlx_clear_window(pointer->mlx_ptr, pointer->win_ptr);
	draw(pointer);
	mlx_put_image_to_window(pointer->mlx_ptr, \
	pointer->win_ptr, pointer->img, 0, 0);
	mlx_destroy_image(pointer->mlx_ptr, tmp);
}

void	ft_drow_scene(t_fdf *pointer)
{
	pointer->mlx_ptr = mlx_init();
	pointer->win_ptr = mlx_new_window(pointer->mlx_ptr, 1920, 1080, "FDF");
	pointer->img = mlx_new_image(pointer->mlx_ptr, 1920, 1080);
	pointer->addr = mlx_get_data_addr(pointer->img, \
	&pointer->bits_per_pixel, &pointer->line_lenght, &pointer->endian);
	draw(pointer);
	mlx_hook(pointer->win_ptr, 2, 0, deal_key, pointer);
	mlx_put_image_to_window(pointer->mlx_ptr, \
	pointer->win_ptr, pointer->img, 0, 0);
	mlx_loop(pointer->mlx_ptr);
}

t_fdf	*ft_create_list(void)
{
	t_fdf	*result;

	result = malloc(sizeof(t_fdf));
	if (result)
	{
		result->wigth = 0;
		result->height = 0;
		result->map = NULL;
		result->map_color = NULL;
		result->error = 0;
		result->zoom = 10;
		result->shift_x = 0;
		result->shift_y = 0;
		result->angle_x = -1.22;
		result->angle_y = 0.697;
		result->angle_z = -0.087;
		result->ratio_z = 1;
		result->flag = 0;
	}
	return (result);
}

void	draw_util_two(t_fdf *pointer, int x, int y)
{
	pointer->x = x;
	pointer->y = y;
	pointer->x1 = x;
	pointer->y1 = y + 1;
}
