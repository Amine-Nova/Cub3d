/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   set_2d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenmous <abenmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/04 13:01:26 by abenmous          #+#    #+#             */
/*   Updated: 2023/12/05 09:39:24 by abenmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	angle_set(t_cube *maps)
{
	if (maps->angle > 2 * PI)
		maps->angle -= 2 * PI;
	if (maps->angle < 0)
		maps->angle += 2 * PI;
}

int	check_arr(char *str)
{
	int	i;

	i = 0;
	str = ft_strtrim(str, " \n\t");
	while (str[i])
		i++;
	i -= 1;
	if (str[i] != '1')
	{
		free(str);
		return (1);
	}
	free(str);
	return (0);
}

int	store_player_side(t_cube *maps)
{
	int	i;
	int	j;

	i = 0;
	while (maps->only_map[i])
	{
		j = 0;
		while (maps->only_map[i][j])
		{
			if (maps->only_map[i][j] == 'N' || maps->only_map[i][j] == 'S'
				|| maps->only_map[i][j] == 'W' || maps->only_map[i][j] == 'E')
			{
				maps->px = (j * TILE_S3D) + (TILE_S3D / 2);
				maps->py = (i * TILE_S3D) + (TILE_S3D / 2);
				maps->player = maps->only_map[i][j];
				return (1);
			}
			j++;
		}
		i++;
	}
	return (0);
}

unsigned long	get_color(unsigned long r, unsigned long g,
unsigned long b, int a)
{
	return ((r << 24) | (g << 16) | (b << 8) | a);
}
