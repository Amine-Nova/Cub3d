/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   move_player.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenmous <abenmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:45:42 by abenmous          #+#    #+#             */
/*   Updated: 2023/12/06 16:11:34 by abenmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_walls(t_cube *p)
{
	float	fi;
	float	fj;
	int		i;
	int		j;

	fj = p->tmpx / TILE_S3D;
	fi = p->tmpy / TILE_S3D;
	i = (int)fi;
	j = (int)fj;
	if (p->only_map[i][j] == '1')
		return (0);
	i = (p->tmpy + 10) / TILE_S3D;
	if (p->only_map[i][j] == '1')
		return (0);
	i = (p->tmpy - 10) / TILE_S3D;
	if (p->only_map[i][j] == '1')
		return (0);
	j = (p->tmpx + 10) / TILE_S3D;
	if (p->only_map[i][j] == '1')
		return (0);
	j = (p->tmpx - 10) / TILE_S3D;
	if (p->only_map[i][j] == '1')
		return (0);
	return (1);
}

void	move_player2(t_cube *maps)
{
	if (mlx_is_key_down(maps->mlx, MLX_KEY_ESCAPE))
		mlx_close_window(maps->mlx);
	if (mlx_is_key_down(maps->mlx, MLX_KEY_W))
	{
		maps->tmpx += 5 * cos(maps->angle);
		maps->tmpy += 5 * sin(maps->angle);
	}
	if (mlx_is_key_down(maps->mlx, MLX_KEY_LEFT))
		maps->angle -= 0.03;
	if (mlx_is_key_down(maps->mlx, MLX_KEY_RIGHT))
		maps->angle += 0.03;
	if (maps->angle > 2 * PI)
		maps->angle -= 2 * PI;
	if (maps->angle < 0)
		maps->angle += 2 * PI;
	if (check_walls(maps))
	{
		maps->px = maps->tmpx;
		maps->py = maps->tmpy;
		draw_map(maps);
	}
}

void	move_player(void *m)
{
	t_cube	*maps;

	maps = m;
	maps->tmpx = maps->px;
	maps->tmpy = maps->py;
	if (mlx_is_key_down(maps->mlx, MLX_KEY_S))
	{
		maps->tmpx -= 5 * cos(maps->angle);
		maps->tmpy -= 5 * sin(maps->angle);
	}
	if (mlx_is_key_down(maps->mlx, MLX_KEY_D))
	{
		maps->tmpx -= 5 * sin(maps->angle);
		maps->tmpy += 5 * cos(maps->angle);
	}
	if (mlx_is_key_down(maps->mlx, MLX_KEY_A))
	{
		maps->tmpx += 5 * sin(maps->angle);
		maps->tmpy -= 5 * cos(maps->angle);
	}
	move_player2(maps);
}
