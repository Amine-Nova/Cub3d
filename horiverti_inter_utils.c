/* ************************************************************************** */
/*	                                                                          */
/*                                                        :::      ::::::::   */
/*   horiverti_inter_utils.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenmous <abenmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:05:58 by abenmous          #+#    #+#             */
/*   Updated: 2023/12/02 19:58:07 by abenmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

float	distance_b(float xa, float ya, float xb, float yb)
{
	return (sqrt(((xa - xb) * (xa - xb)) + ((ya - yb) * (ya - yb))));
}

int	hitwall(t_cube *maps, float xi, float yi)
{
	int	y;
	int	x;

	if (xi > WIDTH || yi > HEIGHT)
		return (1);
	xi = (xi / TILE_S3D);
	yi = (yi / TILE_S3D);
	x = abs((int)xi);
	y = abs((int)yi);
	if (y >= maps->map_size || x >= maps->len[y])
		return (1);
	if (maps->only_map[y])
	{
		if (maps->only_map[y][x])
		{
			if (maps->only_map[y][x] == '1' || maps->only_map[y][x] == ' ')
				return (1);
		}
		else
			return (1);
	}
	else
		return (1);
	return (0);
}
