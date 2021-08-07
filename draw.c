#include "fdf.h"

void	draw(t_fdf *pointer)
{
	int	x;
	int	y;

	y = 0;
	while (y < pointer->height)
	{
		x = 0;
		while (x < pointer->wigth)
		{
			if (x < pointer->wigth - 1)
			{
				draw_util_one(pointer, x, y);
				draw_line(pointer);
			}
			if (y < pointer->height - 1)
			{
				draw_util_two(pointer, x, y);
				draw_line(pointer);
			}
			x++;
		}
		y++;
	}
}

void	draw_util_one(t_fdf *pointer, int x, int y)
{
	pointer->x = x;
	pointer->y = y;
	pointer->x1 = x + 1;
	pointer->y1 = y;
}

void	draw_line(t_fdf *pointer)
{
	pointer->z = (pointer->map)[(int) pointer->y][(int) pointer->x];
	pointer->z1 = (pointer->map)[(int) pointer->y1][(int) pointer->x1];
	ft_choose_color(pointer);
	ft_zoom(pointer);
	ft_rotate_z(pointer);
	ft_rotate_x(pointer);
	ft_rotate_y(pointer);
	pointer->x += pointer->shift_x;
	pointer->y += pointer->shift_y;
	pointer->x1 += pointer->shift_x;
	pointer->y1 += pointer->shift_y;
	bresenham(pointer);
}

void	bresenham(t_fdf *pointer)
{
	float		x_step;
	float		y_step;
	int			max;

	x_step = pointer->x1 - pointer->x;
	y_step = pointer->y1 - pointer->y;
	max = (int) max_mod_number(x_step, y_step);
	x_step /= max;
	y_step /= max;
	while ((int)(pointer->x - pointer->x1) || (int)(pointer->y - pointer->y1))
	{
		if (pointer->x >= 1920 || pointer->x <= 0)
			return ;
		if (pointer->y >= 1080 || pointer->y <= 0)
			return ;
		my_mlx_pixel_put(pointer, pointer->x, pointer->y, pointer->color);
		pointer->x += x_step;
		pointer->y += y_step;
	}
}

float	max_mod_number(float a, float b)
{
	if (a < 0)
		a *= -1;
	if (b < 0)
		b *= -1;
	if (a > b)
		return (a);
	else
		return (b);
}
