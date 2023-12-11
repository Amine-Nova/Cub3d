/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abenmous <abenmous@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 09:21:08 by abenmous          #+#    #+#             */
/*   Updated: 2023/12/06 16:42:52 by abenmous         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "cub3d.h"

int	check_double_nl(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '1')
			break ;
		i++;
	}
	while (str[i])
	{
		if (str[i] == '\n' && str[i + 1] == '\n')
			return (1);
		i++;
	}
	return (0);
}

void	free_all(t_cube *maps)
{
	free(maps->no);
	free(maps->so);
	free(maps->we);
	free(maps->ea);
	free(maps->f);
	free(maps->len);
	free(maps->c);
	free(maps->sides);
	ft_free(maps->only_map);
	ft_free(maps->textures);
}

void	set_null(t_cube *maps)
{
	maps->no = NULL;
	maps->so = NULL;
	maps->we = NULL;
	maps->ea = NULL;
	maps->f = NULL;
	maps->c = NULL;
}

void	ft_free(char **str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}

void	protect_image(t_cube *maps, mlx_texture_t **img)
{
	if (!img[0] || !img[1] || !img[2] || !img[3])
	{
		free_all(maps);
		ft_putstr_fd("Image Error\n", 2);
		exit (1);
	}
	check_image_wh(maps, img);
}
