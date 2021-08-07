#include "fdf.h"

void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color)
{
	char	*dst;

	dst = data->addr + (y * data->line_lenght + x * (data->bits_per_pixel / 8));
	*(unsigned int *)dst = color;
}

int	deal_key(int key, t_fdf *pointer)
{
	if (key == 53)
	{
		mlx_destroy_image(pointer->mlx_ptr, pointer->img);
		exit(0);
	}
	else if (key == 12)
		pointer->angle_x += 0.05;
	else if (key == 0)
		pointer->angle_x -= 0.05;
	else if (key == 13)
		pointer->angle_y += 0.05;
	else if (key == 1)
		pointer->angle_y -= 0.05;
	else if (key == 14)
		pointer->angle_z += 0.05;
	else if (key == 2)
		pointer->angle_z -= 0.05;
	else
		deal_key_util(key, pointer);
	ft_redraw_image(pointer);
	return (0);
}

void	deal_key_util(int key, t_fdf *pointer)
{
	if (key == 15)
		pointer->ratio_z += 0.3;
	else if (key == 3)
		pointer->ratio_z -= 0.3;
	else if (key == 123)
		pointer->shift_x += 30;
	else if (key == 124)
		pointer->shift_x -= 30;
	else if (key == 125)
		pointer->shift_y -= 30;
	else if (key == 126)
		pointer->shift_y += 30;
	else if (key == 24)
		pointer->zoom += 5;
	else if (key == 27)
		pointer->zoom -= 3;
}

int	main(int argc, char **argv)
{
	t_fdf	*pointer;

	if (argc == 2)
	{
		pointer = ft_create_list();
		if (pointer)
		{
			ft_create_map(pointer, argv[1]);
			if (!(pointer->error))
				ft_drow_scene(pointer);
			ft_free_map_color(pointer, pointer->height);
			ft_free_map(pointer, pointer->height);
			free(pointer);
		}
	}
	return (0);
}

void	ft_create_map(t_fdf *pointer, char *filename)
{
	ft_heidht_wigth(pointer, filename);
	if (!(pointer->error))
		ft_create_mas(pointer);
	if (!(pointer->error))
		ft_complete_map(pointer, filename);
}
