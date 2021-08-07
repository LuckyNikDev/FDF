#include "fdf.h"

void	ft_rotate_z(t_fdf *pointer)
{
	float	copy_x;
	float	copy_x1;

	copy_x = pointer->x;
	copy_x1 = pointer->x1;
	copy_x = pointer->x * cos(pointer->angle_z) - \
	pointer->y * sin(pointer->angle_z);
	pointer->y = pointer->x * sin(pointer->angle_z) + \
	pointer->y * cos(pointer->angle_z);
	pointer->x = copy_x;
	copy_x1 = pointer->x1 * cos(pointer->angle_z) - \
	pointer->y1 * sin(pointer->angle_z);
	pointer->y1 = pointer->x1 * sin(pointer->angle_z) + \
	pointer->y1 * cos(pointer->angle_z);
	pointer->x1 = copy_x1;
}

void	ft_rotate_x(t_fdf *pointer)
{
	float	copy_y;
	float	copy_y1;

	copy_y = pointer->y;
	copy_y1 = pointer->y1;
	copy_y = pointer->y * cos(pointer->angle_x) + \
	pointer->z * sin(pointer->angle_x) * pointer->ratio_z;
	pointer->z = -(pointer->y) * sin(pointer->angle_x) + \
	pointer->z * cos(pointer->angle_x) * pointer->ratio_z;
	pointer->y = copy_y;
	copy_y1 = pointer->y1 * cos(pointer->angle_x) + \
	pointer->z1 * sin(pointer->angle_x) * pointer->ratio_z;
	pointer->z1 = -(pointer->y1) * sin(pointer->angle_x) + \
	pointer->z1 * cos(pointer->angle_x) * pointer->ratio_z;
	pointer->y1 = copy_y1;
}

void	ft_rotate_y(t_fdf *pointer)
{
	float	copy_x;
	float	copy_x1;

	copy_x = pointer->x;
	copy_x1 = pointer->x1;
	copy_x = pointer->x * cos(pointer->angle_y) + \
	pointer->z * sin(pointer->angle_y);
	pointer->z = -(pointer->x) * sin(pointer->angle_y) + \
	pointer->z * cos(pointer->angle_y);
	pointer->x = copy_x;
	copy_x1 = pointer->x1 * cos(pointer->angle_y) + \
	pointer->z1 * sin(pointer->angle_y);
	pointer->z1 = -(pointer->x1) * sin(pointer->angle_y) + \
	pointer->z1 * cos(pointer->angle_y);
	pointer->x1 = copy_x1;
}

void	ft_zoom(t_fdf *pointer)
{
	pointer->x *= pointer->zoom;
	pointer->y *= pointer->zoom;
	pointer->x1 *= pointer->zoom;
	pointer->y1 *= pointer->zoom;
}

void	ft_choose_color(t_fdf *pointer)
{
	if (pointer->flag)
	{
		if ((pointer->map_color)[(int) pointer->y][(int) pointer->x])
			pointer->color = \
			(pointer->map_color)[(int) pointer->y][(int) pointer->x];
		else if ((pointer->map_color)[(int) pointer->y1][(int) pointer->x1])
			pointer->color = \
			(pointer->map_color)[(int) pointer->y1][(int) pointer->x1];
		else
			pointer->color = 0xffffff;
	}
	else
	{
		if ((pointer->map)[(int) pointer->y][(int) pointer->x] \
		|| (pointer->map)[(int) pointer->y1][(int) pointer->x1])
			pointer->color = 0xe80c0c;
		else
			pointer->color = 0xffffff;
	}
}
