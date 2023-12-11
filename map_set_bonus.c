/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_set_bonus.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenmous <abenmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 11:54:12 by abenmous          #+#    #+#             */
/*   Updated: 2023/12/06 16:24:38 by abenmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d_bonus.h"

void	draw_ray(t_cube *maps, int i)
{
	double	fisheye;

	fisheye = cos(maps->ray_angle - maps->angle);
	angle_set(maps);
	horizantal_intersection(maps);
	vertical_intersection(maps);
	if (maps->horizhit < maps->vertihit)
	{
		if (maps->ray_angle >= 0 && maps->ray_angle <= PI)
			maps->hove = 1;
		else
			maps->hove = 0;
		maps->x_touch[i] = maps->wallhx;
		maps->distance[i] = maps->horizhit * fisheye;
	}
	else
	{
		if (maps->ray_angle <= PI * 0.5 || maps->ray_angle >= PI * 1.5)
			maps->hove = 3;
		else
			maps->hove = 2;
		maps->x_touch[i] = maps->wallvy;
		maps->distance[i] = maps->vertihit * fisheye;
	}
	maps->sides[i] = maps->hove;
}

void	draw_map_bonus(t_cube *maps)
{
	int	i;
	int	j;

	i = 0;
	floor_ceiling(maps);
	draw_map2(maps);
	while (maps->only_map[i])
	{
		j = 0;
		while (maps->only_map[i][j])
		{
			if (maps->only_map[i][j] == '1')
				fill_map(maps, i, j, 0x006633FF);
			if (maps->only_map[i][j] == '0'
				|| maps->only_map[i][j] == maps->player)
				fill_map(maps, i, j, 0xFFFFE0FF);
			j++;
		}
		i++;
	}
	split_player(maps, 0xFFFA8072);
}

void	split_player(t_cube *maps, int couleur)
{
	int		w;
	int		h;
	float	py;
	float	px;

	py = maps->py / TILE_S3D;
	px = maps->px / TILE_S3D;
	px = (px * TILE_S);
	py = (py * TILE_S);
	w = py;
	h = px;
	while (h < 2 + px)
	{
		while (w < 2 + py)
		{
			mlx_put_pixel(maps->mlx_win, h, w, couleur);
			w++;
		}
		w = py;
		h++;
	}
}

void	get_fc_colors(t_cube *maps)
{
	char	**fl;
	char	**cl;
	int		floor[3];
	int		ceiling[3];
	int		i;

	i = 0;
	fl = ft_split(maps->f, ',');
	cl = ft_split(maps->c, ',');
	while (i < 3)
	{
		floor[i] = ft_atoi(fl[i]);
		ceiling[i] = ft_atoi(cl[i]);
		i++;
	}
	ft_free(fl);
	ft_free(cl);
	maps->fl = get_color(floor[0], floor[1], floor[2], 255);
	maps->cl = get_color(ceiling[0], ceiling[1], ceiling[2], 255);
}

void	open_window(t_cube *maps)
{
	maps->mlx = mlx_init(WIDTH, HEIGHT, "cub3D", 0);
	maps->mlx_win = mlx_new_image(maps->mlx, WIDTH, HEIGHT);
	set_angle(maps);
	maps->sides = ft_calloc(sizeof(int), WIDTH);
	if (!maps->sides)
		return ;
	maps->ray_angle = maps->angle - ((FOV_ANGLE * (PI / 180)) / 2);
	get_fc_colors(maps);
	draw_map_bonus(maps);
	mlx_image_to_window(maps->mlx, maps->mlx_win, 0, 0);
	mlx_loop_hook(maps->mlx, move_player, maps);
	mlx_loop(maps->mlx);
	mlx_terminate(maps->mlx);
}
