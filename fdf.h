#ifndef FDF_H
# define FDF_H

# include "get_next_line/get_next_line.h"
# include "libft_finish/libft.h"
# include <fcntl.h>
# include <stdlib.h>
# include <unistd.h>
# include <mlx.h>
# include <math.h>

typedef struct s_fdf
{
	float	x;
	float	x1;
	float	y;
	float	y1;
	float	z;
	float	z1;
	void	*img;
	char	*addr;
	int		bits_per_pixel;
	int		line_lenght;
	int		endian;
	int		**map;
	int		**map_color;
	int		flag;
	int		wigth;
	int		height;
	int		error;
	int		zoom;
	int		color;
	int		shift_x;
	int		shift_y;
	float	angle_x;
	float	angle_y;
	float	angle_z;
	float	ratio_z;
	void	*mlx_ptr;
	void	*win_ptr;
}			t_fdf;

t_fdf	*ft_create_list(void);
void	ft_heidht_wigth(t_fdf *pointer, char *filename);
void	ft_create_mas(t_fdf *pointer);
void	ft_complete_map(t_fdf *pointer, char *filename);
void	ft_complete_map_util(t_fdf *pointer, char **result, int i);
t_fdf	*ft_create_list(void);
void	ft_free_map(t_fdf *pointer, int i);
void	ft_free_result(char **result);
void	ft_create_map(t_fdf *pointer, char *filename);
float	max_mod_number(float a, float b);
void	bresenham(t_fdf *pointer);
int		deal_key(int key, t_fdf *pointer);
void	draw(t_fdf *pointer);
void	my_mlx_pixel_put(t_fdf *data, int x, int y, int color);
int		ft_atoi_from_16(char *mas);
int		ft_atoi_from_16_util(char c);
void	ft_free_map_color(t_fdf *pointer, int i);
void	ft_drow_scene(t_fdf *pointer);
void	deal_key_util(int key, t_fdf *pointer);
void	ft_redraw_image(t_fdf *pointer);
void	ft_choose_color(t_fdf *pointer);
void	ft_zoom(t_fdf *pointer);
void	ft_rotate_z(t_fdf *pointer);
void	ft_rotate_x(t_fdf *pointer);
void	ft_rotate_y(t_fdf *pointer);
void	draw_line(t_fdf *pointer);
void	draw_util_one(t_fdf *pointer, int x, int y);
void	draw_util_two(t_fdf *pointer, int x, int y);

#endif