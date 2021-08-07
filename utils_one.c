#include "fdf.h"

void	ft_free_map(t_fdf *pointer, int i)
{
	if (pointer->map)
	{
		while (--i >= 0)
		{
			if (pointer->map[i])
				free(pointer->map[i]);
		}
		free(pointer->map);
	}
}

void	ft_free_map_color(t_fdf *pointer, int i)
{
	if (pointer->map_color)
	{
		while (--i >= 0)
		{
			if (pointer->map_color[i])
				free(pointer->map_color[i]);
		}
		free(pointer->map_color);
	}
}

void	ft_free_result(char **result)
{
	int	i;

	i = 0;
	while (result[i])
		free(result[i++]);
	free(result[i]);
	free(result);
}

int	ft_atoi_from_16(char *mas)
{
	int	result;
	int	i;
	int	order;

	i = ft_strlen(mas);
	i--;
	order = 1;
	result = 0;
	while (i >= 0)
	{
		if (mas[i] >= '0' && mas[i] <= '9')
			result += (mas[i] - 48) * order;
		else
			result += (ft_atoi_from_16_util(mas[i]) + 9) * order;
		i--;
		order = order * 16;
	}
	return (result);
}

int	ft_atoi_from_16_util(char c)
{
	int		i;
	char	mas_symbols[8];

	mas_symbols[0] = '1';
	mas_symbols[1] = 'a';
	mas_symbols[2] = 'b';
	mas_symbols[3] = 'c';
	mas_symbols[4] = 'd';
	mas_symbols[5] = 'e';
	mas_symbols[6] = 'f';
	mas_symbols[7] = '\0';
	i = 0;
	while (mas_symbols[i])
	{
		if (mas_symbols[i] == c)
			return (i);
		i++;
	}
	return (0);
}
