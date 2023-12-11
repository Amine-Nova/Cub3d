/* ************************************************************************** */
/*	                                                                        */
/*                                                        :::      ::::::::   */
/*   map_set2D_2.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenmous <abenmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 09:57:25 by abenmous          #+#    #+#             */
/*   Updated: 2023/12/05 18:57:59 by abenmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	floor_ceiling(t_cube *maps)
{
	int	i;
	int	j;

	i = 0;
	while (i <= HEIGHT / 2)
	{
		j = -1;
		while (++j < WIDTH)
			mlx_put_pixel(maps->mlx_win, j, i, maps->cl);
		i++;
	}
	while (i < HEIGHT)
	{
		j = -1;
		while (++j < WIDTH)
			mlx_put_pixel(maps->mlx_win, j, i, maps->fl);
		i++;
	}
}

void	check_image_wh(t_cube *maps, mlx_texture_t **img)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		if (img[i]->width != 50 || img[i]->height != 60)
		{
			free_all(maps);
			ft_putstr_fd("Image Error\n", 2);
			exit (1);
		}
		i++;
	}
}

void	free_img(mlx_texture_t	**img)
{
	int	i;

	i = 0;
	while (i < 4)
	{
		free(img[i]->pixels);
		free(img[i]);
		i++;
	}
	free(img);
}

mlx_texture_t	**get_pics(t_cube *maps, mlx_texture_t **img, char **str)
{
	str[0] = ft_strtrim(maps->no, "\n");
	str[1] = ft_strtrim(maps->so, "\n");
	str[2] = ft_strtrim(maps->we, "\n");
	str[3] = ft_strtrim(maps->ea, "\n");
	img[0] = mlx_load_png(str[0]);
	img[1] = mlx_load_png(str[1]);
	img[2] = mlx_load_png(str[2]);
	img[3] = mlx_load_png(str[3]);
	free(str[0]);
	free(str[1]);
	free(str[2]);
	free(str[3]);
	return (img);
}

void	draw_map2(t_cube *maps)
{
	int				i;
	mlx_texture_t	**img;
	char			*str[4];

	i = -1;
	img = ft_calloc(sizeof(mlx_texture_t *), 4);
	if (!img)
		return ;
	img = get_pics(maps, img, str);
	protect_image(maps, img);
	maps->ray_angle = maps->angle - ((FOV_ANGLE * (PI / 180)) / 2);
	while (++i < WIDTH)
	{
		draw_ray(maps, i);
		maps->ray_angle += (FOV_ANGLE * (PI / 180)) / WIDTH;
		if (maps->ray_angle >= 2 * PI)
			maps->ray_angle = 0;
	}
	i = 0;
	while (i < WIDTH)
	{
		calculs_3d(maps, i, img);
		i++;
	}
	free_img(img);
}
