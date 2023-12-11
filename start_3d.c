/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_3d.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenmous <abenmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/25 22:06:16 by abenmous          #+#    #+#             */
/*   Updated: 2023/12/05 09:29:58 by abenmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int32_t	getcolor(mlx_texture_t *img, int y, int x)
{
	int	inc;

	if (x >= 0 && x < (int)img->width && y >= 0 && y < (int)img->height)
	{
		inc = (img->width * y + x) * img->bytes_per_pixel;
		return (get_color(img->pixels[inc], img->pixels[inc + 1],
				img->pixels[inc + 2], 255));
	}
	return (get_color(0, 0, 0, 0));
}

void	calculs_3d(t_cube *maps, int i, mlx_texture_t **img)
{
	float		dist_top;
	uint32_t	color;
	float		yoff;
	float		xoff;
	float		fact;

	maps->ppl = (WIDTH / 2) / tan((FOV_ANGLE * (PI / 180)));
	maps->wallheight = (TILE_S3D / maps->distance[i]) * maps->ppl;
	maps->start = (HEIGHT / 2) - (maps->wallheight);
	if (maps->start < 0)
		maps->start = 0;
	maps->end = (HEIGHT / 2) + (maps->wallheight);
	if (maps->end > HEIGHT)
		maps->end = HEIGHT;
	fact = img[maps->sides[i]]->height / maps->wallheight;
	while (maps->start < maps->end)
	{
		dist_top = maps->start + (maps->wallheight) - (HEIGHT / 2);
		yoff = dist_top * fact / 2;
		xoff = ((int)maps->x_touch[i]) % (img[maps->sides[i]]->width);
		color = getcolor(img[maps->sides[i]], yoff, xoff);
		if (i >= 0 && i < WIDTH && maps->start >= 0 && maps->start < HEIGHT)
			mlx_put_pixel(maps->mlx_win, i, maps->start, color);
		maps->start++;
	}
}
