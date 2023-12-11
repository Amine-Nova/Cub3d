/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cub_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenmous <abenmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/07 13:08:02 by yberrim           #+#    #+#             */
/*   Updated: 2023/12/11 13:06:32 by abenmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_cub(char *str)
{
	int	i;

	i = 0;
	if (str)
	{
		while (str[i] && str[i] != '.')
			i++;
		if (str[i] && str[i] != '.')
			return (0);
		if (str[i + 1] != 'c')
			return (0);
		if (str[i + 2] != 'u')
			return (0);
		if (str[i + 3] != 'b')
			return (0);
		if (str[i + 4])
			return (0);
	}
	return (1);
}

void	*ft_calloc(size_t count, size_t size)
{
	void	*p;

	p = malloc(count * size);
	if (!p)
		return (NULL);
	ft_bzero(p, count * size);
	return (p);
}

void	fill_map(t_cube *win, int i, int j, int couleur)
{
	int	w;
	int	h;

	w = i * TILE_S;
	h = j * TILE_S;
	while (h <= j * TILE_S + TILE_S)
	{
		while (w <= i * TILE_S + TILE_S)
		{
			mlx_put_pixel(win->mlx_win, h, w, couleur);
			w++;
		}
		w = i * TILE_S;
		h++;
	}
}
