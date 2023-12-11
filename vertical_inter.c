/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   horiverti_inter.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenmous <abenmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/23 16:03:56 by abenmous          #+#    #+#             */
/*   Updated: 2023/12/05 09:47:19 by abenmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

void	vetical_hit(t_cube *maps, float nextvertx, float nextverty)
{
	if (maps->fvertihit)
		maps->vertihit = distance_b(maps->px, maps->py, nextvertx, nextverty);
	else
		maps->vertihit = INT_MAX;
}

void	vertical_intersection2(t_cube *maps, float nextvertx, float nextverty)
{
	float	xcheck;
	float	ycheck;

	maps->fvertihit = false;
	while (nextvertx >= 0 && nextvertx <= WIDTH
		&& nextverty >= 0 && nextverty <= HEIGHT)
	{
		xcheck = nextvertx;
		ycheck = nextverty ;
		if (!maps->lr)
			xcheck -= 1;
		if (hitwall(maps, xcheck, ycheck))
		{
			maps->fvertihit = true;
			maps->wallvx = nextvertx;
			maps->wallvy = nextverty;
			break ;
		}
		else
		{
			nextvertx += maps->vertxstep;
			nextverty += maps->vertystep;
		}
	}
	vetical_hit(maps, nextvertx, nextverty);
}

void	vertical_intersection(t_cube *maps)
{
	float	nextvertx;
	float	nextverty;

	maps->updo = 0;
	maps->lr = 0;
	if (maps->ray_angle >= 0 && maps->ray_angle <= PI)
		maps->updo = 1;
	if (maps->ray_angle <= PI / 2 || maps->ray_angle >= PI * 1.5)
		maps->lr = 1;
	nextvertx = floor(maps->px / TILE_S3D) * TILE_S3D;
	if (maps->lr)
		nextvertx += TILE_S3D;
	nextverty = maps->py + (nextvertx - maps->px) * tan(maps->ray_angle);
	maps->vertxstep = TILE_S3D;
	if (!maps->lr)
		maps->vertxstep *= -1;
	maps->vertystep = TILE_S3D * tan(maps->ray_angle);
	if (!maps->updo && maps->vertystep > 0)
		maps->vertystep *= -1;
	if (maps->updo && maps->vertystep < 0)
		maps->vertystep *= -1;
	vertical_intersection2(maps, nextvertx, nextverty);
}
