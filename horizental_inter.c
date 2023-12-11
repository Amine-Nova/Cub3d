/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horizental_inter.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenmous <abenmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/05 09:46:49 by abenmous          #+#    #+#             */
/*   Updated: 2023/12/05 09:47:24 by abenmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	horizental_hit(t_cube *maps, float nextvertx, float nextverty)
{
	if (maps->fhorihit)
		maps->horizhit = distance_b(maps->px, maps->py, nextvertx, nextverty);
	else
		maps->horizhit = INT_MAX;
}

void	horizental_intersection2(t_cube *maps, float nexthorx, float nexthory)
{
	float	xcheck;
	float	ycheck;

	maps->fhorihit = false;
	while (nexthorx >= 0 && nexthorx <= WIDTH
		&& nexthory >= 0 && nexthory <= HEIGHT)
	{
		xcheck = nexthorx;
		ycheck = nexthory;
		if (!maps->updo)
			ycheck -= 1;
		if (hitwall(maps, xcheck, ycheck))
		{
			maps->fhorihit = true;
			maps->wallhx = nexthorx;
			maps->wallhy = nexthory;
			break ;
		}
		else
		{
			nexthorx += maps->horxstep;
			nexthory += maps->horystep;
		}
	}
	horizental_hit(maps, nexthorx, nexthory);
}

void	horizantal_intersection(t_cube *maps)
{
	float	nexthorx;
	float	nexthory;

	maps->updo = 0;
	maps->lr = 0;
	if (maps->ray_angle >= 0 && maps->ray_angle <= PI)
		maps->updo = 1;
	if (maps->ray_angle <= PI / 2 || maps->ray_angle >= PI * 1.5)
		maps->lr = 1;
	nexthory = floor(maps->py / TILE_S3D) * TILE_S3D;
	if (maps->updo)
		nexthory += TILE_S3D;
	nexthorx = maps->px + (nexthory - maps->py) / tan(maps->ray_angle);
	maps->horystep = TILE_S3D;
	if (!maps->updo)
		maps->horystep *= -1;
	maps->horxstep = TILE_S3D / tan(maps->ray_angle);
	if (!maps->lr && maps->horxstep > 0)
		maps->horxstep *= -1;
	if (maps->lr && maps->horxstep < 0)
		maps->horxstep *= -1;
	horizental_intersection2(maps, nexthorx, nexthory);
}
