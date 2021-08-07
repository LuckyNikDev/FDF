#include "fdf.h"

void	ft_heidht_wigth(t_fdf *pointer, char *filename)
{
	int		fd;
	char	*line;
	int		flag;

	flag = 1;
	fd = open(filename, O_RDONLY);
	if (fd == -1)
	{
		pointer->error = 1;
		return ;
	}
	while (get_next_line(fd, &line))
	{
		if (flag)
		{
			pointer->wigth = (int)ft_counter(line, ' ');
			flag = 0;
		}
		(pointer->height)++;
		free(line);
	}
	close(fd);
	free(line);
}

void	ft_create_mas(t_fdf *pointer)
{
	int	i;

	i = 0;
	pointer->map = (int **)malloc(sizeof(int *) * (pointer->height + 1));
	pointer->map_color = (int **)malloc(sizeof(int *) * (pointer->height + 1));
	(pointer->map)[pointer->height] = NULL;
	(pointer->map_color)[pointer->height] = NULL;
	if (!(pointer->map) || !(pointer->map_color))
	{
		pointer->error = 1;
		return ;
	}
	while (i < pointer->height)
	{
		(pointer->map)[i] = malloc(sizeof(int) * pointer->wigth);
		(pointer->map_color)[i] = malloc(sizeof(int) * pointer->wigth);
		i++;
	}
}

void	ft_complete_map(t_fdf *pointer, char *filename)
{
	int		height;
	char	*line;
	int		fd;
	char	**result;
	int		i;

	i = 0;
	fd = open(filename, O_RDONLY);
	height = pointer->height;
	while (i < height)
	{
		get_next_line(fd, &line);
		result = ft_split(line, ' ');
		ft_complete_map_util(pointer, result, i);
		ft_free_result(result);
		free(line);
		i++;
	}
	close(fd);
}

void	ft_complete_map_util(t_fdf *pointer, char **result, int i)
{
	int		wigth;
	int		j;
	char	*comma;
	char	**color;

	j = 0;
	wigth = pointer->wigth;
	while (result[j])
	{
		comma = ft_strchr(result[j], 44);
		if (comma)
		{
			pointer->flag = 1;
			color = ft_split(result[j], ',');
			pointer->map[i][j] = ft_atoi(color[0]);
			pointer->map_color[i][j] = ft_atoi_from_16(color[1]);
			ft_free_result(color);
		}
		else
		{
			pointer->map[i][j] = ft_atoi(result[j]);
			pointer->map_color[i][j] = 0;
		}
		j++;
	}
}
